#include "Player.h"
#include "../graphics/graphics.h"
#include "../game.h"

using namespace std;

namespace game {

    const float     Player::DEFAULT_JUMP_VELOCITY   =   10;
    const float     Player::DEFAULT_GRAVITY         =   0.5;
    const float     Player::DEFAULT_TERM_VELOCITY   =   -100;
    const float     Player::X_POSITION      =   100;
    const Vector2i  Player::DEFAULT_DIMENSIONS          (50, 50);

    Player::Player(hook_ptr grapplingHook) {
        this->grapplingHook = grapplingHook;
        jumpVelocity = DEFAULT_JUMP_VELOCITY;
        gravity = DEFAULT_GRAVITY;
        terminalVelocity = DEFAULT_TERM_VELOCITY;
        color = Color::BLUE;
        dimensions = DEFAULT_DIMENSIONS;
        pos.x = X_POSITION;
        pos.y = getGroundY();
    }

    hook_ptr Player::getGrapplingHook() const {
        return grapplingHook;
    }
    
    bool Player::hasPowerUp() const {
        return powerUp;
    }
    
    void Player::setPowerUp(bool newPowerUp) {
        powerUp = newPowerUp;
    }

    float Player::getJumpVelocity() const {
        return jumpVelocity;
    }

    void Player::setJumpVelocity(float jumpVelocity) {
        this->jumpVelocity = jumpVelocity;
    }

    float Player::getGravity() const {
        return gravity;
    }

    void Player::setGravity(float gravity) {
        this->gravity = gravity;
    }

    float Player::getTerminalVelocity() const {
        return terminalVelocity;
    }

    void Player::setTerminalVelocity(float terminalVelocity) {
        this->terminalVelocity = terminalVelocity;
    }
    
    bool Player::jump() {
        if (isOnGround() && velocity.y == 0) {
            // start jumping
            velocity.y = jumpVelocity;
            return true;
        }
        return false;
    }

    bool Player::isOnGround() {
        return pos.y == getGroundY();
    }

    void Player::move(float deltaY) {
        Entity::move(0, deltaY);
    }

    void Player::update() {
        Entity::update();

        // handle gravity
        int groundY = getGroundY();
        if (pos.y > groundY && velocity.y > terminalVelocity && !grapplingHook->isHooked()) {
            // apply gravity
            velocity.y = max(velocity.y - gravity, terminalVelocity);
        } else if (pos.y <= groundY) {
            // hit ground
            pos.y = groundY;
            velocity.y = 0;
        }

        if (pos.x <= 0 || pos.x >= getWindowDimensions().x - dimensions.x) {
            velocity = velocity * Vector3f(-1, -1, 0);
        }

        // handle hook
        if (grapplingHook->isHooked()) {
            Vector3f hookPos = grapplingHook->getPosition();
            if (Vector2f::distance(Vector2f(hookPos), Vector2f(pos)) < 20 || pos.y + dimensions.y >= getCeilingY()) {
                grapplingHook->setHooked(false);
            } else {
                velocity.y = (hookPos.y - pos.y) * 0.05f;
                velocity.x = (hookPos.x - pos.x) * 0.05f;
            }
        }
    }

    string Player::getType() const {
        return PLAYER;
    }

    void Player::draw() const {
        drawRect(dimensions, Vector2f(pos).round(), color);
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
