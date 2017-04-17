#include "Entity.h"

namespace game {

    Vector2f Entity::getPosition() const {
        return pos;
    }

    void Entity::setPosition(Vector2f pos) {
        this->pos = pos;
    }

    Vector2f Entity::getVelocity() const {
        return velocity;
    }

    void Entity::setVelocity(Vector2f velocity) {
        this->velocity = velocity;
    }

    bool Entity::isDead() const {
        return dead;
    }

    void Entity::setDead(bool dead) {
        this->dead = dead;
    }

    void Entity::move(float deltaX, float deltaY) {
        pos.x += deltaX;
        pos.y += deltaY;
    }

    void Entity::update() {
        move(velocity.x, velocity.y);
        if (pos.x < 0) {
            // remove once off screen
            dead = true;
        }
    }

}
