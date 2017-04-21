#include "GrapplingHook.h"
#include "../graphics/graphics.h"

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
        graphics::drawCircle(dimensions, Vector2f(pos).round(), color);
    }

    string GrapplingHook::getType() const {
        return GRAPPLING_HOOK;
    }

}
