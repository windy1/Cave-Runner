#ifndef CS_120_FINAL_PROJECT_COIN_H
#define CS_120_FINAL_PROJECT_COIN_H

#include "Collectible.h"

namespace game {

    class Coin : public Collectible {
    public:

        virtual void becomeCollected(Player &player) override;

        virtual void draw() const override;

    };

}

#endif //CS_120_FINAL_PROJECT_COIN_H
