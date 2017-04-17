#include "Score.h"

namespace game {
    
    const float Score::SCORE_POS_X = 5;
    const float Score::SCORE_POS_Y = 5;
    
    Score::Score() {
        score = 0;
        pos = Vector2f(SCORE_POS_X, SCORE_POS_Y);
        
    }
    
    Score::Score(int startScore){
        score = startScore;
        pos = Vector2f(SCORE_POS_X, SCORE_POS_Y);
    }
    
    int getScore() const {
        return score;
    }
    
    void updateScore(int newPoints) {
        score = score + newPoints;
    }
    
}
