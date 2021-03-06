#include "game.h"
#include "tests.h"
#include "io/GameStateReader.h"
#include "io/GameStateWriter.h"
#include "entity/Checkpoint.h"

using namespace game;

game::GameState gameState;
bool paused = false;

int main(int argc, char **argv) {
    if (argc > 1 && strcmp(*argv, "--tests")) {
        return runTests();
    }

    cout << "Starting..." << endl;

    initGraphics(argc, argv);

    return 0;
}

namespace game {

    void startLevel(int level) {
        gameState = {};
        createPlayer();
        loadLevel(level);
        setCurrentPage(gameplay);
    }

    void saveGame() {
        if (gameState.checkpoint != NULL) {
            // remove old checkpoint, if any
            gameState.checkpoint->setDead(true);
        }
        Vector3f checkpointPos =  gameState.player->getPosition() - Vector3f(0, 0, 1);
        gameState.checkpoint = make_shared<Checkpoint>(checkpointPos);
        insertEntity(gameState.checkpoint, gameState.entities);

        // write game state
        GameStateWriter writer(*getGameState());
        if (!writer.write("save.grs")) {
            cerr << "Could not save game state" << endl;
        }
    }

    void resumeGame() {
        gameState = {};
        createPlayer();
        GameStateReader reader(*getGameState());
        if (!reader.read("save.grs")) {
            cerr << "Could not read game state" << endl;
        }
        setCurrentPage(gameplay);
    }

    void loadLevel(int level) {
        GameStateReader reader(gameState);
        reader.setEntityYOffset(getGroundY());
        if (!reader.read("level_" + to_string(level) + ".grs")) {
            cerr << "Could not load level: " << level << endl;
        }
    }

    void createPlayer() {
        gameState.player = make_shared<game::Player>();
        game::hook_ptr grapplingHook = make_shared<game::GrapplingHook>(gameState.player);
        gameState.player->setGrapplingHook(grapplingHook);
        insertEntity(grapplingHook, gameState.entities);
        insertEntity(gameState.player, gameState.entities);
    }

    void update() {
        gameState.globalX += gameState.scrollSpeed;
        if (gameState.globalX % 300 == 0) {
            insertEntity(make_shared<Torch>(), gameState.entities);
        }
        if (gameState.globalX >= gameState.endX) {
            setCurrentPage(gameover);
            return;
        }
        updateEntities(gameState.entities);
        if (gameState.player->isDead()) {
            // game over
            setCurrentPage(gameover);
        }
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
    
    float getScrollSpeed() {
        return gameState.scrollSpeed;
    }

    int getTotalLevels() {
        return 3;
    }
    
    void setScrollSpeed(float newScrollSpeed) {
        gameState.scrollSpeed = newScrollSpeed;
        for (int i = 0; i < gameState.entities.size(); i++) {
            entity_ptr entity = gameState.entities[i];
            entity->setVelocity(Vector2f(-gameState.scrollSpeed, 0));
        }
    }

    page getCurrentPage() {
        return gameState.currentPage;
    }

    void setCurrentPage(page newPage) {
        gameState.currentPage = newPage;
    }

    void setGameState(GameState gs) {
        gameState = gs;
    }

}
