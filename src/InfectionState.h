#pragma once

#include "ofMain.h"

class InfectionState {
public:
    enum State {
        SUSCEPTIBLE,
        INFECTED,
        RECOVERED,
    };
    InfectionState() = default;
    constexpr InfectionState(State s) : state(s) { }

    bool isSusceptible() const {
        return state == InfectionState::SUSCEPTIBLE;
    }
    bool isInfected() const {
        return state == InfectionState::INFECTED;
    }

    ofColor getColor() const {
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

private:
    State state;
};
