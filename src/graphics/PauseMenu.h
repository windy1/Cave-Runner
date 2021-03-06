#ifndef CS_120_FINAL_PROJECT_PAUSEMENU_H
#define CS_120_FINAL_PROJECT_PAUSEMENU_H

#include "Menu.h"

namespace game {

    /**
     * The menu displayed when the game is paused.
     */
    class PauseMenu : public Menu {
    public:

        virtual void draw() const override;

    };

}

#endif //CS_120_FINAL_PROJECT_PAUSEMENU_H
