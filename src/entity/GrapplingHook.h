#ifndef CS_120_FINAL_PROJECT_GRAPPLINGHOOK_H
#define CS_120_FINAL_PROJECT_GRAPPLINGHOOK_H

#include "../math.h"

namespace game {

    class GrapplingHook {

        Point2d pos;
        bool hooked;

    public:

        void shoot(Point2d target);

        bool isHooked() const;

    };

}

#endif //CS_120_FINAL_PROJECT_GRAPPLINGHOOK_H
