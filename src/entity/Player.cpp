#include "Player.h"

namespace game {

    /**
     * Requires: player is not jumping already
     * Modifies: player y position
     * Effects: player rises and falls to original position along y-axis
     */
    void Player::jump() {
        // TODO
    }

    /**
     * Requires: nothing
     * Modifies: player y position
     * Effects: moves player along y-axis by a given amount deltaY
     */
    void Player::move(float deltaY) {
        Entity::move(0, deltaY);
    }

}
