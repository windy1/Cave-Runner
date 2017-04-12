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
        for (int i = 0; i < entities.size(); i++) {
            entities[i]->update();
        }

        // draw entities
        for (int i = 0; i < entities.size(); i++) {
            // TODO
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


//THIS WORKED
