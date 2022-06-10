#include "Mover.h"

Mover::Mover(int width, int height) : worldWidth(width), worldHeight(height) {
    setVelocity(false);
}

void Mover::update(ofVec2f &position, bool symptomatic) {
    position += velocity;
    position.x = ofClamp(position.x, 0, worldWidth);
    position.y = ofClamp(position.y, 0, worldHeight);

    if (ofRandom(1) < params->directionChangeProbability) {
        setVelocity(symptomatic);
    }
}

void Mover::setVelocity(bool symptomatic) {
    float maxMovement = symptomatic ? params->maxMovementSymptomatic : params->maxMovement;
    velocity.x = ofRandom(-maxMovement, maxMovement);
    velocity.y = ofRandom(-maxMovement, maxMovement);
}
