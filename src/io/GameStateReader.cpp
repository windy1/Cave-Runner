#include "GameStateReader.h"

namespace game {

    GameStateReader::GameStateReader(GameState &gameState) : gameState(gameState) {
    }

    GameStateReader::~GameStateReader() {
        if (file.is_open()) {
            file.close();
        }
    }

    float GameStateReader::getEntityYOffset() const {
        return entityYOffset;
    }

    void GameStateReader::setEntityYOffset(float entityYOffset) {
        this->entityYOffset = entityYOffset;
    }

    bool GameStateReader::read(string fileName) {
        assert(!fileName.empty());

        cout << "Reading " << fileName << endl;

        // get file handle
        if (file.is_open()) {
            cerr << "File is opened" << endl;
            return false;
        }
        file = ifstream(fileName);
        if (!file) {
            cerr << "Could not open file: " << fileName << endl;
            return false;
        }

        // reset reader
        lineNum = 1;
        ln = "";
        this->gameState = gameState;

        // start reading
        bool success = true;
        while (getline(file, ln)) {
            if (ln == SECTION_PROPERTIES) {
                // read properties section
                success &= readProperties();
            }
            if (ln == SECTION_ENTITIES) {
                // read entity section
                success &= readEntities();
            }
        }
        
        file.close();

        return success;
    }

    bool GameStateReader::readEntities() {
        bool success = true;
        do {
            // construct entity
            entity_ptr entity;
            string entityName;
            file >> entityName;
            if (entityName == Entity::BARRIER) {
                entity = make_shared<Barrier>();
            } else if (entityName == Entity::COIN) {
                entity = make_shared<Coin>();
            } else if (entityName == Entity::POWER_UP) {
                entity = make_shared<PowerUp>();
            } else if (entityName == Entity::PLAYER) {
                if (gameState.player == NULL) {
                    cerr << "Player must be initialized before loading game state" << endl;
                    success = false;
                    continue;
                }
                entity = gameState.player;
            } else if (entityName == "" || entityName[0] == '[') {
                // done reading entities
                ln = entityName;
                return true;
            } else {
                // unknown entity
                cerr << "Unknown entity type: " << entityName << endl;
                success = false;
                continue;
            }

            // set dimensions
            Vector2i dimensions(-1, -1);
            char ch;
            file >> dimensions.x;
            skipChars(file, 1, ch);
            file >> dimensions.y;
            if (dimensions.x == -1 || dimensions.y == -1) {
                cerr << "Could not read entity dimensions" << endl;
                success = false;
                continue;
            }
            entity->setDimensions(dimensions);

            // set position
            Vector3f pos(-1, -1, 0);
            skipChars(file, 1, ch);
            file >> pos.x;
            skipChars(file, 1, ch);
            file >> pos.y;
            skipChars(file, 1, ch);
            file >> pos.z;
            if (pos.x == -1 || pos.y == -1) {
                cerr << "Could not read entity position" << endl;
                success = false;
                continue;
            }
            pos.y += entityYOffset; // move entities up to ground
            entity->setPosition(pos);

            // get color
            Color color(-1, -1, -1, -1);
            skipChars(file, 8, ch);
            file >> color.r;
            skipChars(file, 1, ch);
            file >> color.g;
            skipChars(file, 1, ch);
            file >> color.b;
            skipChars(file, 1, ch);
            file >> color.a;
            if (color.r == -1 || color.g == -1 || color.b == -1 || color.a == -1) {
                cerr << "Could not read color" << endl;
                success = false;
                continue;
            }
            entity->setColor(color);

            // add to game state
            if (entityName != Entity::PLAYER) {
                insertEntity(entity, gameState.entities);
            }
            cout << "- " << *entity << endl;
            lineNum++;
        } while (getline(file, ln));
        return success;
    }
    
    bool GameStateReader::readProperties() {
        // reset properties
        gameState.globalX = -1;
        gameState.scrollSpeed = -1;
        gameState.level = -1;

        // get global x-position
        char ch;
        skipChars(file, 8, ch);
        file >> gameState.globalX;
        if (gameState.globalX == -1) {
            cerr << "Could not read globalX" << endl;
            return false;
        }
        getline(file, ln);
        lineNum++;

        // get scroll speed
        skipChars(file, 12, ch);
        file >> gameState.scrollSpeed;
        if (gameState.scrollSpeed == -1) {
            cerr << "Could not read scrollSpeed" << endl;
            return false;
        }
        getline(file, ln);
        lineNum++;

        // get level
        skipChars(file, 6, ch);
        file >> gameState.level;
        if (gameState.level == -1) {
            cerr << "Could not read level" << endl;
            return false;
        }
        getline(file, ln);
        lineNum++;

        // get score
        skipChars(file, 6, ch);
        int score = -1;
        file >> score;
        if (gameState.score == NULL) {
            gameState.score = make_shared<Score>(score);
            insertEntity(gameState.score, gameState.entities);
        }
        if (gameState.score->getScore() == -1) {
            cerr << "Could not read score" << endl;
            return false;
        }
        gameState.score->updateScore(score);
        
        return true;
    }

}
