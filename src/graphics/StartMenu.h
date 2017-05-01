#ifndef CS_120_FINAL_PROJECT_STARTMENU_H
#define CS_120_FINAL_PROJECT_STARTMENU_H

#include "Menu.h"

namespace game {

    /**
     * The menu displayed when the game is started.
     */
    class StartMenu : public Menu {
    public:

        virtual void draw() const override;

    };

}

#endif //CS_120_FINAL_PROJECT_STARTMENU_H
