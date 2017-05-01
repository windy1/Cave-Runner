#include "Collectible.h"
#include "../game.h"
#include "Coin.h"

namespace game {

    Collectible::Collectible() {
        velocity.x = -getGameState()->scrollSpeed;
    }
    
    Collectible::Collectible(Vector3f pos) : Collectible::Collectible() {
        this->pos = pos;
    }
    
    bool Collectible::isOverlapping(int xIn, int yIn) const {
        double distanceBetweenCenterAndPoint = Vector2f::distance(getPosition(), Vector2f(xIn, yIn));
        return distanceBetweenCenterAndPoint <= getDimensions().x;
    }
    
    bool Collectible::isOverlapping(int x1, int y1, int x2, int y2) const {
        // vertical line segment
        if (x1 == x2 &&
            // x is in collectible's x-range
            (x1 >= getPosition().x - getDimensions().x) && (x1 <= getPosition().x + getDimensions().x) &&
            // center of collectible is in between y1 and y2
            ((getPosition().y > y1) == (getPosition().y < y2))) {
            return true;
        }
        // horizontal line segment
        if (y1 == y2 &&
            // y is in collectible's y-range
            (y1 >= getPosition().y - getDimensions().x) && (y1 <= getPosition().y + getDimensions().x) &&
            // center of collectible is in between x1 and x2
            ((getPosition().x > x1) == (getPosition().x < x2))) {
            return true;
        }
        return false;
    }
    
    bool Collectible::isOverlapping(const Player &player) const {
        // center of collectibe is inside player
        if (player.isOverlapping(getPosition().x, getPosition().y)) {
            return true;
        }
        // player corner is inside collectible
            // bottom-left
        if (isOverlapping(player.getPosition().x, player.getPosition().y) ||
            // bottom-right
            isOverlapping(player.getPosition().x + player.getDimensions().x, player.getPosition().y) ||
            // top-right
            isOverlapping(player.getPosition().x + player.getDimensions().x, player.getPosition().y - player.getDimensions().y) ||
            // top-left
            isOverlapping(player.getPosition().x, player.getPosition().y - player.getDimensions().y)) {
            return true;
        }
        // edge of player intersects the collectible
            // bottom
        if (isOverlapping(player.getPosition().x, player.getPosition().y, player.getPosition().x + player.getDimensions().x, player.getPosition().y) ||
            // left
            isOverlapping(player.getPosition().x, player.getPosition().y, player.getPosition().x, player.getPosition().y - player.getDimensions().y) ||
            // right
            isOverlapping(player.getPosition().x + player.getDimensions().x, player.getPosition().y, player.getPosition().x + player.getDimensions().x, player.getPosition().y - player.getDimensions().y) ||
            // top
            isOverlapping(player.getPosition().x, player.getPosition().y - player.getDimensions().y, player.getPosition().x + player.getDimensions().x, player.getPosition().y - player.getDimensions().y)) {
            return true;
        }
        return false;
    }
}
