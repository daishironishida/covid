#pragma once

#include "ofMain.h"

class InfectionState {
public:
    enum State {
        UNVACCINATED, // not vaccinated, not infected
        VACCINATED,   // vaccinated, not infected
        LATENT,       // infected, no symptoms
        SYMPTOMATIC,  // infected, symptoms
        RECOVERED,
    };
    InfectionState() = default;
    constexpr InfectionState(State s) : state(s) { }
    constexpr bool operator==(InfectionState s) const { return state == s.state; }
    constexpr bool operator!=(InfectionState s) const { return state != s.state; }

    bool isSusceptible() const {
        return state == InfectionState::UNVACCINATED || state == InfectionState::VACCINATED;
    }
    bool isInfected() const {
        return state == InfectionState::LATENT || state == InfectionState::SYMPTOMATIC;
    }
    bool isSymptomatic() const {
        return state == InfectionState::SYMPTOMATIC;
    }
    void infect() {
        state = InfectionState::LATENT;
    }

    ofColor getColor() const {
        switch(state) {
            case InfectionState::UNVACCINATED:
                return ofColor(150, 200, 255);
            case InfectionState::VACCINATED:
                return ofColor(0, 255, 0);
            case InfectionState::LATENT:
                return ofColor(255, 200, 0);
            case InfectionState::SYMPTOMATIC:
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
