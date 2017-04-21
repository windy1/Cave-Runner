#ifndef CS_120_FINAL_PROJECT_POWERUP_H
#define CS_120_FINAL_PROJECT_POWERUP_H

#include "Collectible.h"
#include "../graphics/graphics.h"

namespace game {

    class PowerUp : public Collectible {
    public:

        // constructors
        
        PowerUp();

        // constructor with position parameter
        PowerUp(Vector3f pos);

        // get type
        virtual string getType() const override;

        /**
         * Requires: nothing
         * Modifies: powerup and player powerup field
         * Effects: powerup disappears from screen and player saves boolean access to powerup
         */
        virtual void becomeCollected(Player &player) override;
        
        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects: draws powerup as circle
         */
        virtual void draw() const override;

    };

}

#endif //CS_120_FINAL_PROJECT_POWERUP_H
