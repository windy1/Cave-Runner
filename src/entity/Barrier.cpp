#include "Barrier.h"
#include "../game.h"

namespace game {

    Barrier::Barrier() : Obstacle::Obstacle() {
    }

    Barrier::Barrier(Vector3f pos) : Obstacle::Obstacle(pos) {
    }

    bool Barrier::isOverlapping(float xIn, float yIn) const {
        return (xIn >= pos.x && xIn <= pos.x + dimensions.x) && (yIn >= pos.y && yIn <= pos.y + dimensions.y);
    }
    
    bool Barrier::isOverlapping(Vector2i point) const {
        return isOverlapping(point.x, point.y);
    }
    
    bool Barrier::isOverlapping(const Player &player) const {
        Vector2i playerPos = Vector2f(player.getPosition()).round();
        Vector2i playerDim = player.getDimensions();
        bool bottomLeft = isOverlapping(playerPos);
        bool topLeft = isOverlapping(playerPos + Vector2i(0, playerDim.y));
        bool topRight = isOverlapping(playerPos + playerDim);
        bool bottomRight = isOverlapping(playerPos + Vector2i(playerDim.x, 0));
        return bottomLeft || topLeft || topRight || bottomRight;
    }

    string Barrier::getType() const {
        return BARRIER;
    }

    void Barrier::update() {
        Entity::update();
        player_ptr player = getPlayer();
        if (isOverlapping(*player)) {
            player->setDead(true);
        }
    }

    void Barrier::draw() const {
        drawRect(dimensions, Vector2f(pos).round(), color);
    }

}
