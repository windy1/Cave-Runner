#ifndef CS_120_FINAL_PROJECT_LEVELSELECT_H
#define CS_120_FINAL_PROJECT_LEVELSELECT_H

#include "graphics.h"
#include "../game.h"

namespace game {

    class LevelButton {

        Vector2i pos;
        Vector2i dimen;
        int borderWidth;
        Color color;
        Color borderColor;
        bool hovered = false;
        int level = 1;

    public:

        static const Vector2i   DEFAULT_DIMENSIONS;
        static const int        DEFAULT_BORDER_WIDTH;

        LevelButton();

        LevelButton(int level);

        Vector2i getPosition() const;

        void setPosition(Vector2i pos);

        Vector2i getDimensions() const;

        void setDimensions(Vector2i dimensions);

        Color getColor() const;

        void setColor(Color color);

        int getBorderWidth() const;

        void setBorderWidth(int borderWidth);

        Color getBorderColor() const;

        void setBorderColor(Color borderColor);

        bool isHovered() const;

        void setHovered(bool hovered);

        bool isOverlapping(int x, int y);

        void draw() const;

        void onMouseEnter();

        void onMouseLeave();

        void onClick();

    };

}

#endif //CS_120_FINAL_PROJECT_LEVELSELECT_H
