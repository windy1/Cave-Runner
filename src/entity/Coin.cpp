#include "Coin.h"
#include "../graphics/graphics.h"
#include "../game.h"

namespace game {

    const int Coin::COIN_VALUE = 10;

    Coin::Coin() : Collectible::Collectible() {
    }
    
    Coin::Coin(Vector3f pos) : Collectible::Collectible(pos) {
    }

    void Coin::becomeCollected(Player &player) {
        dead = true;
        getGameState()->score->updateScore(COIN_VALUE);
    }

    string Coin::getType() const {
        return COIN;
    }

    void Coin::draw() const {
        drawCircle(dimensions, Vector2f(pos).round(), color);
    }

}
