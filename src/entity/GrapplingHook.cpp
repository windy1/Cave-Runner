#include "GrapplingHook.h"

namespace game {

    void GrapplingHook::shoot(Vector2i target) {
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

}
