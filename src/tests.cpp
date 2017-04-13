#include "tests.h"
#include "game.h"
#include "entity/Coin.h"
#include <iostream>

using namespace std;

namespace game {

    int testUpdateEntities();

    int runTests() {
        cout << "Running tests..." << endl;
        int failed = 0;
        failed += testUpdateEntities();
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

}
