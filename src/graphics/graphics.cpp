#include "graphics.h"
#include "../math.h"
#include "../game.h"

namespace graphics {

    static const Vector2i   WINDOW_DIMEN            (500, 500);
    static const string     WINDOW_TITLE        =   "Untitled";
    static const Color      BACKGROUND_COLOR    =   {0, 0, 0, 1};

    static int windowId;

    static void display();
    static void onKey(unsigned char key, int x, int y);
    static void onSpecialKey(int key, int x, int y);
    static void onMouseMove(int x, int y);
    static void onMouseClick(int button, int state, int x, int y);

    void init(int argc, char **argv) {
        // initialize window
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_RGBA);
        glutInitWindowSize(WINDOW_DIMEN.x, WINDOW_DIMEN.y);
        glutInitWindowPosition(100, 500);
        windowId = glutCreateWindow(WINDOW_TITLE.c_str());
        glClearColor(BACKGROUND_COLOR.r, BACKGROUND_COLOR.g, BACKGROUND_COLOR.b, BACKGROUND_COLOR.a);
        // set callbacks
        glutDisplayFunc(display);
        glutKeyboardFunc(onKey);
        glutSpecialFunc(onSpecialKey);
        glutPassiveMotionFunc(onMouseMove);
        glutMouseFunc(onMouseClick);
        glutMainLoop();
    }

    static void display() {
        // initialize
        glViewport(0, 0, WINDOW_DIMEN.x, WINDOW_DIMEN.y);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0, WINDOW_DIMEN.x, WINDOW_DIMEN.y, 0.0, -1.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        // draw stuff
        game::update();

        // finished
        glFlush();

    }

    static void onKey(unsigned char key, int x, int y) {
        cout << "Key: " << key << " " << Vector2i(x, y) << endl;
        // TODO
    }

    static void onSpecialKey(int key, int x, int y) {
        cout << "Special Key: " << key << " " << Vector2i(x, y) << endl;
        // TODO
    }

    static void onMouseMove(int x, int y) {
        cout << "Mouse Move: " << Vector2i(x, y) << endl;
        // TODO
    }

    static void onMouseClick(int button, int state, int x, int y) {
        cout << "Mouse Click: " << button << " " << state << " " << Vector2i(x, y) << endl;
        // TODO
    }

}
