#ifndef CS_120_FINAL_PROJECT_COLLECTIBLE_H
#define CS_120_FINAL_PROJECT_COLLECTIBLE_H

#include "../math.h"
#include "Entity.h"
#include "Player.h"

namespace game {

    class Collectible : public Entity {
    public:

        virtual void becomeCollected(Player player) = 0;

    };

}


#endif //CS_120_FINAL_PROJECT_COLLECTIBLE_H
