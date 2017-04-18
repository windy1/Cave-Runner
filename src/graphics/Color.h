#ifndef CS_120_FINAL_PROJECT_COLOR_H
#define CS_120_FINAL_PROJECT_COLOR_H

#include <iostream>

using namespace std;

struct Color {

    static Color WHITE;
    static Color BLACK;
    static Color RED;
    static Color GREEN;
    static Color BLUE;

    float r;
    float g;
    float b;
    float a;

    Color();

    Color(float r, float g, float b, float a);

    Color(float r, float g, float b);

    friend ostream& operator<<(ostream &stream, const Color &color);

};


#endif //CS_120_FINAL_PROJECT_COLOR_H
