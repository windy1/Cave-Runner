#ifndef CS_120_FINAL_PROJECT_PLAYER_H
#define CS_120_FINAL_PROJECT_PLAYER_H

#include "Entity.h"
#include "Score.h"
#include "../graphics/Color.h"

namespace game {

    class Player : public Entity {

        bool powerUp;

    public:

        static const float      JUMP_VELOCITY;
        static const float      GRAVITY;
        static const float      TERM_VELOCITY;
        static const float      X_POSITION;
        static const Vector2i   DIMENSIONS;

        Player();

        bool hasPowerUp() const;
        
        void setPowerUp(bool newPowerUp);
        
        virtual string getType() const override;

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
