#include "Parameters.h"

#include "ofMain.h"
#include "ofxImGui.h"

namespace ImGui {
bool SliderFloatPercentage(const char* label, float* v, float v_min, float v_max, const char* format = "%.3f", float power = 1.0f) {
    float percentage = *v * 100;
    bool isModified = ImGui::SliderFloat(label, &percentage, v_min, v_max, format, power);
    *v = percentage / 100;
    return isModified;
}
}

Parameters::Parameters() {
    paramsPath = ofToDataPath("params.json");
}

void Parameters::drawGui() {
    if (ImGui::TreeNode("Static")) {
        ImGui::SliderInt("Initial population", &initialPopulation, 1, 10000);
        ImGui::SliderFloat("Initial vaccination rate", &initialVaccinationRate, 0, 1);
        ImGui::SliderFloat("Initial infection rate", &initialInfectionRate, 0, 1);
        array<int, 2> worldSize = {worldWidth, worldHeight};
        ImGui::InputInt2("World size", &worldSize[0]);
        worldWidth = worldSize[0];
        worldHeight = worldSize[1];
        
        ImGui::TreePop();
    }
    
    if (ImGui::TreeNode("Dynamic")) {
        ImGui::SliderFloat("Max movement (healthy)", &maxMovement, 0, 10);
        ImGui::SliderFloat("Max movement (symptomatic)", &maxMovementSymptomatic, 0, 10);
        ImGui::SliderFloatPercentage("Direction change probability %", &directionChangeProbability, 0, 100);
        ImGui::SliderFloat("Infection Radius", &infectionRadius, 0, 100);
        ImGui::SliderFloatPercentage("Vacciation Probability %", &vaccinationProbability, 0, 1);
        ImGui::SliderFloatPercentage("Infection Probability (not vaccinated) %", &infectionProbability, 0, 1);
        ImGui::SliderFloatPercentage("Infection Probability (vaccinated) %", &infectionProbabilityVaccinated, 0, 1);
        ImGui::SliderFloatPercentage("Symptom Probability %", &symptomProbability, 0, 1);
        ImGui::SliderFloatPercentage("Recover Probability %", &recoverProbability, 0, 1);
        
        ImGui::TreePop();
    }

    resetWorld = ImGui::Button("Reset");
}

void Parameters::save() {
    std::ofstream os(paramsPath);
    try {
        cereal::JSONOutputArchive archive( os );
        archive(cereal::make_nvp("params", *this));
    } catch (std::exception &e) {
        ofLogWarning() << "Could not save params to " << paramsPath;
        ofLogWarning() << e.what();
        return;
    }
    ofLogNotice() << "Saved params to " << paramsPath;
}

void Parameters::load() {
    std::ifstream is(paramsPath);
    try {
        cereal::JSONInputArchive archive( is );
        archive(cereal::make_nvp("params", *this));
    } catch (std::exception &e) {
        ofLogWarning() << "Could not load params from " << paramsPath;
        ofLogWarning() << e.what();
        return;
    }
    ofLogNotice() << "Loaded params from " << paramsPath;
}
