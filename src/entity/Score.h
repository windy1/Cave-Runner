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
        
        // constructors
        
        Score();

        Score(int startScore);
        
        // get score
        int getScore() const;
        
        /**
         * Requires: nothing
         * Modifies: score
         * Effects: increments score by given amount
         */
        void updateScore(int newPoints);

        // get type
        virtual string getType() const override;

        /**
         * Requires: nothing
         * Modifies: nothing
         * Effects: draws score as string
         */
        virtual void draw() const override;

    };
    
}


#endif //CS_120_FINAL_PROJECT_SCORE_H
