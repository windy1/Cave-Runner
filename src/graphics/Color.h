#ifndef CS_120_FINAL_PROJECT_COLOR_H
#define CS_120_FINAL_PROJECT_COLOR_H

#include <iostream>

using namespace std;

namespace game {

    /**
     * An RGBA color where each value ranges from 0-1
     */
    struct Color {

        static const Color WHITE;
        static const Color BLACK;
        static const Color RED;
        static const Color GREEN;
        static const Color BLUE;
        static const Color SAND;
        static const Color SAND_DARK;
        static const Color BROWN;
        static const Color SADDLE_BROWN;
        static const Color ORANGE;
        static const Color SILVER;
        static const Color DIM_GRAY;

        float r;
        float g;
        float b;
        float a;

        Color();

        Color(float r, float g, float b, float a);

        Color(float r, float g, float b);

        friend ostream &operator<<(ostream &stream, const Color &color);

    };

}

#endif //CS_120_FINAL_PROJECT_COLOR_H
