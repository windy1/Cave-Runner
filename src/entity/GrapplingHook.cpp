#include "GrapplingHook.h"

namespace game {

    /**
     * Requires: grappling hook is not being shot already
     * Modifies: grappling hook pos, isShot boolean, isHooked boolean
     * Effects: grappling hook pos updates towards selected target, stops on object if ever overlaps object on way to target until player reaches target
     */
    void GrapplingHook::shoot(Vector2i target) {
        if (!shot) {
            // TODO
        }
    }

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: checks if grappling hook is currently hooked onto an object
     */
    bool GrapplingHook::isHooked() const {
        return hooked;
    }
    
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: checks if grappling hook is currently being shot
     */
    bool GrapplingHook::isShot() const {
        return shot;
    }

}
