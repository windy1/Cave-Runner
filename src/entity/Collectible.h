#ifndef CS_120_FINAL_PROJECT_COLLECTIBLE_H
#define CS_120_FINAL_PROJECT_COLLECTIBLE_H

#include "../math.h"
#include "Entity.h"
#include "Player.h"

namespace game {

    class Collectible : public Entity {
    public:

        //scroll velocity - velocity at which entities move horizontally, towards player
        static const float SCROLL_VELOCITY;

        // constructors
        
        Collectible();

        // constructor with position parameter
        Collectible(Vector3f pos);

        /**
         * Requires: the collectible has not been collected already
         * Modifies: none
         * Effects: applies any effects this collectible has on the player - PURE VIRTUAL
         */
        virtual void becomeCollected(Player &player) = 0;
        
        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects: determines if collectible overlaps the given coordinates
         */
        virtual bool isOverlapping(int xIn, int yIn) const;
        
        /**
         * Requires: line segment described by coordinates is vertical or horizontal
         * Modifies: nothing
         * Effects: determines if collectible overlaps the given line segment
         */
        virtual bool isOverlapping(int x1, int y1, int x2, int y2) const;
        
        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects: determines if collectible overlaps the player
         */
        virtual bool isOverlapping(const Player &player) const;
    };

}


#endif //CS_120_FINAL_PROJECT_COLLECTIBLE_H
