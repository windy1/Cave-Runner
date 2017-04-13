#include "graphics/graphics.h"
#include "game.h"
#include <vector>

using namespace std;

bool running = true;
player_ptr player;
vector<entity_ptr> entities;

int main() {
    player = make_shared<game::Player>();
    entities.push_back(player);
    graphics::init();
    while (running) {
        // update entities
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
        // draw entities
        for (int i = 0; i < entities.size(); i++) {
            entities[i]->draw();
        }
        graphics::display();
    }
    return 0;
}

bool game::isRunning() {
    return running;
}

void game::setRunning(bool r) {
    running = r;
}
