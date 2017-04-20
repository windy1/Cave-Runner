#include "graphics/graphics.h"
#include "game.h"
#include "tests.h"
#include "loader.h"

using namespace std;

GameState gameState;

int main(int argc, char **argv) {
    if (argc > 1 && strcmp(*argv, "--tests")) {
        return game::runTests();
    }
    cout << "Starting..." << endl;
    gameState.player = make_shared<game::Player>();
    gameState.entities.push_back(gameState.player);
    gameState.globalX = 500;
    gameState.scrollSpeed = 1;
    gameState.level = 1;
    game::loadLevel(1, gameState);
    for (int i = 0; i < gameState.entities.size(); i++) {
        cout << *gameState.entities[i] << endl;
    }
    graphics::init(argc, argv);
    return 0;
}

namespace game {

    void update() {
        gameState.globalX += gameState.scrollSpeed;
        //cout << "gx = " << gameState.globalX << endl;
        updateEntities(gameState.entities);
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

    player_ptr getPlayer() {
        return gameState.player;
    }

    GameState* getGameState() {
        return &gameState;
    }

    void setGameState(GameState gs) {
        gameState = gs;
    }

}
