#include "Barrier.h"
#include "../game.h"

namespace game {

    Barrier::Barrier() : Obstacle::Obstacle() {
    }

    Barrier::Barrier(Vector3f pos) : Obstacle::Obstacle(pos) {
    }

    bool Barrier::isOverlapping(float xIn, float yIn) const {
        //getPosition returns bottom left point of barrier
        if (xIn < getPosition().x) {
            // out of bounds to the left of the rectangle
            return false;
        }
        if (xIn > getPosition().x + getDimensions().x) {
            // out of bounds to the right of the rectangle
            return false;
        }
        if (yIn < getPosition().y - getDimensions().y) {
            // out of bounds above the rectangle
            return false;
        }
        if (yIn > getPosition().y) {
            // out of bounds below the rectangle
            return false;
        }
        return true;
    }
    
    bool Barrier::isOverlapping(Vector2i point) const {
        if (isOverlapping(point.x, point.y)) {
            return true;
        }
        return false;
    }
    
    bool Barrier::isOverlapping(const Player &player) const {
        /*
         WTF
        cout << "Player top-left: " << player.getPosition() << endl;
        cout << "Player top-right: " << Vector2f(player.getPosition().x + player.getDimensions().x, player.getPosition().y) << endl;
        cout << "Player bot-right: " << Vector2f(player.getPosition().x + player.getDimensions().x, player.getPosition().y - player.getDimensions().y) << endl;
        cout << "Player bot-left: " << Vector2f(player.getPosition().x, player.getPosition().y - player.getDimensions().y) << endl;
        */
        if (isOverlapping(player.getPosition().x, player.getPosition().y)) {
            // top-left corner of player overlaps barrier
            cout << "top-left of player overlaps" << endl;
            return true;
        }
        if (isOverlapping(player.getPosition().x + player.getDimensions().x, player.getPosition().y)) {
            // top-right corner of player overlaps barrier
            cout << "top-right of player overlaps" << endl;
            return true;
        }
        if (isOverlapping(player.getPosition().x + player.getDimensions().x, player.getPosition().y - player.getDimensions().y)) {
            // bot-right corner of player overlaps barrier
            cout << "bot-right of player overlaps" << endl;
            return true;
        }
        if (isOverlapping(player.getPosition().x, player.getPosition().y - player.getDimensions().y)) {
            // bot-left corner of player overlaps barrier
            cout << "bot-left of player overlaps" << endl;
            return true;
        }
        return false;
    }

    string Barrier::getType() const {
        return BARRIER;
    }

    void Barrier::update() {
        Entity::update();
        player_ptr player = getPlayer();
        if (isOverlapping(*player)) {
            player->setDead(true);
        }
    }

    void Barrier::draw() const {
        drawRect(dimensions, Vector2f(pos).round(), color);
    }

}
