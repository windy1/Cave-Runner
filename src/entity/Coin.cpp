#include "Coin.h"
#include "../graphics/graphics.h"
#include "../game.h"

namespace game {

    const int Coin::COIN_VALUE = 10;

    Coin::Coin() : Collectible::Collectible() {
    }
    
    Coin::Coin(Vector2f pos) : Collectible::Collectible(pos) {
    }

    void Coin::becomeCollected(Player &player) {
        dead = true;
        game::getGameState()->score.updateScore(COIN_VALUE);
    }

    void Coin::draw() const {
        graphics::drawCirc(dimensions, pos.round(), color);
    }

    string Coin::getType() const {
        return COIN;
    }

}
