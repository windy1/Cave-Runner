#include "Score.h"

namespace game {
    
    const float Score::SCORE_POS_X = 5;
    const float Score::SCORE_POS_Y = 5;
    
    Score::Score() {
        score = 0;
        pos = Vector3f(SCORE_POS_X, SCORE_POS_Y, 0);
        
    }
    
    Score::Score(int startScore){
        score = startScore;
        pos = Vector3f(SCORE_POS_X, SCORE_POS_Y, 0);
    }
    
    int Score::getScore() const {
        return score;
    }
    
    void Score::updateScore(int newPoints) {
        score = score + newPoints;
    }

    string Score::getType() const {
        return SCORE;
    }

    void Score::draw() const {
        // TODO
    }

}
