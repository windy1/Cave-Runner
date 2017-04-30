#ifndef CS_120_FINAL_PROJECT_GAME_H
#define CS_120_FINAL_PROJECT_GAME_H

#include <memory>
#include <vector>
#include <iostream>
#include <cassert>
#include "ptr.h"
#include "entity/Entity.h"
#include "entity/Barrier.h"
#include "entity/Coin.h"
#include "entity/Collectible.h"
#include "entity/GrapplingHook.h"
#include "entity/Obstacle.h"
#include "entity/Player.h"
#include "entity/PowerUp.h"
#include "entity/Score.h"
#include "entity/Torch.h"

using namespace std;

namespace game {

    struct GameState {
        player_ptr          player;
        vector<entity_ptr>  entities;
        score_ptr           score;
        int                 globalX;
        int                 scrollSpeed;
        int                 level;
    };

    /**
     * Requires: none
     * Modifies: none
     * Effects: returns the player
     */
    player_ptr getPlayer();

    /**
     * Requires: non-null entity
     * Modifies: entity vector
     * Effects: inserts the entity into the entity vector based on it's
     * z-position
     */
    void insertEntity(entity_ptr entity, vector<entity_ptr> &entities);

    /**
     * Requires: none
     * Modifies: none
     * Effects: returns the current game state
     */
    GameState* getGameState();

    /**
     * Requires: none
     * Modifies: the global game state
     * Effects: sets the global game state
     */
    void setGameState(GameState gameState);

    /**
     * Requires: none
     * Modifies: none
     * Effects: returns true if the game is paused
     */
    bool isPaused();

    /**
     * Requires: none
     * Modifies: paused state
     * Effects: sets whether the game is paused
     */
    void setPaused(bool paused);

    /**
     * Requires: none
     * Modifies: none
     * Effects: returns the ground y-position
     */
    int getGroundY();

    /**
     * Requires: none
     * Modifies: updates game elements
     * Effects: game entities
     */
    void update();

    /**
     * Requires: none
     * Modifies: none
     * Effects: draws game elements
     */
    void draw();

    /**
     * Requires: a vector of entities
     * Modifies: removes any dead entities and updates any alive entities
     * Effects: the given entity vector
     */
    void updateEntities(std::vector<entity_ptr> &entities);

    /**
     * Requires: a vector of entities
     * Modifies: draws each entity to the screen
     * Effects: none
     */
    void drawEntities(const std::vector<entity_ptr> &entities);

}

#endif //CS_120_FINAL_PROJECT_GAME_H
