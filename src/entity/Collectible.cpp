#include "Collectible.h"
#include "../game.h"

namespace game {

    Collectible::Collectible() {
        velocity.x = -game::getGameState()->scrollSpeed;
    }
    
    Collectible::Collectible(Vector2f pos) : Collectible::Collectible() {
        this->pos = pos;
    }
    
}
