#ifndef CS_120_FINAL_PROJECT_BARRIER_H
#define CS_120_FINAL_PROJECT_BARRIER_H

#include "Obstacle.h"

namespace game {

    class Barrier : public Obstacle {
    public:

        Barrier();

        Barrier(Vector2f pos);

        virtual void draw() const override;

    };

}

#endif //CS_120_FINAL_PROJECT_BARRIER_H