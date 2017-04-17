#ifndef CS_120_FINAL_PROJECT_SCORE_H
#define CS_120_FINAL_PROJECT_SCORE_H

#include "Entity.h"

namespace game {
    
    class Score : public Entity {
        
    public:
        
        //default constructor
        Score();
        //constructor with score value parameter
        Score(int startScore);
        
        //getter
        int getScore() const;
        
        /**
         * Requires: nothing
         * Modifies: score
         * Effects: increments score by given amount
         */
        void updateScore(int newPoints);
        
        //default score display position
        static const float SCORE_POS_X;
        static const float SCORE_POS_Y;
        
    private:
        
        int score;
        
    };
    
}


#endif //CS_120_FINAL_PROJECT_SCORE_H

