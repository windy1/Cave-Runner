#include "graphics.h"
#include "../game.h"
#include "../entity/Player.h"
#include "Menu.h"
#include "StartMenu.h"
#include "PauseMenu.h"

namespace game {

    static const char KEY_SPACE     = ' ';
    static const char KEY_ESCAPE    = 27;
    static const char KEY_QUIT      = 'q';

    static const Vector2i   WINDOW_DIMEN            (700, 400);
    static const string     WINDOW_TITLE        =   "Untitled";

    static const Vector2i   FLOOR_CEIL_DIMEN        (WINDOW_DIMEN.x, getGroundY());
    static const Vector2i   FLOOR_POS               (0, 0);
    static const Vector2i   CEIL_POS                (0, getCeilingY());

    static int windowId;

    enum page {menu, gameplay, pause};
    page currentPage;

    StartMenu startMenu;
    PauseMenu pauseMenu;
    
    // callback declarations
    static void display();
    static void onKey(unsigned char key, int x, int y);
    static void onSpecialKey(int key, int x, int y);
    static void onMouseMove(int x, int y);
    static void onMouseClick(int button, int state, int x, int y);
    static void timer(int extra);

    static void drawScene();

    void initGraphics(int argc, char **argv) {
        // default page
        currentPage = menu;

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

        startMenu = StartMenu();
        pauseMenu = PauseMenu();

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
        Vector2i pos = invertY(center, WINDOW_DIMEN);
        glBegin(GL_TRIANGLE_FAN);
        glColor4f(color.r, color.g, color.b, color.a);
        glVertex2i(center.x, pos.y);
        for (int i = 0; i <= dimen.y; i++) {
            double radians = i * M_PI / 180.0;
            glVertex2i((int) round(pos.x + radius * cos(radians)), (int) round(pos.y + radius * sin(radians)));
        }
        glEnd();
    }
    
    void drawString(const Vector2i &start_pos, string message, const Color &color) {
        glColor4f(color.r, color.g, color.b, color.a);
        glRasterPos2i(start_pos.x, start_pos.y);
        for (int i = 0; i < message.length(); i++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
        }
    }

    void drawLine(const Vector2i &p1, const Vector2i &p2, const Color &color) {
        glLineWidth(2.5);
        glColor4f(color.r, color.g, color.b, color.a);
        glBegin(GL_LINES);
        glVertex2i(p1.x, invertY(p1, WINDOW_DIMEN).y);
        glVertex2i(p2.x, invertY(p2, WINDOW_DIMEN).y);
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
        
        switch(currentPage) {
            case menu:
                startMenu.draw();
                break;
            case gameplay:
                // draw stuff
                drawScene();
                if (!isPaused()) {
                    update();
                }
                draw();
                break;
            case pause:
                pauseMenu.draw();
                break;
            default:
                break;
        }
        

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
                getPlayer()->jump();
                break;
            case KEY_ESCAPE:
                if (currentPage == menu) {
                    break;
                }
                setPaused(!isPaused());
                if (isPaused()) {
                    currentPage = pause;
                } else {
                    currentPage = gameplay;
                }
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
        glutPostRedisplay();
    }

    static void onMouseMove(int x, int y) {
        cout << "Mouse Move: " << Vector2i(x, y) << endl;
        glutPostRedisplay();
    }

    static void onMouseClick(int button, int state, int x, int y) {
        cout << "Mouse Click: " << button << " " << state << " " << Vector2i(x, y) << endl;
        switch (button) {
            case GLUT_LEFT_BUTTON: {
                hook_ptr hook = game::getPlayer()->getGrapplingHook();
                if (state == GLUT_UP) {
                    if (currentPage == menu) {
                        currentPage = gameplay;
                    } else if (currentPage == gameplay) {
                        hook->setHooked(false);
                    }
                } else if (state == GLUT_DOWN && currentPage == gameplay) {
                    Vector2i hookPos = invertY(Vector2i(x, y), WINDOW_DIMEN);
                    hookPos.y = min(hookPos.y, CEIL_POS.y);
                    hook->setPosition(Vector3f(hookPos, 0));
                    hook->setHooked(true);
                }
                break;
            }
            default:
                break;
        }
        glutPostRedisplay();
    }

    static void timer(int extra) {
        glutPostRedisplay();
        glutTimerFunc(2, timer, 0);
    }

}
