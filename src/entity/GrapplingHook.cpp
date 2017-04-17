#include "GrapplingHook.h"

namespace game {

    void GrapplingHook::shoot(Vector2f target) {
        if (!shot) {
            // TODO
        }
    }

    bool GrapplingHook::isHooked() const {
        return hooked;
    }

    bool GrapplingHook::isShot() const {
        return shot;
    }

    void GrapplingHook::draw() const {
        // TODO
    }

    string GrapplingHook::getType() const {
        return GRAPPLING_HOOK;
    }

}
