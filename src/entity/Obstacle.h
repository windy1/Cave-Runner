#ifndef CS_120_FINAL_PROJECT_OBSTACLE_H
#define CS_120_FINAL_PROJECT_OBSTACLE_H

#include "Entity.h"

namespace game {

    class Obstacle : public Entity {
    public:

        //scroll velocity - velocity at which entities move horizontally, towards player
        static const float SCROLL_VELOCITY;

        // constructors
        
        Obstacle();

        Obstacle(Vector2f pos);

    };

}


#endif //CS_120_FINAL_PROJECT_OBSTACLE_H
