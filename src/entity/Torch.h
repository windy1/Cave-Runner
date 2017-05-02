#ifndef CS_120_FINAL_PROJECT_TORCH_H
#define CS_120_FINAL_PROJECT_TORCH_H

#include "Entity.h"

namespace game {

    /**
     * A torch that is placed on the scene.
     */
    class Torch : public Entity {

        Vector2i flameDimen;

    public:

        /// Defaults
        static const Vector2i DEFAULT_DIMENSIONS;
        static const Vector2i DEFAULT_FLAME_DIMENSIONS;
        static const Vector3f DEFAULT_POSITION;

        Torch();

        /**
         * Requires: none
         * Modifies: none
         * Effects: returns the dimensions of the flame
         */
        Vector2i getFlameDimensions() const;

        /**
         * Requires: flameDimen >= (0, 0)
         * Modifies: flame dimensions
         * Effects: sets the dimensions of the flame
         */
        void setFlameDimensions(Vector2i flameDimen);

        virtual string getType() const override;

        virtual void draw() const override;

    };

}

#endif //CS_120_FINAL_PROJECT_TORCH_H
