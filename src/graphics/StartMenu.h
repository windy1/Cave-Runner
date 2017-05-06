#ifndef CS_120_FINAL_PROJECT_STARTMENU_H
#define CS_120_FINAL_PROJECT_STARTMENU_H

#include "graphics.h"
#include "../game.h"
#include "Menu.h"
#include "LevelButton.h"

namespace game {

    /**
     * The menu displayed when the game is started.
     */
    class StartMenu : public Menu {

        vector<LevelButton> levelButtons;

    public:

        StartMenu();

        virtual void draw() const override;

        void onMouseMove(int x, int y);

        void onClick(int x, int y);

    };

}

#endif //CS_120_FINAL_PROJECT_STARTMENU_H
