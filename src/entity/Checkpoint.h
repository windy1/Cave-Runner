#ifndef CS_120_FINAL_PROJECT_CHECKPOINT_H
#define CS_120_FINAL_PROJECT_CHECKPOINT_H

#include "../game.h"

namespace game {

    class Checkpoint : public Entity {

        Vector2i flagDimen;

    public:

        static const Vector2i DEFAULT_FLAG_DIMENSIONS;
        static const Vector2i DEFAULT_POLE_DIMENSIONS;

        Checkpoint();

        Checkpoint(Vector3f pos);

        Vector2i getFlagDimensions() const;

        void setFlagDimensions(Vector2i flagDimen);

        virtual string getType() const override;

        virtual void draw() const override;

    };

}

#endif //CS_120_FINAL_PROJECT_CHECKPOINT_H
