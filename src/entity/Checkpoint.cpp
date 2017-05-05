#include "Checkpoint.h"

namespace game {

    const Vector2i Checkpoint::DEFAULT_FLAG_DIMENSIONS(30, 20);
    const Vector2i Checkpoint::DEFAULT_POLE_DIMENSIONS(10, 20);

    Checkpoint::Checkpoint() : Entity() {
        color = Color::GREEN;
        dimensions = DEFAULT_POLE_DIMENSIONS;
        flagDimen = DEFAULT_FLAG_DIMENSIONS;
        velocity.x = -getScrollSpeed();
    }

    Checkpoint::Checkpoint(Vector3f pos) : Checkpoint() {
        this->pos = pos;
    }

    Vector2i Checkpoint::getFlagDimensions() const {
        return flagDimen;
    }

    void Checkpoint::setFlagDimensions(Vector2i flagDimen) {
        assert(flagDimen.x > 0 && flagDimen.y > 0);
        this->flagDimen = flagDimen;
    }

    string Checkpoint::getType() const {
        return CHECKPOINT;
    }

    void Checkpoint::draw() const {
        drawRect(dimensions, Vector2f(pos).round(), color);
        Vector2i flagPos = Vector2f(pos + Vector3f(0, dimensions.y, 0)).round();
        drawRect(flagDimen, flagPos, color);
    }

}
