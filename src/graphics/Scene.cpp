#include "Scene.h"
#include "graphics.h"
#include "../game.h"

namespace game {

    Scene::Scene() {
        floorCeilDimen = Vector2i(getWindowDimensions().x, getGroundY());
        floorPos = Vector2i(0, 0);
        ceilPos = Vector2i(0, getCeilingY());
        color = Color::SAND;
    }

    Vector2i Scene::getDimensions() const {
        return floorCeilDimen;
    }

    Vector2i Scene::getFloorPosition() const {
        return floorPos;
    }

    Vector2i Scene::getCeilingPosition() const {
        return ceilPos;
    }

    Color Scene::getColor() const {
        return color;
    }

    void Scene::draw() const {
        drawRect(floorCeilDimen, floorPos, color);
        drawRect(floorCeilDimen, ceilPos, color);
    }

}
