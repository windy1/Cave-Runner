#ifndef CS_120_FINAL_PROJECT_COIN_H
#define CS_120_FINAL_PROJECT_COIN_H

#include "Collectible.h"

namespace game {

    class Coin : public Collectible {
    public:
        
        //default constructor
        Coin();
        
        //constructor with position parameter
        Coin(Vector2f pos);
        
        //coin value (score points)
        static const float COIN_VALUE;
        
        /**
         * Requires: nothing
         * Modifies: coin and player score
         * Effects: coin disappears from screen and player's score is incremented
         */
        virtual void becomeCollected(Player &player) override;

        virtual void draw() const override;

    };

}

#endif //CS_120_FINAL_PROJECT_COIN_H
