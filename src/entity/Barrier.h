#ifndef CS_120_FINAL_PROJECT_BARRIER_H
#define CS_120_FINAL_PROJECT_BARRIER_H

#include "Obstacle.h"
#include "../graphics/graphics.h"

namespace game {

    class Barrier : public Obstacle {
    public:

        Barrier();

        Barrier(Vector2f pos);

        virtual string getType() const override;

        virtual void draw() const override;
        
        virtual bool isOverlapping(float xIn, float yIn) const override;
        
        //this is causing an error - will deal with tomorrow morning
        virtual bool isOverlapping(const Player &player) const override;
        
    };

}

#endif //CS_120_FINAL_PROJECT_BARRIER_H
