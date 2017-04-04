#ifndef CS_120_FINAL_PROJECT_POWERUP_H
#define CS_120_FINAL_PROJECT_POWERUP_H

#include "Collectible.h"

namespace game {

    class PowerUp : public Collectible {
    public:

        virtual void becomeCollected(Player player);

    };

}

#endif //CS_120_FINAL_PROJECT_POWERUP_H
