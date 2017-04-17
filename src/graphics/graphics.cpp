#include "graphics.h"
#include "../game.h"
#include <cassert>

namespace graphics {

    static const Vector2i   WINDOW_DIMEN            (900, 400);
    static const string     WINDOW_TITLE        =   "Untitled";
    static const Color      BACKGROUND_COLOR    =   {0, 0, 0, 1};

    static int windowId;

    static void display();
    static void onKey(unsigned char key, int x, int y);
    static void onSpecialKey(int key, int x, int y);
    static void onMouseMove(int x, int y);
    static void onMouseClick(int button, int state, int x, int y);
    static void timer(int extra);

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
        glutTimerFunc(0, timer, 0);
        glutMainLoop();
    }

    void drawRect(const Vector2i &dimen, const Vector2i &pos, const Color &color) {
        // pos = bottom left corner of rectangle dimensions
        // y-axis = 0-height bottom to top
        // x-axis = 0-width left to right
        assert(dimen.x >= 0 && dimen.y >= 0);
        Vector2i screenPos = invertY(pos, WINDOW_DIMEN);
        glColor4f(color.r, color.g, color.b, color.a);
        glBegin(GL_QUADS);
        glVertex2i(screenPos.x, screenPos.y - dimen.y);             // top left
        glVertex2i(screenPos.x + dimen.x, screenPos.y - dimen.y);   // top right
        glVertex2i(screenPos.x + dimen.x, screenPos.y);             // bottom right
        glVertex2i(screenPos.x, screenPos.y);                       // bottom left
        glEnd();
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
        glutPostRedisplay();
    }

    static void onSpecialKey(int key, int x, int y) {
        cout << "Special Key: " << key << " " << Vector2i(x, y) << endl;
        // TODO
        glutPostRedisplay();
    }

    static void onMouseMove(int x, int y) {
        cout << "Mouse Move: " << Vector2i(x, y) << endl;
        // TODO
        glutPostRedisplay();
    }

    static void onMouseClick(int button, int state, int x, int y) {
        cout << "Mouse Click: " << button << " " << state << " " << Vector2i(x, y) << endl;
        // TODO
        glutPostRedisplay();
    }

    static void timer(int extra) {
        glutPostRedisplay();
        glutTimerFunc(2, timer, 0);
    }

    ostream& operator<<(ostream &stream, const Color &color) {
        stream << "Color(" << color.r << ", " << color.g << ", " << color.b << ", " << color.a << ")";
        return stream;
    }

}
