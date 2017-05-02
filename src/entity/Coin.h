#ifndef CS_120_FINAL_PROJECT_COIN_H
#define CS_120_FINAL_PROJECT_COIN_H

#include "Collectible.h"
#include "../graphics/graphics.h"

namespace game {

    /**
     * A collectible coin.
     */
    class Coin : public Collectible {
    public:

        /// Coin value (score points)
        static const int COIN_VALUE;

        Coin();

        Coin(Vector3f pos);
        
        /**
         * Requires: nothing
         * Modifies: coin and player score
         * Effects: coin disappears from screen and player's score is incremented
         */
        virtual void becomeCollected(Player &player) override;

        virtual string getType() const override;

        virtual void draw() const override;

    };

}

#endif //CS_120_FINAL_PROJECT_COIN_H
