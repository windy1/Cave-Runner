#include "PowerUp.h"
#include "../graphics/graphics.h"

namespace game {
    
    PowerUp::PowerUp(player_ptr player) : Collectible::Collectible(player) {
    }
    
    PowerUp::PowerUp(player_ptr player, Vector3f pos) : Collectible::Collectible(player, pos) {
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
