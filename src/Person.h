#pragma once

#include "ofMain.h"

enum class InfectionState {
    SUSCEPTIBLE,
    INFECTED,
    RECOVERED,
};

class Person {
public:
    void update() {
        float dx = ofRandom(-1, 1);
        float dy = ofRandom(-1, 1);
        pos += ofPoint(dx, dy, 0);
    }

    void draw() const {
        ofPushStyle();
        ofSetColor(getColor(state));
        ofDrawCircle(pos, 2);
        ofPopStyle();
    }
    
private:
    ofPoint pos;
    InfectionState state;
    
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
