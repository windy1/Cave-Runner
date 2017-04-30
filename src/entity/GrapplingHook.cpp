#include "GrapplingHook.h"
#include "../graphics/graphics.h"
#include "../game.h"

namespace game {

    GrapplingHook::GrapplingHook() : Entity() {
        dimensions = Vector2i(10, 360);
    }

    void GrapplingHook::shoot(Vector2f target) {
        if (!shot) {
            // TODO
        }
    }

    bool GrapplingHook::isHooked() const {
        return hooked;
    }

    void GrapplingHook::setHooked(bool hooked) {
        this->hooked = hooked;
    }

    bool GrapplingHook::isShot() const {
        return shot;
    }

    void GrapplingHook::draw() const {
        if (hooked) {
            graphics::drawCircle(dimensions, Vector2f(pos).round(), color);
            player_ptr player = game::getPlayer();
            Vector2i pDimen = player->getDimensions();
            Vector2f startPos = Vector2f(player->getPosition()) + Vector2f(pDimen.x / 2, pDimen.y / 2);
            graphics::drawLine(Vector2f(pos).round(), startPos.round());
        }
    }

    string GrapplingHook::getType() const {
        return GRAPPLING_HOOK;
    }

}
