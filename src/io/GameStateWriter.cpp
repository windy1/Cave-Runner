#include "GameStateWriter.h"

namespace game {

    GameStateWriter::GameStateWriter(const GameState &gameState) : gameState(gameState) {
    }

    GameStateWriter::~GameStateWriter() {
        if (file.is_open()) {
            file.close();
        }
    }

    bool GameStateWriter::write(string fileName) {
        assert(!fileName.empty());

        cout << "Writing " << fileName << endl;

        // get file handle
        if (file.is_open()) {
            cerr << "File is opened" << endl;
            return false;
        }
        file = ofstream(fileName);
        if (!file) {
            cerr << "Could not open file: " << fileName << endl;
            return false;
        }

        writeProperties();
        writeEntities();

        return true;
    }

    void GameStateWriter::writeEntities() {
        file << SECTION_ENTITIES << endl;
        const vector<entity_ptr> entities = *(&gameState.entities);
        for (int i = 0; i < entities.size(); i++) {
            entity_ptr entity = entities[i];
            Vector2i dimen = entity->getDimensions();
            Vector3f pos = entity->getPosition();
            Color color = entity->getColor();
            file << entity->getType() << " ";
            file << dimen.x << 'x' << dimen.y << " ";
            file << "(" << pos.x << "," << pos.y << "," << pos.z << ") ";
            file << "color={" << color.r << "," << color.g << "," << color.b << "," << color.a << "}";
            file << endl;
            cout << "- " << *entity << endl;
        }
    }

    void GameStateWriter::writeProperties() {
        file << SECTION_PROPERTIES << endl;
        file << "globalX=" << gameState.globalX << endl;
        file << "scrollSpeed=" << gameState.scrollSpeed << endl;
        file << "level=" << gameState.level << endl;
        file << "score=" << gameState.score->getScore() << endl;
    }

}
