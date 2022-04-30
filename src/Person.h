#pragma once

#include "ofMain.h"

enum class InfectionState {
    SUSCEPTIBLE,
    INFECTED,
    RECOVERED,
};

class Person {
public:
    Person(int x, int y, int width, int height, InfectionState initialState = InfectionState::SUSCEPTIBLE) : pos(x, y), worldWidth(width), worldHeight(height), state(initialState) {};

    void update() {
        // update position
        float dx = ofRandom(-1, 1);
        float dy = ofRandom(-1, 1);
        pos += ofVec2f(dx, dy);

        pos.x = ofClamp(pos.x, 0, worldWidth);
        pos.y = ofClamp(pos.y, 0, worldHeight);

        // update state
    }

    // two people come into contact with each other
    static void contact(Person &a, Person &b) {
        a.contact(b);
        b.contact(a);
    }

    // this comes into contact with other
    void contact(const Person &other) {
        if (this->isSusceptible() && other.isInfected()) {
            state = InfectionState::INFECTED;
        }
    }

    void draw() const {
        ofPushStyle();
        ofSetColor(getColor(state));
        ofDrawCircle(pos, 2);
        ofPopStyle();
    }

    ofVec2f getPosition() const {
        return pos;
    }
    bool isSusceptible() const {
        return state == InfectionState::SUSCEPTIBLE;
    }
    bool isInfected() const {
        return state == InfectionState::INFECTED;
    }
    
private:
    ofVec2f pos;
    InfectionState state;
    int worldWidth, worldHeight;
    
    static ofColor getColor(InfectionState state) {
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
