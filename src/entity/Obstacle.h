#ifndef CS_120_FINAL_PROJECT_OBSTACLE_H
#define CS_120_FINAL_PROJECT_OBSTACLE_H

#include "Entity.h"

namespace game {

    class Obstacle : public Entity {
    public:

        Obstacle();

        Obstacle(Vector2f pos);

        static const float SCROLL_VELOCITY;

    };

}


#endif //CS_120_FINAL_PROJECT_OBSTACLE_H
