#include "GrapplingHook.h"
#include "../graphics/graphics.h"
#include "../game.h"

namespace game {

    const Vector2i GrapplingHook::DEFAULT_DIMENSIONS        (7, 360);
    const Vector2f GrapplingHook::DEFAULT_RETRACT_VELOCITY  (5, 5);

    GrapplingHook::GrapplingHook(player_ptr player) {
        assert(player != NULL);
        this->player = player;
        dimensions = DEFAULT_DIMENSIONS;
        retractVelocity = DEFAULT_RETRACT_VELOCITY;
        velocity.x = -getGameState()->scrollSpeed;
        color = Color::SADDLE_BROWN;
        hookColor = Color::DIM_GRAY;
        ropeWidth = DEFAULT_ROPE_WIDTH;
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

    Color GrapplingHook::getHookColor() const {
        return hookColor;
    }

    void GrapplingHook::setHookColor(Color hookColor) {
        this->hookColor = hookColor;
    }

    float GrapplingHook::getRopeWidth() const {
        return ropeWidth;
    }

    void GrapplingHook::setRopeWidth(float ropeWidth) {
        this->ropeWidth = ropeWidth;
    }

    void GrapplingHook::onLeaveScreen() {
        hooked = false;
    }

    void GrapplingHook::draw() const {
        if (hooked) {
            Vector2i pDimen = player->getDimensions();
            Vector2f startPos = Vector2f(player->getPosition()) + Vector2f(pDimen.x / 2, pDimen.y / 2);
            drawLine(Vector2f(pos).round(), startPos.round(), color, ropeWidth);
            drawCircle(dimensions, Vector2f(pos).round(), hookColor);
        }
    }

    string GrapplingHook::getType() const {
        return GRAPPLING_HOOK;
    }

}
