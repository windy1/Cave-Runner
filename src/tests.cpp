#include "tests.h"
#include "game.h"
#include "entity/Coin.h"
#include "entity/Barrier.h"
#include "level_loader.h"
#include <iostream>

using namespace std;

namespace game {

    // game.h
    int testUpdateEntities();

    // Entity.h
    int testEntityPosition();
    int testEntityVelocity();

    // Player.h
    int testPlayerJump();

    // Obstacle.h
    int testObstacleScroll();

    // level_loader.h
    int testLoadLevel();

    int runTests() {
        cout << "Running tests..." << endl;
        int failed = 0;
        failed += testUpdateEntities();
        failed += testEntityPosition();
        failed += testEntityVelocity();
        failed += testPlayerJump();
        failed += testObstacleScroll();
        failed += testLoadLevel();
        cout << "Done [failed " << failed << " tests]" << endl;
        return failed;
    }

    int testUpdateEntities() {
        cout << "**** testUpdateEntities() ****" << endl;
        vector<entity_ptr> entities;
        entities.push_back(make_shared<Player>());
        entities.push_back(make_shared<Coin>());
        player_ptr e3 = make_shared<Player>();
        e3->setDead(true);
        entities.push_back(e3);
        game::updateEntities(entities);
        for (int i = 0; i < entities.size(); i++) {
            if (entities[i] == e3) {
                return 1;
            }
        }
        return 0;
    }

    int testEntityPosition() {
        cout << "**** testEntityPosition() ****" << endl;
        Coin entity;
        Vector2f pos(0, 0);
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
        Coin entity;
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
        } while (player.getPosition().y > 0);
        return 0;
    }

    int testObstacleScroll() {
        cout << "**** testObstacleScroll() ****" << endl;
        Barrier barrier(Vector2f(100, 50));
        do {
            barrier.update();
            cout << barrier.getPosition() << endl;
        } while (barrier.getPosition().x > 0);
        return 0;
    }

    int testLoadLevel() {
        cout << "**** testLoadLevel() ****" << endl;
        vector<entity_ptr> entities;
        loadLevel(1, 100, entities);
        for (int i = 0; i < entities.size(); i++) {
            cout << *entities[i] << endl;
        }
        return 0;
    }

}
