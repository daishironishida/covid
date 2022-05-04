#include "Mover.h"

Mover::Mover(int width, int height) : worldWidth(width), worldHeight(height) {
    setVelocity();
}

void Mover::update(ofVec2f &position) {
    position += velocity;
    position.x = ofClamp(position.x, 0, worldWidth);
    position.y = ofClamp(position.y, 0, worldHeight);

    if (ofRandom(1) < params->directionChangeProbability) {
        setVelocity();
    }
}

void Mover::setVelocity() {
    velocity.x = ofRandom(-params->maxMovement, params->maxMovement);
    velocity.y = ofRandom(-params->maxMovement, params->maxMovement);
}
