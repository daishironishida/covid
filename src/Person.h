#pragma once

#include "ofMain.h"

#include "InfectionState.h"
#include "Mover.h"
#include "Parameters.h"

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
        ofSetColor(state.getColor());
        ofDrawCircle(pos, 2);
        ofPopStyle();
    }

    ofVec2f getPosition() const {
        return pos;
    }
    bool isSusceptible() const {
        return state.isSusceptible();
    }
    bool isInfected() const {
        return state.isInfected();
    }

private:
    ofVec2f pos;
    Mover mover;
    InfectionState state;

    Parameters *params = Parameters::getInstance();

    void updateState();
};
