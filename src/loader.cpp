#include "game.h"
#include "loader.h"
#include <fstream>

namespace game {

    static const string FILE_SAVE           = "save.txt";       /// file to save game state to
    static const string SECTION_ENTITIES    = "[Entities]";     /// section in save file that has entities
    static const string SECTION_PROPERTIES  = "[Properties]";   /// section in save file that has game properties

    /// skips the next 'amount' of chars in the given file stream into the specified char
    static void skipChars(ifstream &file, int amount, char &ch);


    /* -- Internal functions of loader -- */

    /**
     * Reads the game state in the given file into the given game state
     * reference.
     */
    static bool readGameState(string fileName, GameState &gameState, bool saveFile = false);

    /**
     * Reads the next entity in the stream into the given ptr. Returns true if
     * should continue to read more entities. Sets success to false if there
     * is an error. Updates ln as it reads new lines.
     */
    static bool readEntity(ifstream &in, entity_ptr &entity, bool &success, string &ln);

    /**
     * Attempts to read all entities until end or next section in the stream.
     * Returns true if successful. Increments lineNum and updates ln as it
     * reads new lines.
     */
    static bool readEntities(ifstream &in, vector<entity_ptr> &entities, int &lineNum, string &ln);

    /**
     * Writes the given entity to the stream.
     */
    static void writeEntity(ofstream &out, const entity_ptr &entity);

    /**
     * Reads the properties of the given game state from the given stream.
     */
    static bool readProperties(ifstream &in, GameState &gameState, int &lineNum);

    /**
     * Writes the properties of the given game state to the given stream.
     */
    static void writeProperties(ofstream &out, const GameState &gameState);


    /* -- External definitions -- */

    bool loadLevel(int level, GameState &gameState) {
        assert(level > 0);
        cout << "Loading level " << level << endl;
        string fileName = "level_" + to_string(level) + ".txt";
        if (!readGameState(fileName, gameState)) {
            cerr << "Error: Could not load level " << level << endl;
            return false;
        }
        return true;
    }

    bool saveGame(const GameState &gameState) {
        cout << "Saving game..." << endl;

        ofstream file(FILE_SAVE);
        if (!file) {
            cerr << "Error: Could not open save file." << endl;
            return false;
        }

        // write entities
        file << SECTION_ENTITIES << endl;
        const vector<entity_ptr> *entities = &gameState.entities;
        for (int i = 0; i < entities->size(); i++) {
            writeEntity(file, (*entities)[i]);
        }

        // write properties
        file << SECTION_PROPERTIES << endl;
        writeProperties(file, gameState);

        return true;
    }

    bool loadGame(GameState &gameState) {
        if (!readGameState(FILE_SAVE, gameState, true)) {
            cerr << "Error: Could not open save file" << endl;
            return false;
        }
        return true;
    }


    /* -- Internal definitions -- */

    bool readGameState(string fileName, GameState &gameState, bool saveFile) {
        // get file handle
        ifstream file(fileName);
        if (!file) {
            return false;
        }

        int lineNum = 1;
        string ln;
        bool success = true;
        while (getline(file, ln)) {
            if (ln == SECTION_ENTITIES) {
                // read entity section
                success = readEntities(file, gameState.entities, lineNum, ln);
                if (!success) {
                    break;
                }

                // read properties
                if (ln == SECTION_PROPERTIES) {
                    success = readProperties(file, gameState, lineNum);
                    if (!success) {
                        break;
                    }

                    if (saveFile) {
                        getline(file, ln);
                        lineNum++;
                        char ch;
                        skipChars(file, 6, ch);
                        int score = -1;
                        file >> score;
                        cout << "s = " << score << endl;
                        if (gameState.score == NULL) {
                            gameState.score = make_shared<Score>(score);
                        }
                        if (gameState.score->getScore() == -1) {
                            cerr << "Error: Could not read score";
                            return false;
                        }
                        gameState.score->updateScore(score);
                    }
                }
            }
        }

        file.close();
        if (!success) {
            cerr << " (failed on line " << lineNum << ")" << endl;
        }

        return true;
    }

