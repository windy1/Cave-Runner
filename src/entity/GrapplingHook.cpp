#include "GrapplingHook.h"
#include "../graphics/graphics.h"
#include "../game.h"

namespace game {

    GrapplingHook::GrapplingHook() {
        dimensions = Vector2i(10, 360);
        velocity.x = -getGameState()->scrollSpeed;
        retractVelocity = Vector2f(5, 5);
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

    Vector2f GrapplingHook::getRetractVelocity() const {
        return retractVelocity;
    }

    void GrapplingHook::setRetractVelocity(Vector2f retractVelocity) {
        this->retractVelocity = retractVelocity;
    }

    bool GrapplingHook::isShot() const {
        return shot;
    }

    void GrapplingHook::onLeaveScreen() {
        hooked = false;
    }

    void GrapplingHook::draw() const {
        if (hooked) {
            drawCircle(dimensions, Vector2f(pos).round(), color);
            player_ptr player = getPlayer();
            Vector2i pDimen = player->getDimensions();
            Vector2f startPos = Vector2f(player->getPosition()) + Vector2f(pDimen.x / 2, pDimen.y / 2);
            drawLine(Vector2f(pos).round(), startPos.round());
        }
    }

    string GrapplingHook::getType() const {
        return GRAPPLING_HOOK;
    }

}
