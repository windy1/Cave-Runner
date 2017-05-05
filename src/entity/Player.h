#ifndef CS_120_FINAL_PROJECT_PLAYER_H
#define CS_120_FINAL_PROJECT_PLAYER_H

#include "../ptr.h"
#include "Entity.h"
#include "GrapplingHook.h"

namespace game {

    /**
     * The player of the game.
     */
    class Player : public Entity {

        hook_ptr grapplingHook;
        bool powerUp;
        bool powered;
        float jumpVelocity;
        float gravity;
        float terminalVelocity;
        float groundFriction;

    public:

        /// Defaults
        static const float      DEFAULT_JUMP_VELOCITY;
        static const float      DEFAULT_GRAVITY;
        static const float      DEFAULT_TERM_VELOCITY;
        static const float      DEFAULT_GROUND_FRICTION;
        static const Vector2i   DEFAULT_DIMENSIONS;
        static const float      STARTING_X_POSITION;

        Player();

        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects: returns a pointer to this player's grappling hook
         */
        hook_ptr getGrapplingHook() const;

        /**
         * Requires: a valid hook_ptr
         * Modifies: player grappling hook
         * Effects: sets the player's grappling hook
         */
        void setGrapplingHook(hook_ptr grapplingHook);

        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects: checks if player has access to powerup
         */
        bool hasPowerUp() const;
        
        /**
         * Requires: nothing
         * Modifies: player's powerup access status
         * Effects: sets player's powerup inventory status
         */
        void setPowerUp(bool newPowerUp);
        
        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects: checks if player is currently executing powerup
         */
        bool isPowered() const;
        
        /**
         * Requires: nothing
         * Modifies: player's powerup execution status
         * Effects: sets player's powerup execution status
         */
        void setPowered(bool newPoweredStatus);

        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects: returns the initial y-velocity of the player when they jump
         */
        float getJumpVelocity() const;

        /**
         * Requires: nothing
         * Modifies: player jump velocity
         * Effects: sets the initial y-velocity of the player when they jump
         */
        void setJumpVelocity(float jumpVelocity);

        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects: returns the amount of negative velocity exerted on the
         * player while in the air
         */
        float getGravity() const;

        /**
         * Requires: nothing
         * Modifies: player gravity
         * Effects: sets the amount of negative velocity exerted on the player
         * while in the air
         */
        void setGravity(float gravity);

        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects: returns the maximum negative velocity of the player
         */
        float getTerminalVelocity() const;

        /**
         * Requires: nothing
         * Modifies: player terminal velocity
         * Effects: sets the maximum negative velocity of the player
         */
        void setTerminalVelocity(float terminalVelocity);

        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects: returns the amount of x-velocity exerted on the player
         * towards zero while the player is on the ground and has a non-zero
         * x-velocity
         */
        float getGroundFriction() const;

        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects; sets the amount of x-velocity exerted on the player towards
         * zero while the player is on the ground and has a non-zero x-velocity
         */
        void setGroundFriction(float groundFriction);
        
        // get type
        virtual string getType() const override;

        /**
         * Requires: player is not jumping already
         * Modifies: player y position
         * Effects: player rises and falls to original position along y-axis
         */
        bool jump();

        /**
         * Requires: none
         * Modifies: none
         * Effects: returns true if the player is on the ground
         */
        bool isOnGround() const;
        
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
