#ifndef CS_120_FINAL_PROJECT_POWERUP_H
#define CS_120_FINAL_PROJECT_POWERUP_H

#include "../game.h"

namespace game {

    /**
     * A collectible that gives the player a special ability.
     */
    class PowerUp : public Collectible {
    public:

        PowerUp();

        PowerUp(Vector3f pos);

        /**
         * Requires: nothing
         * Modifies: powerup and player powerup field
         * Effects: powerup disappears from screen and player saves boolean access to powerup
         */
        virtual void becomeCollected(Player &player) override;

        virtual void draw() const override;

        virtual string getType() const override;

    };

}

#endif //CS_120_FINAL_PROJECT_POWERUP_H
