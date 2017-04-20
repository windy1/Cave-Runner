#include "tests.h"
#include "game.h"
#include "entity/Coin.h"
#include "entity/Barrier.h"
#include "loader.h"
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

    // loader.h
    int testLoadLevel();
    int testSaveGame();
    int testLoadGame();

    // Barrier.h
    int testBarrierPointOverlap();
    int testBarrierPlayerOverlap();

    int runTests() {
        cout << "Running tests..." << endl;
        GameState testState;
        testState.globalX = 500;
        testState.scrollSpeed = 1;
        testState.level = 1;
        game::setGameState(testState);
        int failed = 0;
        failed += testUpdateEntities();
        failed += testEntityPosition();
        failed += testEntityVelocity();
        failed += testPlayerJump();
        failed += testObstacleScroll();
        failed += testBarrierPointOverlap();
        failed += testBarrierPlayerOverlap();
        failed += testLoadLevel();
        failed += testSaveGame();
        failed += testLoadGame();
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
    
    int testBarrierPointOverlap() {
        cout << "**** testBarrierPointOverlap() ****" << endl;
        Barrier barrier;
        Vector2f pos(50, 100);
        barrier.setPosition(pos);
        barrier.setDimensions(Vector2i(10, 20));
        int failed = 0;
        Vector2i overlap_point(55, 90);
        // barrier overlaps point
        if (!barrier.isOverlapping(overlap_point)) {
            cout << "unexpected barrier overlap determination: expect overlapping" << endl;
            cout << "barrier pos: " << pos << endl;
            cout << "barrier dimensions: " << barrier.getDimensions() << endl;
            cout << "point pos: " << overlap_point << endl;
            failed++;
        }
        Vector2i left_point(10, 90);
        // point to left of barrier
        if (barrier.isOverlapping(left_point)) {
            cout << "unexpected barrier overlap determination: expect left of barrier" << endl;
            cout << "barrier pos: " << pos << endl;
            cout << "barrier dimensions: " << barrier.getDimensions() << endl;
            cout << "point pos: " << left_point << endl;
            failed++;
        }
        Vector2i right_point(70, 90);
        // point to right of barrier
        if (barrier.isOverlapping(right_point)) {
            cout << "unexpected barrier overlap determination: expect right of barrier" << endl;
            cout << "barrier pos: " << pos << endl;
            cout << "barrier dimensions: " << barrier.getDimensions() << endl;
            cout << "point pos: " << right_point << endl;
            failed++;
        }
        Vector2i above_point(55, 75);
        // point above barrier
        if (barrier.isOverlapping(above_point)) {
            cout << "unexpected barrier overlap determination: expect above barrier" << endl;
            cout << "barrier pos: " << pos << endl;
            cout << "barrier dimensions: " << barrier.getDimensions() << endl;
            cout << "point pos: " << above_point << endl;
            failed++;
        }
        Vector2i below_point(55, 110);
        // point above barrier
        if (barrier.isOverlapping(below_point)) {
            cout << "unexpected barrier overlap determination below: expect below barrier" << endl;
            cout << "barrier pos: " << pos << endl;
            cout << "barrier dimensions: " << barrier.getDimensions() << endl;
            cout << "point pos: " << below_point << endl;
            failed++;
        }
        return failed;
    }
    
    int testBarrierPlayerOverlap() {
        cout << "**** testBarrierPlayerOverlap() ****" << endl;
        Barrier barrier;
        Vector2f barrier_pos(50, 100);
        barrier.setPosition(barrier_pos);
        barrier.setDimensions(Vector2i(10, 20)); //barrier points [(50,100), (60,100), (50, 80), (60,80)]
        int failed = 0;
        Player player;
        player.setDimensions(Vector2i(5, 5));
        player.setPosition(Vector2f(58, 82));
        // barrier overlaps bottom-left corner of player
        if (!barrier.isOverlapping(player)) {
            cout << "unexpected barrier overlap determination: expect overlapping" << endl;
            cout << "barrier pos: " << barrier_pos << endl;
            cout << "barrier dimensions: " << barrier.getDimensions() << endl;
            cout << "player pos: " << player.getPosition() << endl;
            cout << "player dimensions: " << player.getDimensions() << endl;
            failed++;
        }
        player.setPosition(Vector2f(48, 82));
        // barrier overlaps bottom-right corner of player
        if (!barrier.isOverlapping(player)) {
            cout << "unexpected barrier overlap determination: expect overlapping" << endl;
            cout << "barrier pos: " << barrier_pos << endl;
            cout << "barrier dimensions: " << barrier.getDimensions() << endl;
            cout << "player pos: " << player.getPosition() << endl;
            cout << "player dimensions: " << player.getDimensions() << endl;
            failed++;
        }
        player.setPosition(Vector2f(48, 102));
        // barrier overlaps top-right corner of player
        if (!barrier.isOverlapping(player)) {
            cout << "unexpected barrier overlap determination: expect overlapping" << endl;
            cout << "barrier pos: " << barrier_pos << endl;
            cout << "barrier dimensions: " << barrier.getDimensions() << endl;
            cout << "player pos: " << player.getPosition() << endl;
            cout << "player dimensions: " << player.getDimensions() << endl;
            failed++;
        }
        player.setPosition(Vector2f(58, 102));
        // barrier overlaps top-left corner of player
        if (!barrier.isOverlapping(player)) {
            cout << "unexpected barrier overlap determination: expect overlapping" << endl;
            cout << "barrier pos: " << barrier_pos << endl;
            cout << "barrier dimensions: " << barrier.getDimensions() << endl;
            cout << "player pos: " << player.getPosition() << endl;
            cout << "player dimensions: " << player.getDimensions() << endl;
            failed++;
        }
        return failed;
    }

    int testLoadLevel() {
        cout << "**** testLoadLevel() ****" << endl;
        loadLevel(1, *game::getGameState());
        vector<entity_ptr> *entities = &game::getGameState()->entities;
        for (int i = 0; i < entities->size(); i++) {
            cout << *(*entities)[i] << endl;
        }
        return 0;
    }

    int testSaveGame() {
        cout << "**** testSaveGame() ****" << endl;
        if (!saveGame(*game::getGameState())) {
            return 1;
        }
        return 0;
    }

    int testLoadGame() {
        cout << "**** testLoadGame() ****" << endl;
        GameState loadedState;
        if (!loadGame(loadedState)) {
            return 1;
        }
        for (int i = 0; i < loadedState.entities.size(); i++) {
            cout << *loadedState.entities[i] << endl;
        }
        cout << "globalX = " << loadedState.globalX << endl;
        cout << "scrollSpeed = " << loadedState.scrollSpeed << endl;
        return 0;
    }

}
