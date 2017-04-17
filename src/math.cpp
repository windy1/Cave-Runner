#include "math.h"

Vector2f::Vector2f() {
}

Vector2f::Vector2f(float x, float y) : x(x), y(y) {
}

bool Vector2f::operator==(const Vector2f &other) const {
    return x == other.x && y == other.y;
}

bool Vector2f::operator!=(const Vector2f &other) const {
    return !(*this == other);
}

ostream& operator<<(ostream &stream, const Vector2f &vec2f) {
    stream << "(" << vec2f.x << ", " << vec2f.y << ")";
    return stream;
}

Vector2i::Vector2i() {
}

Vector2i::Vector2i(int x, int y) : x(x), y(y) {
}

bool Vector2i::operator==(const Vector2i &other) const {
    return x == other.x && y == other.y;
}

bool Vector2i::operator!=(const Vector2i &other) const {
    return !(*this == other);
}

ostream& operator<<(ostream &stream, const Vector2i &vec2i) {
    stream << "(" << vec2i.x << ", " << vec2i.y << ")";
    return stream;
}
