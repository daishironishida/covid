#pragma once

#include "ofMain.h"
#include "Mover.h"
#include "Parameters.h"

enum class InfectionState {
    SUSCEPTIBLE,
    INFECTED,
    RECOVERED,
};

class Person {
public:
    Person(int x, int y, int width, int height, InfectionState initialState = InfectionState::SUSCEPTIBLE) : pos(x, y), mover(width, height), state(initialState) {};

    void update();

    // two people come into contact with each other
    static void contact(Person &a, Person &b) {
        a.contact(b);
        b.contact(a);
    }

    // comes into contact with other
    void contact(const Person &other);

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
    Mover mover;
    InfectionState state;

    Parameters *params = Parameters::getInstance();
    
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
