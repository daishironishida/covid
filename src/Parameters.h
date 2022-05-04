#pragma once

class Parameters {
public:
    // static
    int initialPopulation = 100;
    float initialVaccinationRate = 0.1;
    float initialInfectionRate = 0.01;
    int worldWidth = 1000;
    int worldHeight = 1000;

    // dynamic
    float maxMovement = 3;
    float directionChangeProbability = 0.1;
    float infectionRadius = 10;
    float vaccinationProbability = 0.001;
    float infectionProbability = 0.1;
    float infectionProbabilityVaccinated = 0.01;
    float symptomProbability = 0.03;
    float recoverProbability = 0.01;

    // button
    bool resetWorld = false;

    void drawGui();

    static Parameters* getInstance() {
        static Parameters instance;
        return &instance;
    }
private:
    Parameters() = default;

    Parameters(const Parameters&) = delete;
    Parameters& operator=(const Parameters&) = delete;
    Parameters(Parameters&&) = delete;
    Parameters& operator=(Parameters&&) = delete;
};
