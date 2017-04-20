#ifndef CS_120_FINAL_PROJECT_ENTITY_H
#define CS_120_FINAL_PROJECT_ENTITY_H

#include "../math.h"
#include "../graphics/Color.h"
class Player;

namespace game {

    class Entity {
    protected:

        Vector2f pos;
        Vector2f velocity;
        Vector2i dimensions;
        Color color = Color::WHITE;
        bool dead;

    public:

        // entity type names (no abstracts)
        static const string BARRIER;
        static const string COIN;
        static const string GRAPPLING_HOOK;
        static const string PLAYER;
        static const string POWER_UP;
        static const string SCORE;

        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects: returns entity position as Point2D
         */
        Vector2f getPosition() const;

        /**
         * Requires: a position
         * Modifies: the entities position
         * Effects: sets the position to the supplied Vector2i
         */
        void setPosition(Vector2f pos);

        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects: returns this entities velocity
         */
        Vector2f getVelocity() const;

        /**
         * Requires: a velocity
         * Modifies: the entities velocity
         * Effects: sets the velocity to the supplied Vector2i
         * @param velocity
         */
        void setVelocity(Vector2f velocity);

        /**
         * Requires: none
         * Modifies: none
         * Effects: returns the entities width and height in a vector
         */
        Vector2i getDimensions() const;

        /**
         * Requires: dimensions x and y are non-negative
         * Modifies: entities dimensions
         * Effects: sets the entities dimensions
         */
        void setDimensions(Vector2i dimensions);

        /**
         * Requires: none
         * Modifies: none
         * Effects: returns this entity's color
         */
        Color getColor() const;

        /**
         * Requires: none
         * Modifies: entity color
         * Effects: sets this entity's color
         */
        void setColor(Color color);

        /**
         * Requires: none
         * Modifies: none
         * Effects: returns the string name of this entity type
         */
        virtual string getType() const = 0;

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
         * Effects: draws this entity to the screen - pure virtual
         */
        virtual void draw() const = 0;
        
        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects: determines if entity overlaps the given point - pure virtual
         */
        //TODO actually make this pure virtual
        virtual bool isOverlapping(float xIn, float yIn) const;
        
        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects: determines if entity overlaps the player - pure virtual
         */
        //TODO actually make this pure virtual
        virtual bool isOverlapping(const Player &player) const;

        friend ostream& operator<<(ostream &stream, const Entity &entity);

    };

}


#endif //CS_120_FINAL_PROJECT_ENTITY_H
