#include "Entity.h"
#include <cassert>

namespace game {

    const string Entity::BARRIER        = "barrier";
    const string Entity::COIN           = "coin";
    const string Entity::GRAPPLING_HOOK = "grapplingHook";
    const string Entity::PLAYER         = "player";
    const string Entity::POWER_UP       = "powerUp";
    const string Entity::SCORE          = "score";
    const string Entity::TORCH          = "torch";

    Vector3f Entity::getPosition() const {
        return pos;
    }

    void Entity::setPosition(Vector3f pos) {
        this->pos = pos;
    }

    Vector2f Entity::getVelocity() const {
        return velocity;
    }

    void Entity::setVelocity(Vector2f velocity) {
        this->velocity = velocity;
    }

    Vector2i Entity::getDimensions() const {
        return dimensions;
    }

    void Entity::setDimensions(Vector2i dimensions) {
        assert(dimensions.x >= 0 && dimensions.y >= 0);
        this->dimensions = dimensions;
    }

    Color Entity::getColor() const {
        return color;
    }

    void Entity::setColor(Color color) {
        this->color = color;
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
        if (pos.x < -dimensions.x) {
            // remove once off screen
            dead = true;
        }
    }

    ostream& operator<<(ostream &stream, const Entity &entity) {
        stream << "Entity(";
        stream << "type=" << entity.getType() << ", ";
        stream << "pos=" << entity.getPosition() << ", ";
        stream << "velocity=" << entity.getVelocity() << ", ";
        stream << "dimensions=" << entity.getDimensions() << ", ";
        stream << "dead=" << entity.isDead() << ")";
        return stream;
    }

}
