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
