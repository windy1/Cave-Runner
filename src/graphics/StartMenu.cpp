#include "graphics.h"
#include "StartMenu.h"

namespace game {

    void StartMenu::draw() const {
        string title = "C A V E  R U N N E R";
        string controls1 = "Use the spacebar to jump";
        string controls2 = "Click to use your grappling hook";
        string controls3 = "Press S to place a checkpoint";
        string directions1 = "Avoid the obstacles!";
        string directions2 = "Click anywhere to start a new game!";
        string directions3 = "Press R to resume from your last checkpoint!";
        Vector2i wd = getWindowDimensions();
        drawString(Vector2i(wd.x/2 - 110, wd.y/4), title, textColor);
        drawString(Vector2i(wd.x/2 - 120, wd.y/2), controls1, textColor);
        drawString(Vector2i(wd.x/2 - 150, wd.y/2 + 25), controls2, textColor);
        drawString(Vector2i(wd.x/2 - 140, wd.y/2 + 50), controls3, textColor);
        drawString(Vector2i(wd.x/2 - 100, wd.y/2 + 100), directions1, textColor);
        drawString(Vector2i(wd.x/2 - 180, wd.y/2 + 125), directions2, textColor);
        drawString(Vector2i(wd.x/2 - 220, wd.y/2 + 150), directions3, textColor);
    }

}
