#ifndef CS_120_FINAL_PROJECT_GRAPPLINGHOOK_H
#define CS_120_FINAL_PROJECT_GRAPPLINGHOOK_H

#include "../math.h"
#include "Entity.h"

namespace game {

    class GrapplingHook : public Entity {

        bool hooked;
        bool shot;
        Vector2f retractVelocity;

    protected:

        virtual void onLeaveScreen() override;

    public:

        GrapplingHook();

        /**
         * Requires: grappling hook is not being shot already
         * Modifies: grappling hook pos, isShot boolean, isHooked boolean
         * Effects: grappling hook pos updates towards selected target, stops on object if ever overlaps object on way to target until player reaches target
         */
        void shoot(Vector2f target);

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
         * Requires: nothing
         * Modifies: nothing
         * Effects: checks if grappling hook is currently being shot
         */
        bool isShot() const;
        
        // get type
        virtual string getType() const override;
        
        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects: draws grappling hook as circle
         */
        virtual void draw() const override;

    };

}

#endif //CS_120_FINAL_PROJECT_GRAPPLINGHOOK_H
