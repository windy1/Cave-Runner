#ifndef CS_120_FINAL_PROJECT_MATH_H
#define CS_120_FINAL_PROJECT_MATH_H

#include <iostream>

using namespace std;

struct Vector2i {

    int x = 0;
    int y = 0;

    Vector2i();

    Vector2i(int x, int y);

    bool operator==(const Vector2i &other) const;

    bool operator!=(const Vector2i &other) const;

    friend ostream& operator<<(ostream& stream, const Vector2i &vec2i);

};

struct Vector2f {

    float x = 0;
    float y = 0;

    Vector2f();

    Vector2f(float x, float y);

    Vector2i round() const;

    bool operator==(const Vector2f &other) const;

    bool operator!=(const Vector2f &other) const;
    
    static float distance(const Vector2f &p1, const Vector2f &p2);

    friend ostream& operator<<(ostream& stream, const Vector2f &vec2f);

};

Vector2i invertY(const Vector2i &coords, const Vector2i &screenDimen);

#endif //CS_120_FINAL_PROJECT_MATH_H
