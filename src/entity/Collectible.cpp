#include "Collectible.h"

namespace game {
    
    const float Collectible::SCROLL_VELOCITY = -1;
    
    Collectible::Collectible() {
        velocity.x = SCROLL_VELOCITY;
    }
    
    Collectible::Collectible(Vector2f pos) : Collectible::Collectible() {
        this->pos = pos;
    }
    
}
