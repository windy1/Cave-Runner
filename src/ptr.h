#ifndef CS_120_FINAL_PROJECT_PTR_H
#define CS_120_FINAL_PROJECT_PTR_H

#include <memory>
#include "entity/GrapplingHook.h"

using namespace std;

namespace game {

    class Entity;
    class Player;
    class Score;

    typedef shared_ptr<Player>          player_ptr;
    typedef shared_ptr<Entity>          entity_ptr;
    typedef shared_ptr<Score>           score_ptr;
    typedef shared_ptr<GrapplingHook>   hook_ptr;

}

#endif //CS_120_FINAL_PROJECT_PTR_H
