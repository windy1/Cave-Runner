#include "Obstacle.h"

namespace game {

    const float Obstacle::SCROLL_VELOCITY = -1;

    Obstacle::Obstacle() {
        velocity.x = SCROLL_VELOCITY;
    }

    Obstacle::Obstacle(Vector2f pos) : Obstacle::Obstacle() {
        this->pos = pos;
    }

}
