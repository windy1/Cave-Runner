#ifndef CS_120_FINAL_PROJECT_GAMELOADER_H
#define CS_120_FINAL_PROJECT_GAMELOADER_H

#include "grs.h"

namespace game {

    /**
     * Handles reading saved games and levels from file.
     */
    class GameStateReader {

        int lineNum;
        string ln;
        ifstream file;
        GameState &gameState;
        float entityYOffset = 0;

        bool readEntities();

        bool readProperties();

    public:

        GameStateReader(GameState &gameState);

        ~GameStateReader();

        /**
         * Requires: none
         * Modifies: none
         * Effects: returns the default y-offset for entities
         */
        float getEntityYOffset() const;

        /**
         * Requires: none
         * Modifies: entity y-offset
         * Effects: sets the default y-offset for entities
         */
        void setEntityYOffset(float entityYOffset);

        /**
         * Requires: fileName not empty
         * Modifies: the given game state
         * Effects: reads the save file of the specified name into the given
         * game state
         */
        bool read(string fileName);

    };

}

#endif //CS_120_FINAL_PROJECT_GAMELOADER_H
