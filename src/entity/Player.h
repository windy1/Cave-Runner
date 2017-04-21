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

        // constructors
        
        Player();

        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects: checks if player has access to powerup
         */
        bool hasPowerUp() const;
        
        /**
         * Requires: nothing
         * Modifies: player's powerup access status
         * Effects: sets player's powerup status
         */
        void setPowerUp(bool newPowerUp);
        
        // get type
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

        /**
         * Requires: nothing
         * Modifies: player y velocity, sometimes player y position
         * Effects: applies gravity to player movement
         */
        virtual void update() override;

        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects: draws player as rectangle
         */
        virtual void draw() const override;
        
        /*
        * Requires: nothing
        * Modifies: nothing
        * Effects: determines if player overlaps the given coordinates
        */
        virtual bool isOverlapping(float xIn, float yIn) const;

    };

}


#endif //CS_120_FINAL_PROJECT_PLAYER_H
