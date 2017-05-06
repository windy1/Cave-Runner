#include "LevelButton.h"

namespace game {

    const Vector2i  LevelButton::DEFAULT_DIMENSIONS     (30, 30);
    const int       LevelButton::DEFAULT_BORDER_WIDTH   = 3;

    LevelButton::LevelButton() {
        dimen = DEFAULT_DIMENSIONS;
        borderWidth = DEFAULT_BORDER_WIDTH;
        borderColor = Color::SAND;
        color = Color::SAND_DARK;
        cout << "debug" << endl;
    }

    LevelButton::LevelButton(int level) : LevelButton() {
        this->level = level;
    }

    Vector2i LevelButton::getPosition() const {
        return pos;
    }

    void LevelButton::setPosition(Vector2i pos) {
        this->pos = pos;
    }

    Vector2i LevelButton::getDimensions() const {
        return dimen;
    }

    void LevelButton::setDimensions(Vector2i dimensions) {
        assert(dimensions.x > 0 && dimensions.y > 0);
        dimen = dimensions;
    }

    Color LevelButton::getColor() const {
        return color;
    }

    void LevelButton::setColor(Color color) {
        this->color = color;
    }

    int LevelButton::getBorderWidth() const {
        return borderWidth;
    }

    void LevelButton::setBorderWidth(int borderWidth) {
        this->borderWidth = borderWidth;
    }

    Color LevelButton::getBorderColor() const {
        return borderColor;
    }

    void LevelButton::setBorderColor(Color borderColor) {
        this->borderColor = borderColor;
    }

    bool LevelButton::isHovered() const {
        return hovered;
    }

    void LevelButton::setHovered(bool hovered) {
        this->hovered = hovered;
    }

    bool LevelButton::isOverlapping(int x, int y) {
        Vector2i pt = invertY(pos, getWindowDimensions());
        return x >= pt.x && x <= pt.x + dimen.x && y >= pt.y - dimen.y && y <= pt.y;
    }

    void LevelButton::draw() const {
        Vector2i outerDimen = dimen + Vector2i(borderWidth * 2, borderWidth * 2);
        Vector2i innerPos = pos + Vector2i(borderWidth, borderWidth);
        drawRect(outerDimen, pos, borderColor);
        drawRect(dimen, innerPos, color);
        drawString(invertY(innerPos, getWindowDimensions()) + Vector2i(9, -6), to_string(level), borderColor);
    }

    void LevelButton::onMouseEnter() {
        cout << "mouse enter " << endl;
        setBorderColor(Color::SADDLE_BROWN);
    }

    void LevelButton::onMouseLeave() {
        cout << "mouse leave" << endl;
        setBorderColor(Color::SAND);
    }

    void LevelButton::onClick() {
        cout << "level click" << endl;
        startLevel(level);
    }

}
