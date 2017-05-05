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
        Color hookColor;
        float ropeWidth;

    protected:

        /// Overrides default "death" behavior and just unhooks instead
        virtual void onLeaveScreen() override;

    public:

        /// Defaults
        static const Vector2i   DEFAULT_DIMENSIONS;
        static const Vector2f   DEFAULT_RETRACT_VELOCITY;
        static const float      DEFAULT_ROPE_WIDTH = 5;

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

        /**
         * Requires: none
         * Modifies: none
         * Effects: returns the color of the hook
         */
        Color getHookColor() const;

        /**
         * Requires: none
         * Modifies: hook color
         * Effects: sets the color of the hook
         */
        void setHookColor(Color hookColor);

        /**
         * Requires: none
         * Modifies: none
         * Effects: sets the width of the rope
         */
        float getRopeWidth() const;

        /**
         * Requires: none
         * Modifies: rope width
         * Effects: sets the rope width
         */
        void setRopeWidth(float ropeWidth);
        
        virtual string getType() const override;

        virtual void draw() const override;

    };

}

#endif //CS_120_FINAL_PROJECT_GRAPPLINGHOOK_H
