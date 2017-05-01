#include "PowerUp.h"
#include "../graphics/graphics.h"

namespace game {
    
    PowerUp::PowerUp() : Collectible::Collectible() {
    }
    
    PowerUp::PowerUp(Vector3f pos) : Collectible::Collectible(pos) {
    }
    
    void PowerUp::becomeCollected(Player &player) {
        dead = true;
        player.setPowerUp(true);
    }

    string PowerUp::getType() const {
        return POWER_UP;
    }

    void PowerUp::draw() const {
        drawCircle(dimensions, Vector2f(pos).round(), color);
    }

}
