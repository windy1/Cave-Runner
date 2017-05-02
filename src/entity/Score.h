#ifndef CS_120_FINAL_PROJECT_SCORE_H
#define CS_120_FINAL_PROJECT_SCORE_H

#include "Entity.h"

namespace game {

    /**
     * The score display.
     */
    class Score : public Entity {

        int score;

    public:

        /// Default score display position
        static const Vector3f DEFAULT_POSITION;

        Score();

        Score(int startScore);

        /**
         * Requires: none
         * Modifies: none
         * Effects: returns the score's int value
         */
        int getScore() const;
        
        /**
         * Requires: nothing
         * Modifies: score
         * Effects: increments score by given amount
         */
        void updateScore(int newPoints);

        virtual string getType() const override;

        virtual void draw() const override;

    };
    
}


#endif //CS_120_FINAL_PROJECT_SCORE_H
