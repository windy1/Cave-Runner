#ifndef CS_120_FINAL_PROJECT_GRAPPLINGHOOK_H
#define CS_120_FINAL_PROJECT_GRAPPLINGHOOK_H

#include "../math.h"
#include "Entity.h"
#include "../ptr.h"

namespace game {

    /**
     * A grappling hook tool used by the player.
     */
    class GrapplingHook : public Entity {

        player_ptr player;
        bool hooked;
        Vector2f retractVelocity;

    protected:

        /// Overrides default "death" behavior and just unhooks instead
        virtual void onLeaveScreen() override;

    public:

        /// Defaults
        static const Vector2i DEFAULT_DIMENSIONS;
        static const Vector2f DEFAULT_RETRACT_VELOCITY;

        GrapplingHook(player_ptr player);

        /**
         * Requires: none
         * Modifies: none
         * Effects: returns the owning player of this grappling hook
         */
        player_ptr getPlayer() const;

        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects: checks if grappling hook is currently hooked onto an object
         */
        bool isHooked() const;

        /**
         * Requires: nothing
         * Modifies: hooked state
         * Effects: sets if the grappling hook is attached and should be drawn
         */
        void setHooked(bool hooked);

        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects: returns the velocity at which the grappling hook pulls the
         * player towards it
         */
        Vector2f getRetractVelocity() const;

        /**
         * Requires: nothing
         * Modifies: retract velocity
         * Effects: sets the velocity at which the grappling hook pulls the
         * player towards it
         */
        void setRetractVelocity(Vector2f retractVelocity);
        
        virtual string getType() const override;

        virtual void draw() const override;

    };

}

#endif //CS_120_FINAL_PROJECT_GRAPPLINGHOOK_H
