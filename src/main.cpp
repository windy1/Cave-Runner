#include "game.h"
#include "tests.h"
#include "loader.h"

game::GameState gameState;
bool paused = false;

int main(int argc, char **argv) {
    if (argc > 1 && strcmp(*argv, "--tests")) {
        return game::runTests();
    }

    cout << "Starting..." << endl;

    gameState.globalX = 500;
    gameState.scrollSpeed = 3;
    gameState.level = 1;

    game::loadLevel(1, gameState);

    gameState.player = make_shared<game::Player>();
    game::hook_ptr grapplingHook = make_shared<game::GrapplingHook>(gameState.player);
    gameState.player->setGrapplingHook(grapplingHook);

    insertEntity(grapplingHook, gameState.entities);
    insertEntity(gameState.player, gameState.entities);

    game::initGraphics(argc, argv);

    return 0;
}

namespace game {

    void update() {
        gameState.globalX += gameState.scrollSpeed;
        if (gameState.globalX % 300 == 0) {
            insertEntity(make_shared<Torch>(), gameState.entities);
        }
        updateEntities(gameState.entities);
    }

    void draw() {
        drawEntities(gameState.entities);
    }

    void updateEntities(vector<entity_ptr> &entities) {
        vector<entity_ptr>::iterator iter = entities.begin();
        while (iter != entities.end()) {
            entity_ptr entity = *iter;
            if (entity->isDead()) {
                // remove entity from vector
                iter = entities.erase(iter);
            } else {
                // update and continue
                entity->update();
                iter++;
            }
        }
    }

    void drawEntities(const vector<entity_ptr> &entities) {
        for (int i = 0; i < entities.size(); i++) {
            entities[i]->draw();
        }
    }

    void insertEntity(entity_ptr entity, vector<entity_ptr> &entities) {
        assert(entity != NULL);
        if (entities.empty()) {
            entities.push_back(entity);
            return;
        }

        vector<entity_ptr>::iterator iter = entities.begin();
        bool inserted = false;
        while (iter != entities.end()) {
            entity_ptr en = *iter;
            if (entity->getPosition().z < en->getPosition().z) {
                entities.insert(iter, entity);
                inserted = true;
                break;
            }
            iter++;
        }

        if (!inserted) {
            entities.push_back(entity);
        }
    }

    player_ptr getPlayer() {
        return gameState.player;
    }

    GameState* getGameState() {
        return &gameState;
    }

    bool isPaused() {
        return paused;
    }

    void setPaused(bool p) {
        paused = p;
    }

    int getGroundY() {
        return 50;
    }

    int getCeilingY() {
        return getWindowDimensions().y - getGroundY();
    }

    void setGameState(GameState gs) {
        gameState = gs;
    }

}
