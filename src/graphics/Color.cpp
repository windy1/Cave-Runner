#include "Color.h"

const Color Color::WHITE(1, 1, 1);
const Color Color::BLACK(0, 0, 0);
const Color Color::RED(1, 0, 0);
const Color Color::GREEN(0, 1, 0);
const Color Color::BLUE(0, 0, 1);
const Color Color::SAND(0.761, 0.698, 0.502);
const Color Color::SAND_DARK(0.4627, 0.4, 0.2039);
const Color Color::BROWN(0.6471, 0.1647, 0.1647);
const Color Color::ORANGE(1, 0.6471, 0);

Color::Color() {
}

Color::Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {
}

Color::Color(float r, float g, float b) : Color::Color(r, g, b, 1) {
}

ostream& operator<<(ostream &stream, const Color &color) {
    stream << "Color(" << color.r << ", " << color.g << ", " << color.b << ", " << color.a << ")";
    return stream;
}
