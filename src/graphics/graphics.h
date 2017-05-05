#ifndef CS_120_FINAL_PROJECT_GRAPHICS_H
#define CS_120_FINAL_PROJECT_GRAPHICS_H

#include "../math.h"
#include "Color.h"
#include <cmath>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

namespace game {

    /**
     * Requires: none
     * Effects: starts the main game loop
     * Modifies: game state
     */
    void initGraphics(int argc, char **argv);

    /**
     * Requires: dimen's x and y are both non-negative
     * Effects: draws a rectangle with the given dimensions, position, and color
     * Modifies: the window buffer
     */
    void drawRect(const Vector2i &dimen, const Vector2i &pos, const Color &color = {1, 1, 1, 1});
    
    /**
     * Requires: dimen's x (radius) and y (numb pts for tri fan) are both non-negative
     * Effects: draws a circle with the given radius and num tri fan pts, center, and color
     * Modifies: the window buffer
     */
    void drawCircle(const Vector2i &dimen, const Vector2i &center, const Color &color = {1, 1, 1, 1});
    
    /**
     * Requires: nothing
     * Effects: draws a string with given start_pos, message, and color
     * Modifies: the window buffer
     */
    void drawString(const Vector2i &start_pos, string message, const Color &color);

    /**
     * Requires: none
     * Modifies: none
     * Effects: Draws a line from p1 to p2
     */
    void drawLine(const Vector2i &p1, const Vector2i &p2, const Color &color, float lineWidth);

    /**
     * Requires: none
     * Modifies: none
     * Effects: returns the window's dimensions
     */
    Vector2i getWindowDimensions();

}

#endif //CS_120_FINAL_PROJECT_GRAPHICS_H
