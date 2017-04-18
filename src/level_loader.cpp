#include "level_loader.h"
#include "entity/Barrier.h"
#include <fstream>
#include <cassert>

namespace game {

    static void skipChars(ifstream &file, int amount, char &ch);

    void loadLevel(unsigned int level, unsigned int x, vector<entity_ptr> &entities) {
        assert(level > 0);
        cout << "Loading level " << level << endl;

        string fileName = "level_" + to_string(level) + ".txt";
        int lineNum = 1;
        bool success = true;
        string ln;

        // open file
        ifstream file(fileName);
        if (!file) {
            cout << "Error: Could not load level " << level << endl;
            goto done;
        }

        // read file, line by line. each line contains a new entity to place
        do {
            // create entity
            entity_ptr entity;
            string entityName;
            file >> entityName;
            if (entityName == Entity::BARRIER) {
                entity = make_shared<Barrier>();
            } else if (entityName == "") {
                goto done;
            } else {
                // unknown entity
                cout << "Error: Unknown entity type \"" << entityName << "\"";
                success = false;
                goto done;
            }

            // set dimensions
            Vector2i dimensions(-1, -1);
            char ch;
            file >> dimensions.x;
            skipChars(file, 1, ch);
            file >> dimensions.y;
            if (dimensions.x == -1 || dimensions.y == -1) {
                cout << "Error: Could not read entity dimensions";
                success = false;
                goto done;
            }
            entity->setDimensions(dimensions);

            // set position
            Vector2f pos(x, -1);
            skipChars(file, 2, ch);
            file >> pos.y;
            if (pos.y == -1) {
                cout << "Error: Could not read entity y-position";
                success = false;
                goto done;
            }
            entity->setPosition(pos);

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

            // get color
            Color color(-1, -1, -1, -1);
            skipChars(file, 7, ch);
            file >> color.r;
            skipChars(file, 1, ch);
            file >> color.g;
            skipChars(file, 1, ch);
            file >> color.b;
            skipChars(file, 1, ch);
            file >> color.a;
            if (color.r == -1 || color.g == -1 || color.b == -1 || color.a == -1) {
                cout << "Error: Could not read color";
                success = false;
                goto done;
            }
            entity->setColor(color);

            // add to vector
            entities.push_back(entity);
            cout << "- " << *entity << " | " << "color=" << color << endl;
            lineNum++;
        } while (getline(file, ln));

        done:
        file.close();
        if (!success) {
            cout << " (failed on line " << lineNum << ")" << endl;
        }
    }

    static void skipChars(ifstream &file, int amount, char &ch) {
        for (int i = 0; i < amount; i++) {
            file >> ch;
            //cout << ch;
        }
        //cout << endl;
    }

}
