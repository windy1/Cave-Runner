#ifndef CS_120_FINAL_PROJECT_GAMEOVERMENU_H
#define CS_120_FINAL_PROJECT_GAMEOVERMENU_H

#include "Menu.h"

namespace game {

    /**
     * The menu displayed when a level has completed.
     */
    class GameOverMenu : public Menu {

        bool victory;

    public:

        static const string VICTORY_MESSAGE;
        static const string DEATH_MESSAGE;

        /**
         * Requires: none
         * Modifies: none
         * Effects: returns true if the victory message should be displayed
         */
        bool isVictory() const;

        /**
         * Requires: none
         * Modifies: victory status
         * Effects: sets whether the victory message should be displayed
         */
        void setVictory(bool victory);

        virtual void draw() const override;

    };

}

#endif //CS_120_FINAL_PROJECT_GAMEOVERMENU_H
