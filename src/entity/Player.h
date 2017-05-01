#ifndef CS_120_FINAL_PROJECT_PLAYER_H
#define CS_120_FINAL_PROJECT_PLAYER_H

#include "../ptr.h"
#include "Entity.h"
#include "GrapplingHook.h"

namespace game {

    class Player : public Entity {

        hook_ptr grapplingHook;
        bool powerUp;
        float jumpVelocity;
        float gravity;
        float terminalVelocity;

    public:

        static const float      DEFAULT_JUMP_VELOCITY;
        static const float      DEFAULT_GRAVITY;
        static const float      DEFAULT_TERM_VELOCITY;
        static const Vector2i   DEFAULT_DIMENSIONS;
        static const float      X_POSITION;

        // constructors
        
        Player(hook_ptr grapplingHook);

        hook_ptr getGrapplingHook() const;

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

        float getJumpVelocity() const;

        void setJumpVelocity(float jumpVelocity);

        float getGravity() const;

        void setGravity(float gravity);

        float getTerminalVelocity() const;

        void setTerminalVelocity(float terminalVelocity);
        
        // get type
        virtual string getType() const override;

        /**
         * Requires: player is not jumping already
         * Modifies: player y position
         * Effects: player rises and falls to original position along y-axis
         */
        bool jump();

        bool isOnGround();

        /**
         * Requires: nothing
         * Modifies: player y position
         * Effects: moves player along y-axis by a given amount deltaY
         */
        void move(float deltaY);
        
        /*
        * Requires: nothing
        * Modifies: nothing
        * Effects: determines if player overlaps the given coordinates
        */
        virtual bool isOverlapping(float xIn, float yIn) const;

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

    };

}


#endif //CS_120_FINAL_PROJECT_PLAYER_H
