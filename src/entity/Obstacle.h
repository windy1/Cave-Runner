#ifndef CS_120_FINAL_PROJECT_OBSTACLE_H
#define CS_120_FINAL_PROJECT_OBSTACLE_H

#include "Entity.h"

namespace game {

    class Obstacle : public Entity {
    public:

        // constructors
        
        Obstacle();

        Obstacle(Vector3f pos);

    };

}


#endif //CS_120_FINAL_PROJECT_OBSTACLE_H
