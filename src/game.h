#ifndef CS_120_FINAL_PROJECT_GAME_H
#define CS_120_FINAL_PROJECT_GAME_H

#include "entity/Entity.h"
#include "entity/Player.h"
#include <memory>

typedef std::shared_ptr<game::Player> player_ptr;
typedef std::shared_ptr<game::Entity> entity_ptr;

namespace game {

    bool isRunning();

    void setRunning(bool running);

    player_ptr getPlayer();

}

#endif //CS_120_FINAL_PROJECT_GAME_H
