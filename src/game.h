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

    enum page {menu, gameplay, pause, gameover};

    /**
     * Represents the current state of the game. Encapsulated for easily
     * writing/reading the game state to/from disk.
     */
    struct GameState {
        vector<entity_ptr>  entities;                   /// all entities currently in game
        player_ptr          player          = NULL;     /// a reference to the player
        score_ptr           score           = NULL;     /// a reference to the score
        checkpt_ptr         checkpoint      = NULL;     /// a reference to the currently set checkpoint, if any
        page                currentPage;                /// the current page being displayed
        int                 globalX;                    /// the current scroll x-position
        float               scrollSpeed;                /// pixel-rate of how quickly we scroll
        int                 level;                      /// current game level
        int                 endX;                       /// x-position where the current level ends
    };

    /**
     * Requires: none
     * Modifies: game state
     * Effects: resets the game state, loads a level, and starts the game
     */
    void startLevel(int level);

    /**
     * Requires: none
     * Modifies: save file
     * Effects: saves the current game state to file
     */
    void saveGame();

    /**
     * Requires: none
     * Modifies: save file
     * Effects: resumes the game from the last checkpoint
     */
    void resumeGame();

    /**
     * Requires: a valid level integer
     * Modifies: game state
     * Effects: loads the specified level into the game state
     */
    void loadLevel(int level);

    /**
     * Requires: none
     * Modifies: game state
     * Effects: creates and initializes the player entity
     */
    void createPlayer();

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
     * Requires: non-null entity
     * Modifies: entity vector
     * Effects: inserts the entity into the entity vector based on it's
     * z-position
     */
    void insertEntity(entity_ptr entity, vector<entity_ptr> &entities);

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
     * Modifies: none
     * Effects: return the ceiling y-position
     */
    int getCeilingY();
    
    /**
     * Requires: none
     * Modifies: none
     * Effects: return the scroll speed
     */
    float getScrollSpeed();

    int getTotalLevels();
    
    /**
     * Requires: none
     * Modifies: scroll speed
     * Effects: sets scroll speed
     */
    void setScrollSpeed(float newScrollSpeed);

    /**
     * Requires: none
     * Modifies: none
     * Effects: returns the current page that is being displayed.
     */
    page getCurrentPage();

    /**
     * Requires: none
     * Modifies: current page
     * Effects: sets the current page that is being displayed
     */
    void setCurrentPage(page newPage);

}

#endif //CS_120_FINAL_PROJECT_GAME_H
