#ifndef CS_120_FINAL_PROJECT_PLAYER_H
#define CS_120_FINAL_PROJECT_PLAYER_H

#include "Entity.h"
#include "Score.h"

namespace game {

    class Player : public Entity {

        Score playerScore;
        bool powerUp;
        Vector2i dimensions = Vector2i(50, 50);

    public:

        static const float JUMP_VELOCITY;
        static const float GRAVITY;
        static const float TERM_VELOCITY;
        static const float X_POSITION;

        Player();

        Score getPlayerScore() const;

        bool hasPowerUp() const;
        
        void setPowerUp(bool newPowerUp);
        
        void updatePlayerScore(int newPlayerPoints);

        Vector2i getDimensions() const;

        void setDimensions(Vector2i dimensions);
        
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
