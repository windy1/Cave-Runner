#ifndef CS_120_FINAL_PROJECT_OBSTACLE_H
#define CS_120_FINAL_PROJECT_OBSTACLE_H

#include "Entity.h"

namespace game {

    class Obstacle : public Entity {
    public:

        static const float SCROLL_VELOCITY;

        Obstacle();

        Obstacle(Vector2f pos);

        virtual void update() override;

    };

}


#endif //CS_120_FINAL_PROJECT_OBSTACLE_H
