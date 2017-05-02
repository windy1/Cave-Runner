#include "Torch.h"
#include "../graphics/graphics.h"
#include "../game.h"

namespace game {

    const Vector2i Torch::DEFAULT_DIMENSIONS        (10, 20);
    const Vector2i Torch::DEFAULT_FLAME_DIMENSIONS  (10, 10);
    const Vector3f Torch::DEFAULT_POSITION          (getWindowDimensions().x, getWindowDimensions().y * 0.5f, -1);

    Torch::Torch() : Entity() {
        dimensions = DEFAULT_DIMENSIONS;
        flameDimen = DEFAULT_FLAME_DIMENSIONS;
        pos = DEFAULT_POSITION;
        velocity.x = -getGameState()->scrollSpeed;
    }

    Vector2i Torch::getFlameDimensions() const {
        return flameDimen;
    }

    void Torch::setFlameDimensions(Vector2i flameDimen) {
        assert(flameDimen.x >= 0 && flameDimen.y >= 0);
        this->flameDimen = flameDimen;
    }

    string Torch::getType() const {
        return TORCH;
    }

    void Torch::draw() const {
        Vector2i pos2i = Vector2f(pos).round();
        drawRect(dimensions, pos2i, Color::BROWN);
        drawRect(flameDimen, pos2i + Vector2i(0, dimensions.y), Color::ORANGE);
    }

}
