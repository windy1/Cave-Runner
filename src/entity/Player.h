#ifndef CS_120_FINAL_PROJECT_PLAYER_H
#define CS_120_FINAL_PROJECT_PLAYER_H

#include "Entity.h"

namespace game {

    class Player : public Entity {

        float velocityY;

    public:

        /**
         * Requires: player is not jumping already
         * Modifies: player y position
         * Effects: player rises and falls to original position along y-axis
         */
        void jump();

        /**
         * Requires: nothing
         * Modifies: player y position
         * Effects: moves player along y-axis by a given amount deltaY
         */
        void move(float deltaY);

        virtual void draw() const override;

    };

}


#endif //CS_120_FINAL_PROJECT_PLAYER_H
