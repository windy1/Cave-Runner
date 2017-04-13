#ifndef CS_120_FINAL_PROJECT_ENTITY_H
#define CS_120_FINAL_PROJECT_ENTITY_H

#include "../math.h"

namespace game {

    class Entity {
    protected:

        Vector2i pos;
        Vector2i velocity;
        bool dead;

    public:

        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects: returns entity position as Point2D
         */
        Vector2i getPosition() const;

        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects: returns this entities velocity
         */
        Vector2i getVelocity() const;

        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects: returns true if the entity is dead and should be removed
         */
        bool isDead() const;

        /**
         * Requires: nothing
         * Modifies: sets the "dead" state of the entity
         * Effects: nothing
         */
        void setDead(bool dead);

        /**
         * Requires: nothing
         * Modifies: pos
         * Effects: moves entity by given amounts along the x and y axes
         */
        void move(float deltaX, float deltaY);

        /**
         * Requires: nothing
         * Modifies: entity properties
         * Effects: called every game loop, updates entity logic
         */
        virtual void update();

        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects: draws this entity to the screen
         */
        virtual void draw() const = 0;

    };

}


#endif //CS_120_FINAL_PROJECT_ENTITY_H
