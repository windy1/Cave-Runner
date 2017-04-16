#ifndef CS_120_FINAL_PROJECT_PLAYER_H
#define CS_120_FINAL_PROJECT_PLAYER_H

#include "Entity.h"

namespace game {

    class Player : public Entity {
    public:

        static const float JUMP_VELOCITY;
        static const float GRAVITY;
        static const float TERM_VELOCITY;

        /**
         * Requires: player is not jumping already
         * Modifies: player y position
         * Effects: player rises and falls to original position along y-axis
         */
        bool jump();

        /**
         * Requires: nothing
         * Modifies: player y position
         * Effects: moves player along y-axis by a given amount deltaY
         */
        void move(float deltaY);

        virtual void update() override;

        virtual void draw() const override;

    };

}


#endif //CS_120_FINAL_PROJECT_PLAYER_H
