#include "tests.h"
#include "game.h"
#include "entity/Coin.h"
#include <iostream>

using namespace std;

namespace game {

    // game.h
    int testUpdateEntities();

    // Entity.h
    int testEntityPosition();
    int testEntityVelocity();

    int runTests() {
        cout << "Running tests..." << endl;
        int failed = 0;
        failed += testUpdateEntities();
        failed += testEntityPosition();
        failed += testEntityVelocity();
        cout << "Done [failed " << failed << " tests]" << endl;
        return failed;
    }

    int testUpdateEntities() {
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

}
