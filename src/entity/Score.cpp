#include "Score.h"
#include "../graphics/graphics.h"

namespace game {

    const Vector3f Score::DEFAULT_POSITION(5, 5, 0);

    Score::Score() {
        score = 0;
        pos = DEFAULT_POSITION;
        
    }
    
    Score::Score(int startScore) : Score() {
        score = startScore;
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
        drawString(Vector2i(50, 100), "SCORE: ", Color::WHITE);
        drawString(Vector2i(140, 100), to_string(getScore()), Color::WHITE);
    }
}
