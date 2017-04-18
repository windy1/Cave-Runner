#ifndef CS_120_FINAL_PROJECT_GRAPHICS_H
#define CS_120_FINAL_PROJECT_GRAPHICS_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#include "../math.h"
#include "Color.h"

#else
#include <GL/glut.h>
#endif

namespace graphics {

    /**
     * Requires: none
     * Effects: starts the main game loop
     * Modifies: game state
     */
    void init(int argc, char **argv);

    /**
     * Requires: dimen's x and y are both non-negative
     * Effects: draws a rectangle with the given dimensions, position, and color
     * Modifies: the window buffer
     */
    void drawRect(const Vector2i &dimen, const Vector2i &pos, const Color &color = {1, 1, 1, 1});

}

#endif //CS_120_FINAL_PROJECT_GRAPHICS_H
