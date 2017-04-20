#include "graphics.h"
#include "../game.h"
#include <cassert>

namespace graphics {

    static const char KEY_SPACE     = ' ';
    static const char KEY_ESCAPE    = 27;
    static const char KEY_QUIT      = 'q';

    static const Vector2i   WINDOW_DIMEN            (700, 400);
    static const string     WINDOW_TITLE        =   "Untitled";

    static const Vector2i   FLOOR_CEIL_DIMEN        (WINDOW_DIMEN.x, game::getGroundY());
    static const Vector2i   FLOOR_POS               (0, 0);
    static const Vector2i   CEIL_POS                (0, WINDOW_DIMEN.y - FLOOR_CEIL_DIMEN.y);

    static int windowId;

    // callback declarations
    static void display();
    static void onKey(unsigned char key, int x, int y);
    static void onSpecialKey(int key, int x, int y);
    static void onMouseMove(int x, int y);
    static void onMouseClick(int button, int state, int x, int y);
    static void timer(int extra);

    static void drawScene();

    void init(int argc, char **argv) {
        // initialize window
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_RGBA);
        glutInitWindowSize(WINDOW_DIMEN.x, WINDOW_DIMEN.y);
        glutInitWindowPosition(100, 500);
        windowId = glutCreateWindow(WINDOW_TITLE.c_str());
        Color bg = Color::SAND_DARK;
        glClearColor(bg.r, bg.g, bg.b, bg.a);
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
    
    void drawCircle(const Vector2i &dimen, const Vector2i &center, const Color &color) {
        // dimen = (radius, number of points for triangle fan)
        assert(dimen.x >= 0 && dimen.y >= 0);
        int radius = dimen.x;
        glBegin(GL_TRIANGLE_FAN);
        glColor4f(color.r, color.g, color.b, color.a);
        glVertex2i(center.x, center.y);
        for (int i = 0; i <= dimen.y; i++) {
            double radians = i * M_PI / 180.0;
            glVertex2i((int) round(center.x + radius * cos(radians)), (int) round(center.y + radius * sin(radians)));
        }
        glEnd();
    }

    Vector2i getWindowDimensions() {
        return WINDOW_DIMEN;
    }

    /* callback definitions */

    static void display() {
        // initialize
        glViewport(0, 0, WINDOW_DIMEN.x, WINDOW_DIMEN.y);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0, WINDOW_DIMEN.x, WINDOW_DIMEN.y, 0.0, -1.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        // draw stuff
        drawScene();
        if (!game::isPaused()) {
            game::update();
        }
        game::draw();

        // finished
        glFlush();
    }

    static void drawScene() {
        drawRect(FLOOR_CEIL_DIMEN, FLOOR_POS, Color::SAND);
        drawRect(FLOOR_CEIL_DIMEN, CEIL_POS, Color::SAND);
    }

    static void onKey(unsigned char key, int x, int y) {
        cout << "Key: " << key << " " << Vector2i(x, y) << endl;
        switch (key) {
            case KEY_SPACE:
                game::getPlayer()->jump();
                break;
            case KEY_ESCAPE:
                game::setPaused(!game::isPaused());
                break;
            case KEY_QUIT:
                glutDestroyWindow(windowId);
                exit(0);
                break;
            default:
                break;
        }
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

}
