#ifndef CS_120_FINAL_PROJECT_COIN_H
#define CS_120_FINAL_PROJECT_COIN_H

#include "Collectible.h"
#include "../graphics/graphics.h"

namespace game {

    class Coin : public Collectible {
    public:

        // coin value (score points)
        static const int COIN_VALUE;
        
        // constructors
        
        Coin();

        // constructor with position parameter
        Coin(Vector3f pos);

        //get type
        virtual string getType() const override;
        
        /**
         * Requires: nothing
         * Modifies: coin and player score
         * Effects: coin disappears from screen and player's score is incremented
         */
        virtual void becomeCollected(Player &player) override;

        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects: draws coin as circle
         */
        virtual void draw() const override;

    };

}

#endif //CS_120_FINAL_PROJECT_COIN_H
