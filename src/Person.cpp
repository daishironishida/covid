#include "Person.h"

void Person::update() {
    // update position
    mover.update(pos);

    // update state
    updateState();
}

void Person::updateState() {
    if (state == InfectionState::SUSCEPTIBLE || state == InfectionState::VACCINATED || state == InfectionState::RECOVERED) {
        return;
    }

    // chance to recover if latent/symptomatic
    if (ofRandom(1) < params->recoverProbability) {
        state = InfectionState::RECOVERED;
        return;
    }

    if (state == InfectionState::SYMPTOMATIC) {
        return;
    }

    // chance to get symptoms if latent
    if (ofRandom(1) < params->symptomProbability) {
        state = InfectionState::SYMPTOMATIC;
        return;
    }
}

void Person::contact(const Person &other) {
    if (this->isSusceptible() && other.isInfected()) {
        state.infect();
    }
}

