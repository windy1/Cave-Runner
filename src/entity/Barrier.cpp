#include "Barrier.h"

namespace game {

    Barrier::Barrier() : Obstacle::Obstacle() {
    }

    Barrier::Barrier(Vector2f pos) : Obstacle::Obstacle(pos) {
    }

    void Barrier::draw() const {
        // TODO
    }

    string Barrier::getType() const {
        return BARRIER;
    }

}
