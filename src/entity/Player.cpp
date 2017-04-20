#include "Player.h"
#include "../graphics/graphics.h"

using namespace std;

namespace game {

    const float     Player::JUMP_VELOCITY   =   10;
    const float     Player::GRAVITY         =   0.5;
    const float     Player::TERM_VELOCITY   =   -100;
    const float     Player::X_POSITION      =   100;
    const Vector2i  Player::DIMENSIONS          (50, 50);

    Player::Player() {
        color = Color::BLUE;
        dimensions = DIMENSIONS;
        pos.x = X_POSITION;
        pos.y = 500; // TODO: remove this, only here to test falling
    }
    
    bool Player::hasPowerUp() const {
        return powerUp;
    }
    
    void Player::setPowerUp(bool newPowerUp) {
        powerUp = newPowerUp;
    }
    
    bool Player::jump() {
        if (pos.y == 0 && velocity.y == 0) {
            // start jumping
            velocity.y = JUMP_VELOCITY;
            return true;
        }
        return false;
    }

    void Player::move(float deltaY) {
        Entity::move(0, deltaY);
    }

    void Player::update() {
        Entity::update();
        if (pos.y > 0 && velocity.y > TERM_VELOCITY) {
            // apply gravity
            velocity.y = max(velocity.y - GRAVITY, TERM_VELOCITY);
        } else if (pos.y <= 0) {
            // hit ground
            pos.y = 0;
            velocity.y = 0;
        }
    }

    string Player::getType() const {
        return PLAYER;
    }

    void Player::draw() const {
        graphics::drawRect(dimensions, pos.round(), color);
    }
    
    bool Player::isOverlapping(float xIn, float yIn) const {
        //getPosition returns bottom left point of player
        if (xIn < getPosition().x) {
            // out of bounds to the left of the rectangle
            return false;
        }
        if (xIn > getPosition().x + getDimensions().x) {
            // out of bounds to the right of the rectangle
            return false;
        }
        if (yIn < getPosition().y - getDimensions().y) {
            // out of bounds above the rectangle
            return false;
        }
        if (yIn > getPosition().y) {
            // out of bounds below the rectangle
            return false;
        }
        return true;
    }

}
