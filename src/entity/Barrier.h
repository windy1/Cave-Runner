#ifndef CS_120_FINAL_PROJECT_BARRIER_H
#define CS_120_FINAL_PROJECT_BARRIER_H

#include "Obstacle.h"
#include "../graphics/graphics.h"
#include "Player.h"

namespace game {

    class Barrier : public Obstacle {
    public:
        
        //constructors
        
        Barrier();

        Barrier(Vector2f pos);

        // get type
        virtual string getType() const override;

        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects: draws barrier as rectangle
         */
        virtual void draw() const override;
        
        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects: determines if barrier overlaps the given coordinates
         */
        virtual bool isOverlapping(float xIn, float yIn) const;
        
        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects: determines if barrier overlaps the given point
         */
        virtual bool isOverlapping(Vector2i point) const;
        
        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects: determines if barrier overlaps the player
         */
        virtual bool isOverlapping(const Player &player) const;
    };

}

#endif //CS_120_FINAL_PROJECT_BARRIER_H