    bool readEntities(ifstream &in, vector<entity_ptr> &entities, int &lineNum, string &ln) {
        bool success = true;
        do {
            entity_ptr entity;
            bool finished = readEntity(in, entity, success, ln);
            if (finished) {
                return success;
            }
            entities.push_back(entity);
            cout << "- " << *entity << endl;
            lineNum++;
        } while (getline(in, ln));
        return success;
    }

    bool readEntity(ifstream &in, entity_ptr &entity, bool &success, string &ln) {
        string entityName;
        in >> entityName;
        if (entityName == Entity::BARRIER) {
            entity = make_shared<Barrier>();
        } else if (entityName == Entity::COIN) {
            entity = make_shared<Coin>();
        } else if (entityName == "" || entityName[0] == '[') {
            ln = entityName;
            return true;
        } else {
            // unknown entity
            cerr << "Error: Unknown entity type \"" << entityName << "\"";
            success = false;
            return true;
        }

        // set dimensions
        Vector2i dimensions(-1, -1);
        char ch;
        in >> dimensions.x;
        skipChars(in, 1, ch);
        in >> dimensions.y;
        if (dimensions.x == -1 || dimensions.y == -1) {
            cerr << "Error: Could not read entity dimensions";
            success = false;
            return true;
        }
        entity->setDimensions(dimensions);

        // set position
        Vector3f pos(-1, -1, 0);
        skipChars(in, 1, ch);
        in >> pos.x;
        skipChars(in, 1, ch);
        in >> pos.y;
        if (pos.x == -1 || pos.y == -1) {
            cerr << "Error: Could not read entity position";
            success = false;
            return true;
        }
        pos.y += getGroundY(); // move entities up to ground
        entity->setPosition(pos);

        // get color
        Color color(-1, -1, -1, -1);
        skipChars(in, 8, ch);
        in >> color.r;
        skipChars(in, 1, ch);
        in >> color.g;
        skipChars(in, 1, ch);
        in >> color.b;
        skipChars(in, 1, ch);
        in >> color.a;
        cout << "color = " << color << endl;
        if (color.r == -1 || color.g == -1 || color.b == -1 || color.a == -1) {
            cerr << "Error: Could not read color";
            success = false;
            return true;
        }
        entity->setColor(color);
        return false;
    }

    void writeEntity(ofstream &out, const entity_ptr &entity) {
        Vector2i dimen = entity->getDimensions();
        Vector2f pos = entity->getPosition();
        Color color = entity->getColor();
        out << entity->getType() << " ";
        out << dimen.x << 'x' << dimen.y << " ";
        out << "(" << pos.x << "," << pos.y << ") ";
        out << "color={" << color.r << "," << color.g << "," << color.b << "," << color.a << "}";
        out << endl;
        cout << "- " << *entity << endl;
    }

    bool readProperties(ifstream &in, GameState &gameState, int &lineNum) {
        gameState.globalX = -1;
        gameState.scrollSpeed = -1;
        gameState.level = -1;
        char ch;
        string ln;

        skipChars(in, 8, ch);
        in >> gameState.globalX;
        if (gameState.globalX == -1) {
            cerr << "Error: Could not read globalX";
            return false;
        }
        getline(in, ln);
        lineNum++;

        skipChars(in, 12, ch);
        in >> gameState.scrollSpeed;
        if (gameState.scrollSpeed == -1) {
            cerr << "Error: Could not read scrollSpeed";
            return false;
        }
        getline(in, ln);
        lineNum++;

        skipChars(in, 6, ch);
        in >> gameState.level;
        if (gameState.level == -1) {
            cerr << "Error: Could not read level";
            return false;
        }

        return true;
    }

    void writeProperties(ofstream &out, const GameState &gameState) {
        out << "globalX=" << gameState.globalX << endl;
        out << "scrollSpeed=" << gameState.scrollSpeed << endl;
        out << "level=" << gameState.level << endl;
        out << "score=" << gameState.score->getScore() << endl;
    }

    void skipChars(ifstream &file, int amount, char &ch) {
        for (int i = 0; i < amount; i++) {
            file >> ch;
            //cout << ch;
        }
        //cout << endl;
    }

}
