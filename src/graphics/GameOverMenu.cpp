#include "GameOverMenu.h"
#include "graphics.h"

namespace game {

    const string GameOverMenu::VICTORY_MESSAGE  = "You win!";
    const string GameOverMenu::DEATH_MESSAGE    = "You are dead.";

    bool GameOverMenu::isVictory() const {
        return victory;
    }

    void GameOverMenu::setVictory(bool victory) {
        this->victory = victory;
    }

    void GameOverMenu::draw() const {
        Vector2i wd = getWindowDimensions();
        int xOff = victory ? -40 : -60;
        string msg1 = victory ? VICTORY_MESSAGE : DEATH_MESSAGE;
        string msg2 = "Click anywhere to return to the home screen";
        drawString(Vector2i(wd.x / 2 + xOff, wd.y / 3), msg1, textColor);
        drawString(Vector2i(wd.x / 2 - 200, wd.y / 3 + 30), msg2, textColor);
    }

}
