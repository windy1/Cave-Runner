#ifndef CS_120_FINAL_PROJECT_GRAPPLINGHOOK_H
#define CS_120_FINAL_PROJECT_GRAPPLINGHOOK_H

#include "../math.h"
#include "Entity.h"

namespace game {

    class GrapplingHook : public Entity {

        bool hooked;
        
        bool shot;

    public:

        void shoot(Vector2i target);

        bool isHooked() const;
        
        bool isShot() const;

    };

}

#endif //CS_120_FINAL_PROJECT_GRAPPLINGHOOK_H
