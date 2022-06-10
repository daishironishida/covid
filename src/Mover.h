#pragma once

#include "ofMain.h"
#include "Parameters.h"

class Mover {
public:
    Mover(int width, int height);
    void update(ofVec2f &position, bool symptomatic=false);

private:
    int worldWidth, worldHeight;
    ofVec2f velocity;
    Parameters *params = Parameters::getInstance();

    void setVelocity(bool symptomatic);
};
