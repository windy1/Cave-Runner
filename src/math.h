#ifndef CS_120_FINAL_PROJECT_MATH_H
#define CS_120_FINAL_PROJECT_MATH_H

struct Vector2f {

    float x = 0;
    float y = 0;

    Vector2f();

    Vector2f(float x, float y);

    bool operator==(const Vector2f &other) const;

    bool operator!=(const Vector2f &other) const;

};

#endif //CS_120_FINAL_PROJECT_MATH_H
