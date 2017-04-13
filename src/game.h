#ifndef CS_120_FINAL_PROJECT_GAME_H
#define CS_120_FINAL_PROJECT_GAME_H

#include "entity/Entity.h"
#include "entity/Player.h"
#include <memory>
#include <vector>

typedef std::shared_ptr<game::Player> player_ptr;
typedef std::shared_ptr<game::Entity> entity_ptr;

namespace game {

    bool isRunning();

    void setRunning(bool running);

    player_ptr getPlayer();

    void updateEntities(std::vector<entity_ptr> &entities);

    void drawEntities(std::vector<entity_ptr> &entities);

}

#endif //CS_120_FINAL_PROJECT_GAME_H
