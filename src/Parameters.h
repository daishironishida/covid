#pragma once

#include <cereal/cereal.hpp>
#include <cereal/archives/json.hpp>

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
    float maxMovementSymptomatic = 0.3;
    float directionChangeProbability = 0.1;
    float infectionRadius = 10;
    float vaccinationProbability = 0.001;
    float infectionProbability = 0.01;
    float infectionProbabilityVaccinated = 0.001;
    float symptomProbability = 0.003;
    float recoverProbability = 0.001;

    // button
    bool resetWorld = false;

    void drawGui();

    static Parameters* getInstance() {
        static Parameters instance;
        return &instance;
    }

    // serialize
    template <class Archive>
    void serialize( Archive & ar )
    {
        ar(
           CEREAL_NVP(initialPopulation), CEREAL_NVP(initialVaccinationRate), CEREAL_NVP(initialInfectionRate),
           CEREAL_NVP(worldWidth), CEREAL_NVP(worldHeight),
           CEREAL_NVP(maxMovement), CEREAL_NVP(maxMovementSymptomatic), CEREAL_NVP(directionChangeProbability),
           CEREAL_NVP(infectionRadius),
           CEREAL_NVP(vaccinationProbability), CEREAL_NVP(infectionProbability), CEREAL_NVP(infectionProbabilityVaccinated),
           CEREAL_NVP(symptomProbability), CEREAL_NVP(recoverProbability)
         );
    }
    void save();
    void load();
    
private:
    Parameters();

    Parameters(const Parameters&) = delete;
    Parameters& operator=(const Parameters&) = delete;
    Parameters(Parameters&&) = delete;
    Parameters& operator=(Parameters&&) = delete;

    std::string paramsPath;
};
