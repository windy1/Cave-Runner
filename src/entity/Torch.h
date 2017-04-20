#ifndef CS_120_FINAL_PROJECT_TORCH_H
#define CS_120_FINAL_PROJECT_TORCH_H

#include "Entity.h"

namespace game {

    class Torch : public Entity {
    public:

        Torch();

        virtual string getType() const override;

        virtual void draw() const override;

    };

}

#endif //CS_120_FINAL_PROJECT_TORCH_H
