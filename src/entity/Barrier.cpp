#include "Barrier.h"
#include "../graphics/graphics.h"

namespace game {

    Barrier::Barrier() : Obstacle::Obstacle() {
    }

    Barrier::Barrier(Vector2f pos) : Obstacle::Obstacle(pos) {
    }

    string Barrier::getType() const {
        return BARRIER;
    }

    void Barrier::draw() const {
        graphics::drawRect(dimensions, pos.round(), color);
    }

}
