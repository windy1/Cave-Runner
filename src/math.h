#ifndef CS_120_FINAL_PROJECT_MATH_H
#define CS_120_FINAL_PROJECT_MATH_H

#include <iostream>

using namespace std;

struct Vector2f {

    float x = 0;
    float y = 0;

    Vector2f();

    Vector2f(float x, float y);

    bool operator==(const Vector2f &other) const;

    bool operator!=(const Vector2f &other) const;

    friend ostream& operator<<(ostream& stream, const Vector2f &vec2f);

};

struct Vector2i {

    int x = 0;
    int y = 0;

    Vector2i();

    Vector2i(int x, int y);

    bool operator==(const Vector2i &other) const;

    bool operator!=(const Vector2i &other) const;

    friend ostream& operator<<(ostream& stream, const Vector2i &vec2i);

};


#endif //CS_120_FINAL_PROJECT_MATH_H
