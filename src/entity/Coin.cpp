#include "Coin.h"

namespace game {

    Coin::Coin() : Collectible::Collectible() {
    }
    
    Coin::Coin(Vector2f pos) : Collectible::Collectible(pos){
    }
    
    const float Coin::COIN_VALUE = 10;
    
    void Coin::becomeCollected(Player &player) {
        dead = true;
        player.updatePlayerScore(COIN_VALUE);
    }

    void Coin::draw() const {
        // TODO
    }

}
