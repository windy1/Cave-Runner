#ifndef CS_120_FINAL_PROJECT_GRS_H
#define CS_120_FINAL_PROJECT_GRS_H

#include "../game.h"
#include <fstream>

namespace game {

    extern const string SECTION_ENTITIES;
    extern const string SECTION_PROPERTIES;

    void skipChars(ifstream &file, int amount, char &ch);

}

#endif //CS_120_FINAL_PROJECT_GRS_H
