#ifndef CS_120_FINAL_PROJECT_POWERUP_H
#define CS_120_FINAL_PROJECT_POWERUP_H

#include "Collectible.h"

namespace game {

    class PowerUp : public Collectible {
    public:

        //default constructor
        PowerUp();
        
        //constructor with position parameter
        PowerUp(Vector2f pos);
        
        /**
         * Requires: nothing
         * Modifies: powerup and player powerup field
         * Effects: powerup disappears from screen and player saves boolean access to powerup
         */
        virtual void becomeCollected(Player &player) override;
        
        virtual void draw() const override;

    };

}

#endif //CS_120_FINAL_PROJECT_POWERUP_H
