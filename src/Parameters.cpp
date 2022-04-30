#include "Parameters.h"

#include "ofMain.h"
#include "ofxImGui.h"

void Parameters::drawGui() {
    if (ImGui::TreeNode("Static")) {
        array<int, 2> worldSize = {worldWidth, worldHeight};
        ImGui::InputInt2("World size", &worldSize[0]);
        worldWidth = worldSize[0];
        worldHeight = worldSize[1];
        
        ImGui::TreePop();
    }
    
    if (ImGui::TreeNode("Dynamic")) {
        ImGui::SliderFloat("Max movement", &maxMovement, 0, 10);
        ImGui::SliderFloat("Infection Radius", &infectionRadius, 0, 100);
        
        ImGui::TreePop();
    }
}
