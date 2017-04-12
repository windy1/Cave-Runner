#include "Entity.h"

namespace game {

    Vector2i Entity::getPosition() const {
        return pos;
    }

    Vector2i Entity::getVelocity() const {
        return velocity;
    }

    void Entity::move(float deltaX, float deltaY) {
        pos.x += deltaX;
        pos.y += deltaY;
    }

    void Entity::update() {
        move(velocity.x, velocity.y);
    }

}
