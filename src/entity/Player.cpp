#include "Player.h"

using namespace std;

namespace game {

    const float Player::JUMP_VELOCITY = 1;
    const float Player::GRAVITY = 0.1;
    const float Player::TERM_VELOCITY = -1;

    Score Player::getPlayerScore() const {
        return playerScore;
    }
    
    bool Player::hasPowerUp() const {
        return powerUp;
    }
    
    void Player::setPowerUp(bool newPowerUp) {
        powerUp = newPowerUp;
    }
    
    void Player::updatePlayerScore(int newPlayerPoints) {
        playerScore.updateScore(newPlayerPoints);
    }
    
    bool Player::jump() {
        // TODO: y == 0 -> bottom?
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

    void Player::draw() const {
        // TODO
    }

}
