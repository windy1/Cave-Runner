#include "Entity.h"

namespace game {

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns entity position as Point2D
     */
    Point2d Entity::getPosition() const {
        return pos;
    }
    
    /**
     * Requires: nothing
     * Modifies: pos
     * Effects: moves entity by given amounts along the x and y axes
     */
    void Entity::move(float deltaX, float deltaY) {
        pos.x += deltaX;
        pos.y += deltaY;
    }

}
