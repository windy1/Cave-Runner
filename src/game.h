#ifndef CS_120_FINAL_PROJECT_GAME_H
#define CS_120_FINAL_PROJECT_GAME_H

#include "entity/Entity.h"
#include "entity/Player.h"
#include <memory>
#include <vector>

typedef std::shared_ptr<game::Player> player_ptr;
typedef std::shared_ptr<game::Entity> entity_ptr;

struct GameState {
    player_ptr          player;
    vector<entity_ptr>  entities;
    int                 globalX;
    int                 scrollSpeed;
    int                 level;
};

namespace game {

    /**
     * Requires: none
     * Modifies: none
     * Effects: returns the player
     */
    player_ptr getPlayer();

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
     * Modifies: updates and draws game entities
     * Effects: game entities
     */
    void update();

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
