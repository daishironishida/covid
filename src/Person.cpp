#include "Person.h"

void Person::update() {
    // update position
    mover.update(pos, state.isSymptomatic());

    // update state
    updateState();

    // reset contact number
    numContacts = 0;
}

void Person::updateState() {
    if (state == InfectionState::RECOVERED) {
        return;
    }

    // chance to get vaccination
    if (state == InfectionState::UNVACCINATED) {
        if (ofRandom(1) < params->vaccinationProbability) {
            state = InfectionState::VACCINATED;
        }
    }

    // chance to catch virus if susceptible
    if (isSusceptible()) {
        float thresh = params->infectionProbability;
        if (state == InfectionState::VACCINATED) {
            thresh = params->infectionProbabilityVaccinated;
        }
        thresh *= numContacts;
        if (ofRandom(1) < thresh) {
            state = InfectionState::LATENT;
        }
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
        numContacts++;
    }
}

