#include "PowerUp.h"

namespace game {
    
    PowerUp::PowerUp() : Collectible::Collectible() {
    }
    
    PowerUp::PowerUp(Vector2f pos) : Collectible::Collectible(pos){
    }
    
    void PowerUp::becomeCollected(Player &player) {
        dead = true;
        player.setPowerUp(true);
    }
    
    void PowerUp::draw() const {
        // TODO
    }

}
