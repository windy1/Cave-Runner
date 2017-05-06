#include "StartMenu.h"

namespace game {

    StartMenu::StartMenu() {
        Vector2i wd = getWindowDimensions();
        for (int i = 0; i < getTotalLevels(); i++) {
            LevelButton btn(i + 1);
            btn.setPosition(Vector2i(wd.x/2 - 70 + (i * (btn.getDimensions().x + 20)), wd.y - wd.y/2 + 40));
            levelButtons.push_back(btn);
        }
    }

    void StartMenu::draw() const {
        string title = "C A V E  R U N N E R";
        string controls1 = "Use the spacebar to jump";
        string controls2 = "Click to use your grappling hook";
        string controls3 = "Press S to place a checkpoint";
        string directions1 = "Avoid the obstacles!";
        string directions2 = "Press R to resume from your last checkpoint!";
        Vector2i wd = getWindowDimensions();
        drawString(Vector2i(wd.x/2 - 110, wd.y/4), title, textColor);

        for (int i = 0; i < levelButtons.size(); i++) {
            levelButtons[i].draw();
        }
        
        drawString(Vector2i(wd.x/2 - 120, wd.y/2), controls1, textColor);
        drawString(Vector2i(wd.x/2 - 150, wd.y/2 + 25), controls2, textColor);
        drawString(Vector2i(wd.x/2 - 140, wd.y/2 + 50), controls3, textColor);
        drawString(Vector2i(wd.x/2 - 100, wd.y/2 + 100), directions1, textColor);
        drawString(Vector2i(wd.x/2 - 220, wd.y/2 + 125), directions2, textColor);
    }

    void StartMenu::onMouseMove(int x, int y) {
        for (int i = 0; i < levelButtons.size(); i++) {
            if (!levelButtons[i].isHovered()) {
                if (levelButtons[i].isOverlapping(x, y)) {
                    levelButtons[i].setHovered(true);
                    levelButtons[i].onMouseEnter();
                }
            } else if (!levelButtons[i].isOverlapping(x, y)) {
                levelButtons[i].setHovered(false);
                levelButtons[i].onMouseLeave();
            }
        }
    }

    void StartMenu::onClick(int x, int y) {
        for (int i = 0; i < levelButtons.size(); i++) {
            if (levelButtons[i].isOverlapping(x, y)) {
                levelButtons[i].onClick();
            }
        }
    }

}
