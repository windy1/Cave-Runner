#include "Torch.h"
#include "../graphics/graphics.h"
#include "../game.h"

namespace game {

    static const Vector2i HANDLE_DIMEN  (10, 20);
    static const Vector2i FLAME_DIMEN   (10, 10);

    Torch::Torch() : Entity() {
        pos.y = graphics::getWindowDimensions().y * 0.5f;
        pos.x = graphics::getWindowDimensions().x;
        pos.z = -1;
        velocity.x = -game::getGameState()->scrollSpeed;
    }

    string Torch::getType() const {
        return TORCH;
    }

    void Torch::draw() const {
        Vector2i pos2i = ((Vector2f) pos).round();
        graphics::drawRect(HANDLE_DIMEN, pos2i, Color::BROWN);
        graphics::drawRect(FLAME_DIMEN, pos2i + Vector2i(0, HANDLE_DIMEN.y), Color::ORANGE);
    }

}
