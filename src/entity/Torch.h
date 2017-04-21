#ifndef CS_120_FINAL_PROJECT_TORCH_H
#define CS_120_FINAL_PROJECT_TORCH_H

#include "Entity.h"

namespace game {

    class Torch : public Entity {
    public:

        // constructors
        
        Torch();

        // get type
        virtual string getType() const override;

        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects: draws torch as two rectangles: handle and flame
         */
        virtual void draw() const override;

    };

}

#endif //CS_120_FINAL_PROJECT_TORCH_H
