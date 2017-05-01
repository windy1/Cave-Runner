#ifndef CS_120_FINAL_PROJECT_MENU_H
#define CS_120_FINAL_PROJECT_MENU_H

#include "Color.h"

namespace game {

    class Menu {
    protected:

        Color textColor;

    public:

        Menu();

        virtual void draw() const = 0;

    };

}

#endif //CS_120_FINAL_PROJECT_MENU_H
