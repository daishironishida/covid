#pragma once

#include "ofMain.h"
#include "Parameters.h"

class Mover {
public:
    Mover(int width, int height) : worldWidth(width), worldHeight(height) {};
    void update(ofVec2f &position);

private:
    int worldWidth, worldHeight;
    ofVec2f velocity;
    Parameters *params = Parameters::getInstance();
};
