#include "Mover.h"

void Mover::update(ofVec2f &position) {
    float dx = ofRandom(-params->maxMovement, params->maxMovement);
    float dy = ofRandom(-params->maxMovement, params->maxMovement);
    position += ofVec2f(dx, dy);
    
    position.x = ofClamp(position.x, 0, worldWidth);
    position.y = ofClamp(position.y, 0, worldHeight);
}
