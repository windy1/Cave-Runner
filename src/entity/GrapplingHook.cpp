#include "GrapplingHook.h"
#include "../graphics/graphics.h"
#include "../game.h"

namespace game {

    const Vector2i GrapplingHook::DEFAULT_DIMENSIONS        (10, 360);
    const Vector2f GrapplingHook::DEFAULT_RETRACT_VELOCITY  (5, 5);

    GrapplingHook::GrapplingHook(player_ptr player) {
        assert(player != NULL);
        this->player = player;
        dimensions = DEFAULT_DIMENSIONS;
        retractVelocity = DEFAULT_RETRACT_VELOCITY;
        velocity.x = -getGameState()->scrollSpeed;
    }

    player_ptr GrapplingHook::getPlayer() const {
        return player;
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

    void GrapplingHook::onLeaveScreen() {
        hooked = false;
    }

    void GrapplingHook::draw() const {
        if (hooked) {
            drawCircle(dimensions, Vector2f(pos).round(), color);
            Vector2i pDimen = player->getDimensions();
            Vector2f startPos = Vector2f(player->getPosition()) + Vector2f(pDimen.x / 2, pDimen.y / 2);
            drawLine(Vector2f(pos).round(), startPos.round());
        }
    }

    string GrapplingHook::getType() const {
        return GRAPPLING_HOOK;
    }

}
