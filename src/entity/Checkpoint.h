#ifndef CS_120_FINAL_PROJECT_CHECKPOINT_H
#define CS_120_FINAL_PROJECT_CHECKPOINT_H

#include "../game.h"

namespace game {

    /**
     * A marker for saved game locations.
     */
    class Checkpoint : public Entity {

        Vector2i flagDimen;

    public:

        static const Vector2i DEFAULT_FLAG_DIMENSIONS;
        static const Vector2i DEFAULT_POLE_DIMENSIONS;

        Checkpoint();

        Checkpoint(Vector3f pos);

        /**
         * Requires: none
         * Modifies: none
         * Effects: returns the dimensions of the flag portion
         */
        Vector2i getFlagDimensions() const;

        /**
         * Requires: dimensions > 0
         * Modifies: flag dimensions
         * Effects: sets the dimensions of the flag portion
         */
        void setFlagDimensions(Vector2i flagDimen);

        virtual string getType() const override;

        virtual void draw() const override;

    };

}

#endif //CS_120_FINAL_PROJECT_CHECKPOINT_H
