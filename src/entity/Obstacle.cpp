#include "Obstacle.h"
#include "../game.h"

namespace game {

    Obstacle::Obstacle() {
        velocity.x = -game::getGameState()->scrollSpeed;
    }

    Obstacle::Obstacle(Vector3f pos) : Obstacle::Obstacle() {
        this->pos = pos;
    }

}
