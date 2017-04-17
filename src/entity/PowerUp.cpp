#include "PowerUp.h"

namespace game {
    
    PowerUp::PowerUp() : Collectible::Collectible() {
    }
    
    PowerUp::PowerUp(Vector2f pos) : Collectible::Collectible(pos) {
    }
    
    void PowerUp::becomeCollected(Player &player) {
        dead = true;
        player.setPowerUp(true);
    }

    string PowerUp::getType() const {
        return POWER_UP;
    }

    void PowerUp::draw() const {
        // TODO
    }

}
