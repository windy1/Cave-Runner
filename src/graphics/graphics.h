#ifndef CS_120_FINAL_PROJECT_GRAPHICS_H
#define CS_120_FINAL_PROJECT_GRAPHICS_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

namespace graphics {

    struct Color {
        float r;
        float g;
        float b;
        float a;
    };

    /**
     * Requires: none
     * Effects: starts the main game loop
     * Modifies: game state
     */
    void init(int argc, char **argv);

}

#endif //CS_120_FINAL_PROJECT_GRAPHICS_H
