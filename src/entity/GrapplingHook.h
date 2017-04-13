#ifndef CS_120_FINAL_PROJECT_GRAPPLINGHOOK_H
#define CS_120_FINAL_PROJECT_GRAPPLINGHOOK_H

#include "../math.h"
#include "Entity.h"

namespace game {

    class GrapplingHook : public Entity {

        bool hooked;
        bool shot;

    public:

        /**
         * Requires: grappling hook is not being shot already
         * Modifies: grappling hook pos, isShot boolean, isHooked boolean
         * Effects: grappling hook pos updates towards selected target, stops on object if ever overlaps object on way to target until player reaches target
         */
        void shoot(Vector2i target);

        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects: checks if grappling hook is currently hooked onto an object
         */
        bool isHooked() const;

        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects: checks if grappling hook is currently being shot
         */
        bool isShot() const;

    };

}

#endif //CS_120_FINAL_PROJECT_GRAPPLINGHOOK_H
