#ifndef CS_120_FINAL_PROJECT_GAMESTATEWRITER_H
#define CS_120_FINAL_PROJECT_GAMESTATEWRITER_H

#include "grs.h"

namespace game {

    /**
     * Handles writing games to file.
     */
    class GameStateWriter {

        ofstream file;
        const GameState &gameState;

        void writeEntities();

        void writeProperties();

    public:

        GameStateWriter(const GameState &gameState);

        ~GameStateWriter();

        /**
         * Requires: fileName not empty
         * Modifies: the given file
         * Effects: writes the game state to the specified file
         */
        bool write(string fileName);

    };

}

#endif //CS_120_FINAL_PROJECT_GAMESTATEWRITER_H
