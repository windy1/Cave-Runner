#ifndef CS_120_FINAL_PROJECT_PLAYER_H
#define CS_120_FINAL_PROJECT_PLAYER_H

#include "Entity.h"

namespace game {

    class Player : public Entity {

        float velocityY;

    public:

        void jump();

        void move(float deltaY);

    };

}


#endif //CS_120_FINAL_PROJECT_PLAYER_H
