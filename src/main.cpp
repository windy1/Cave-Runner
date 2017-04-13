#include "graphics/graphics.h"
#include "game.h"
#include "tests.h"
#include <iostream>

using namespace std;

bool running = true;
player_ptr player;
vector<entity_ptr> entities;

int main(int argc, char **argv) {
    if (argc > 1 && strcmp(*argv, "--tests")) {
        return game::runTests();
    }
    cout << "Starting..." << endl;
    player = make_shared<game::Player>();
    entities.push_back(player);
    graphics::init();
    while (running) {
        game::updateEntities(entities);
        game::drawEntities(entities);
        graphics::display();
    }
    return 0;
}

namespace game {

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
        return player;
    }

    bool isRunning() {
        return running;
    }

    void setRunning(bool r) {
        running = r;
    }

}
