#include <cmath>
#include "math.h"

/* Vector2f */

Vector2f::Vector2f() {
}

Vector2f::Vector2f(float x, float y) : x(x), y(y) {
}

Vector2f::Vector2f(Vector3f vec3f) : Vector2f(vec3f.x, vec3f.y) {
}

Vector2i Vector2f::round() const {
    return Vector2i((int) std::round(x), (int) std::round(y));
}

bool Vector2f::operator==(const Vector2f &other) const {
    return x == other.x && y == other.y;
}

bool Vector2f::operator!=(const Vector2f &other) const {
    return !(*this == other);
}

Vector2f Vector2f::operator+(const Vector2f &other) const {
    return Vector2f(x + other.x, y + other.y);
}

Vector2f Vector2f::operator-(const Vector2f &other) const {
    return Vector2f(x - other.x, y - other.y);
}

Vector2f Vector2f::operator*(const Vector2f &other) const {
    return Vector2f(x * other.x, y * other.y);
}

Vector2f Vector2f::operator/(const Vector2f &other) const {
    return Vector2f(x / other.x, y / other.y);
}

float Vector2f::distance(const Vector2f &p1, const Vector2f &p2) {
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

ostream& operator<<(ostream &stream, const Vector2f &vec2f) {
    stream << "(" << vec2f.x << ", " << vec2f.y << ")";
    return stream;
}


/* Vector2i */

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

Vector2i Vector2i::operator+(const Vector2i &other) const {
    return Vector2i(x + other.x, y + other.y);
}

Vector2i Vector2i::operator-(const Vector2i &other) const {
    return Vector2i(x - other.x, y - other.y);
}

Vector2i Vector2i::operator*(const Vector2i &other) const {
    return Vector2i(x * other.x, y * other.y);
}

Vector2i Vector2i::operator/(const Vector2i &other) const {
    return Vector2i(x / other.x, y / other.y);
}

ostream& operator<<(ostream &stream, const Vector2i &vec2i) {
    stream << "(" << vec2i.x << ", " << vec2i.y << ")";
    return stream;
}

Vector2i invertY(const Vector2i &coords, const Vector2i &screenDimen) {
    return Vector2i(coords.x, screenDimen.y - coords.y);
}


/* Vector3f */

Vector3f::Vector3f() {
}

Vector3f::Vector3f(float x, float y, float z) : x(x), y(y), z(z) {
}

Vector3f::Vector3f(Vector2f vec2f, float z) : Vector3f(vec2f.x, vec2f.y, z){
}

bool Vector3f::operator==(const Vector3f &other) const {
    return x == other.x && y == other.y && z == other.z;
}

bool Vector3f::operator!=(const Vector3f &other) const {
    return !(*this == other);
}

Vector3f Vector3f::operator+(const Vector3f &other) const {
    return Vector3f(x + other.x, y + other.y, z + other.z);
}

Vector3f Vector3f::operator-(const Vector3f &other) const {
    return Vector3f(x - other.x, y - other.y, z - other.z);
}

Vector3f Vector3f::operator*(const Vector3f &other) const {
    return Vector3f(x * other.x, y * other.y, z * other.z);
}

Vector3f Vector3f::operator/(const Vector3f &other) const {
    return Vector3f(x / other.x, y / other.y, z / other.z);
}

ostream& operator<<(ostream &stream, const Vector3f &vec3f) {
    stream << "(" << vec3f.x << ", " << vec3f.y << ", " << vec3f.z << ")";
    return stream;
}
