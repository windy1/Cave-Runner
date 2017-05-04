#ifndef CS_120_FINAL_PROJECT_PTR_H
#define CS_120_FINAL_PROJECT_PTR_H

#include <memory>

using namespace std;

namespace game {

    class Entity;
    class Player;
    class Score;
    class GrapplingHook;
    class Checkpoint;

    typedef shared_ptr<Player>          player_ptr;
    typedef shared_ptr<Entity>          entity_ptr;
    typedef shared_ptr<Score>           score_ptr;
    typedef shared_ptr<GrapplingHook>   hook_ptr;
    typedef shared_ptr<Checkpoint>      checkpt_ptr;

}

#endif //CS_120_FINAL_PROJECT_PTR_H
