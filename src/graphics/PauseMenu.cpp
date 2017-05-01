#include "PauseMenu.h"
#include "../math.h"
#include "graphics.h"

namespace game {

    void PauseMenu::draw() const {
        string title = "PAUSED";
        string msg1 = "Press ESC to resume";
        string msg2 = "Press Q to quit";
        Vector2i wd = getWindowDimensions();
        drawString(Vector2i(wd.x/2 - 50, wd.y/3), title, textColor);
        drawString(Vector2i(wd.x/2 - 100, wd.y/2), msg1, textColor);
        drawString(Vector2i(wd.x/2 - 75, wd.y/2 + 25), msg2, textColor);
    }

}
