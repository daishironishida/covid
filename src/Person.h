#pragma once

#include "ofMain.h"

enum class InfectionState {
    SUSCEPTIBLE,
    INFECTED,
    RECOVERED,
};

class Person {
public:
    Person(int x, int y, int width, int height) : pos(x, y), worldWidth(width), worldHeight(height) {};

    void update() {
        float dx = ofRandom(-1, 1);
        float dy = ofRandom(-1, 1);
        pos += ofVec2f(dx, dy);

        pos.x = ofClamp(pos.x, 0, worldWidth);
        pos.y = ofClamp(pos.y, 0, worldHeight);
    }

    void draw() const {
        ofPushStyle();
        ofSetColor(getColor(state));
        ofDrawCircle(pos, 2);
        ofPopStyle();
    }
    
private:
    ofVec2f pos;
    InfectionState state = InfectionState::SUSCEPTIBLE;
    int worldWidth, worldHeight;
    
    ofColor getColor(InfectionState state) const {
        switch(state) {
            case InfectionState::SUSCEPTIBLE:
                return ofColor(0, 255, 255);
            case InfectionState::INFECTED:
                return ofColor(255, 0, 0);
            case InfectionState::RECOVERED:
                return ofColor(0, 0, 255);
            default:
                ofLogWarning() << "Invalid state: " << static_cast<int>(state);
                return ofColor(255, 255, 255);
        }
    }
};
