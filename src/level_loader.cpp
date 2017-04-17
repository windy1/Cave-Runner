#include "level_loader.h"
#include "entity/Barrier.h"
#include <fstream>

namespace game {

    static void skipChars(ifstream &file, int amount, char &ch);

    vector<entity_ptr> loadLevel(int level, int x) {
        cout << "Loading level " << level << endl;
        vector<entity_ptr> entities;

        // open file
        string fileName = "level_" + to_string(level) + ".txt";
        ifstream file(fileName);
        if (!file) {
            cout << "Error: Could not load level " << level << endl;
            return entities;
        }

        // read file, line by line. each line contains a new entity to place
        string ln;
        int lineNum = 1;
        bool success = true;
        do {
            // create entity
            entity_ptr entity;
            string entityName;
            file >> entityName;
            if (entityName == Entity::BARRIER) {
                entity = make_unique<Barrier>();
            } else {
                // unknown entity
                cout << "Error: Unknown entity type \"" << entityName << "\"";
                success = false;
                goto done;
            }

            // set dimensions
            int width = -1;
            int height = -1;
            char ch;
            file >> width;
            skipChars(file, 1, ch);
            file >> height;
            if (width == -1 || height == -1) {
                cout << "Error: Could not read entity dimensions";
                success = false;
                goto done;
            }
            entity->setDimensions(Vector2i(width, height));

            // set position
            int y = -1;
            skipChars(file, 2, ch);
            file >> y;
            if (y == -1) {
                cout << "Error: Could not read entity y-position";
                success = false;
                goto done;
            }
            entity->setPosition(Vector2f(x, y));

            // increment x counter
            int xInc = -1;
            skipChars(file, 3, ch);
            file >> xInc;
            if (xInc == -1) {
                cout << "Error: Could not read x-increment";
                success = false;
                goto done;
            }
            x += xInc;
            // print result
            cout << "- " << *entity << endl;
        } while (getline(file, ln));

        done:
        file.close();
        if (!success) {
            cout << " (failed on line " << lineNum << ")" << endl;
        }

        return entities;
    }

    static void skipChars(ifstream &file, int amount, char &ch) {
        for (int i = 0; i < amount; i++) {
            file >> ch;
            //cout << ch;
        }
        //cout << endl;
    }

}
