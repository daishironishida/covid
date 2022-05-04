#include "Person.h"

void Person::update() {
    // update position
    mover.update(pos);

    // update state
}

void Person::contact(const Person &other) {
    if (this->isSusceptible() && other.isInfected()) {
        state.infect();
    }
}

