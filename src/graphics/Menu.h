#ifndef CS_120_FINAL_PROJECT_MENU_H
#define CS_120_FINAL_PROJECT_MENU_H

#include "Color.h"

namespace game {

    /**
     * A game menu to display.
     */
    class Menu {
    protected:

        Color textColor;

    public:

        Menu();

        /**
         * Requires: none
         * Modifies: none
         * Effects: draws this menu to the screen
         */
        virtual void draw() const = 0;

    };

}

#endif //CS_120_FINAL_PROJECT_MENU_H
