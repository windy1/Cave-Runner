#include "grs.h"

namespace game {

    const string SECTION_ENTITIES   = "[Entities]";
    const string SECTION_PROPERTIES = "[Properties]";

    void skipChars(ifstream &file, int amount, char &ch) {
        for (int i = 0; i < amount; i++) {
            file >> ch;
            //cout << ch;
        }
        //cout << endl;
    }

}
