#ifndef CS_120_FINAL_PROJECT_LEVEL_LOADER_H
#define CS_120_FINAL_PROJECT_LEVEL_LOADER_H

#include "game.h"

namespace game {

    /**
     * Requires: level > 0
     * Modifies: the given entity vector
     * Effects: loads the specified level into the specified entity vector
     */
    bool loadLevel(int level, GameState &gameState);

    /**
     * Requires: none
     * Modifies: save file
     * Effects: saves the current game state to a single save file
     */
    bool saveGame(const GameState &gameState);

    /**
     * Requires: none
     * Modifies: the game state
     * Effects: loads the save file into the specified game state
     */
    bool loadGame(GameState &gameState);

}

#endif //CS_120_FINAL_PROJECT_LEVEL_LOADER_H
