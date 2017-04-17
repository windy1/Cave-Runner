#ifndef CS_120_FINAL_PROJECT_COIN_H
#define CS_120_FINAL_PROJECT_COIN_H

#include "Collectible.h"

namespace game {

    class Coin : public Collectible {
    public:

        // coin value (score points)
        static const int COIN_VALUE;
        
        // default constructor
        Coin();
        
        // constructor with position parameter
        Coin(Vector2f pos);

        virtual string getType() const override;
        
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
