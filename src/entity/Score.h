#ifndef CS_120_FINAL_PROJECT_SCORE_H
#define CS_120_FINAL_PROJECT_SCORE_H

#include "Entity.h"

namespace game {
    
    class Score : public Entity {

        int score;

    public:

        // default score display position
        static const float SCORE_POS_X;
        static const float SCORE_POS_Y;
        
        // default constructor
        Score();

        // constructor with score value parameter
        Score(int startScore);
        
        int getScore() const;
        
        /**
         * Requires: nothing
         * Modifies: score
         * Effects: increments score by given amount
         */
        void updateScore(int newPoints);

        virtual void draw() const override;

    };
    
}


#endif //CS_120_FINAL_PROJECT_SCORE_H

