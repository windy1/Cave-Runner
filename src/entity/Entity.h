#ifndef CS_120_FINAL_PROJECT_ENTITY_H
#define CS_120_FINAL_PROJECT_ENTITY_H

#include "../math.h"

namespace game {

    class Entity {

        Point2d pos;

    public:

        Point2d getPosition() const;

        void move(float deltaX, float deltaY);

    };

}


#endif //CS_120_FINAL_PROJECT_ENTITY_H
