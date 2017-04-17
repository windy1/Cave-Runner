#ifndef CS_120_FINAL_PROJECT_COLLECTIBLE_H
#define CS_120_FINAL_PROJECT_COLLECTIBLE_H

#include "../math.h"
#include "Entity.h"
#include "Player.h"

namespace game {

    class Collectible : public Entity {
    public:
        
        //default constructor
        Collectible();
        
        //constructor with position parameter
        Collectible(Vector2f pos);
        
        static const float SCROLL_VELOCITY;
        
        /**
         * Requires: the collectible has not been collected already
         * Modifies: none
         * Effects: applies any effects this collectible has on the player - PURE VIRTUAL
         */
        virtual void becomeCollected(Player &player) = 0;

    };

}


#endif //CS_120_FINAL_PROJECT_COLLECTIBLE_H
