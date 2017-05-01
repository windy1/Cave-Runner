#include "graphics.h"
#include "StartMenu.h"

namespace game {

    void StartMenu::draw() const {
        string title = "GNARLY RASTAFARIAN";
        string controls1 = "Use the spacebar to jump";
        string controls2 = "Click to use your grappling hook";
        string directions1 = "Avoid the obstacles!";
        string directions2 = "Click anywhere to begin!";
        Vector2i wd = getWindowDimensions();
        drawString(Vector2i(wd.x/2 - 130, wd.y/4), title, textColor);
        drawString(Vector2i(wd.x/2 - 120, wd.y/2), controls1, textColor);
        drawString(Vector2i(wd.x/2 - 150, wd.y/2 + 25), controls2, textColor);
        drawString(Vector2i(wd.x/2 - 100, wd.y/2 + 100), directions1, textColor);
        drawString(Vector2i(wd.x/2 - 120, wd.y/2 + 125), directions2, textColor);
    }

}
