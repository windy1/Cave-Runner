#ifndef CS_120_FINAL_PROJECT_SCENE_H
#define CS_120_FINAL_PROJECT_SCENE_H

#include "../math.h"
#include "Color.h"

namespace game {

    /**
     * The scene or "backdrop" of the game.
     */
    class Scene {

        Vector2i floorCeilDimen;
        Vector2i floorPos;
        Vector2i ceilPos;
        Color color;

    public:

        Scene();

        /**
         * Requires: none
         * Modifies: none
         * Effects: returns the dimensions of the floor and ceiling
         */
        Vector2i getDimensions() const;

        /**
         * Requires: none
         * Modifies: none
         * Effects: returns the position of the floor
         */
        Vector2i getFloorPosition() const;

        /**
         * Requires: none
         * Modifies: none
         * Effects: returns the position of the ceiling
         */
        Vector2i getCeilingPosition() const;

        /**
         * Requires: none
         * Modifies: none
         * Effects: returns the color of the floor and ceiling
         */
        Color getColor() const;

        /**
         * Requires: none
         * Modifies: none
         * Effects: draws the scene to the screen
         */
        void draw() const;

    };

}

#endif //CS_120_FINAL_PROJECT_SCENE_H
