#include "graphics/graphics.h"
#include "game.h"

bool running = true;

int main() {
    graphics::init();
    while (running) {
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
