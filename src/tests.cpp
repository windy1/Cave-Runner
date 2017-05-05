#include "game.h"
#include "io/GameStateReader.h"
#include "io/GameStateWriter.h"

namespace game {

    // game.h
    int testUpdateEntities();
    int testInsertEntity();

    // Entity.h
    int testEntityPosition();
    int testEntityVelocity();

    // Player.h
    int testPlayerJump();

    // Obstacle.h
    int testObstacleScroll();
    
    // Coin.h
    int testCoinBecomeCollected();
    
    // PowerUp.h
    int testPowerUpBecomeCollected();
    
    // GameStateReader.h
    int testGameStateIO();

    int runTests() {
        cout << "Running tests..." << endl;
        GameState testState;
        testState.globalX = 500;
        testState.scrollSpeed = 42;
        testState.level = 13;
        testState.score = make_shared<Score>();
        testState.score->updateScore(1337);
        setGameState(testState);
        int failed = 0;
        failed += testUpdateEntities();
        failed += testInsertEntity();
        failed += testEntityPosition();
        failed += testEntityVelocity();
        failed += testPlayerJump();
        failed += testObstacleScroll();
        failed += testCoinBecomeCollected();
        failed += testPowerUpBecomeCollected();
        failed += testGameStateIO();
        cout << "Done [failed " << failed << " tests]" << endl;
        return failed;
    }

    int testUpdateEntities() {
        cout << "**** testUpdateEntities() ****" << endl;
        vector<entity_ptr> entities;
        player_ptr player = make_shared<Player>();
        entities.push_back(player);
        entities.push_back(make_shared<Coin>(player));
        player_ptr e3 = make_shared<Player>();
        e3->setDead(true);
        entities.push_back(e3);
        updateEntities(entities);
        for (int i = 0; i < entities.size(); i++) {
            if (entities[i] == e3) {
                return 1;
            }
        }
        return 0;
    }

    int testInsertEntity() {
        cout << "**** testInsertEntity() ****" << endl;
        int failed = 0;
        player_ptr player = make_shared<Player>();
        vector<entity_ptr> entities;
        entity_ptr e1 = make_shared<Barrier>(player, Vector3f(0, 0, 1));
        entity_ptr e2 = make_shared<Barrier>(player, Vector3f(0, 0, 1));
        entity_ptr e3 = make_shared<Barrier>(player, Vector3f(0, 0, 0));
        entity_ptr e4 = make_shared<Barrier>(player, Vector3f(0, 0, 0));
        entity_ptr e5 = make_shared<Barrier>(player, Vector3f(0, 0, 2));
        insertEntity(e1, entities);
        insertEntity(e2, entities);
        insertEntity(e3, entities);
        insertEntity(e4, entities);
        insertEntity(e5, entities);

        for (int i = 0; i < entities.size(); i++) {
            cout << "- " << *entities[i] << endl;
        }

        if (entities[0] != e3) {
            cerr << "unexpected entity index for e3" << endl;
            failed++;
        }
        if (entities[1] != e4) {
            cerr << "unexpected entity index for e4" << endl;
            failed++;
        }
        if (entities[2] != e1) {
            cerr << "unexpected entity index for e1" << endl;
            failed++;
        }
        if (entities[3] != e2) {
            cerr << "unexpected entity index for e2" << endl;
            failed++;
        }
        if (entities[4] != e5) {
            cerr << "unexpected entity index for e5" << endl;
            failed++;
        }
        return failed;
    }

    int testEntityPosition() {
        cout << "**** testEntityPosition() ****" << endl;
        Player entity;
        Vector3f pos(0, 0, 0);
        entity.setPosition(pos);
        int failed = 0;
        if (entity.getPosition() != pos) {
            cout << "unexpected entity position" << endl;
            failed++;
        }
        entity.move(10, 20);
        if (Vector2f(10, 20) != entity.getPosition()) {
            cout << "unexpected entity position after move" << endl;
            failed++;
        }
        return failed;
    }

    int testEntityVelocity() {
        cout << "**** testEntityVelocity() ****" << endl;
        Coin entity(make_shared<Player>());
        Vector2f velocity(420, 1337);
        entity.setVelocity(velocity);
        int failed = 0;
        if (entity.getVelocity() != velocity) {
            cout << "unexpected entity velocity" << endl;
            failed++;
        }
        entity.update();
        if (Vector2f(420, 1337) != entity.getPosition()) {
            cout << "unexpected entity position after velocity update" << endl;
            failed++;
        }
        return failed;
    }

    int testPlayerJump() {
        cout << "**** testPlayerJump() ****" << endl;
        Player player;
        player.jump();
        do {
            player.update();
            cout << player.getPosition() << endl;
        } while (player.getPosition().y > getGroundY());
        return 0;
    }

    int testObstacleScroll() {
        cout << "**** testObstacleScroll() ****" << endl;
        player_ptr player = make_shared<Player>();
        Barrier barrier(player, Vector3f(100, 50, 0));
        do {
            barrier.update();
            cout << barrier.getPosition() << endl;
        } while (barrier.getPosition().x > 0);
        return 0;
    }

    int testCoinBecomeCollected() {
        cout << "**** testCoinBecomeCollected() ****" << endl;
        player_ptr player = make_shared<Player>();
        Coin coin(player);
        getGameState()->score = make_shared<Score>();
        coin.becomeCollected(*player);
        int failed = 0;
        // if coin not dead, test fails
        if (!coin.isDead()) {
            cout << "coin should be dead after collection" << endl;
            failed++;
        }
        // if score not incremented, test fails
        if (getGameState()->score->getScore() != Coin::COIN_VALUE) {
            cout << "coin collection should increment score by coin value" << endl;
            failed++;
        }
        return failed;
    }

    int testPowerUpBecomeCollected() {
        cout << "**** testPowerUpBecomeCollected() ****" << endl;
        player_ptr player = make_shared<Player>();
        PowerUp powerUp(player);
        powerUp.becomeCollected(*player);
        int failed = 0;
        // if powerup not dead, test fails
        if (!powerUp.isDead()) {
            cout << "powerUp should be dead after collection" << endl;
            failed++;
        }
        // player does not have powerUp, test fails
        if (!player->hasPowerUp()) {
            cout << "player should have powerUp access after powerUp collection" << endl;
            failed++;
        }
        return failed;
    }
    
    int testGameStateIO() {
        cout << "**** testGameStateIO() ****" << endl;

        GameState gameState;
        GameStateReader reader(gameState);
        if (!reader.read("level_1.grs")) {
            return 1;
        }
        for (int i = 0; i < gameState.entities.size(); i++) {
            cout << *gameState.entities[i] << endl;
        }
        cout << "globalX = " << gameState.globalX << endl;
        cout << "scrollSpeed = " << gameState.scrollSpeed << endl;
        cout << "level = " << gameState.level << endl;
        cout << "score = " << gameState.score->getScore() << endl;

        GameStateWriter writer(gameState);
        if (!writer.write("level_1.test.grs")) {
            return 1;
        }

        return 0;
    }

}
