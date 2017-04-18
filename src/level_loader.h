#ifndef CS_120_FINAL_PROJECT_LEVEL_LOADER_H
#define CS_120_FINAL_PROJECT_LEVEL_LOADER_H

#include "game.h"

namespace game {

    /**
     * Requires: level > 0
     * Modifies: the given entity vector
     * Effects: loads the specified level into the specified entity vector
     * starting at the specified x-position
     */
    void loadLevel(unsigned int level, unsigned int x, vector<entity_ptr> &entities);

}

#endif //CS_120_FINAL_PROJECT_LEVEL_LOADER_H
