#pragma once

class Parameters {
public:
    int worldWidth = 1000;
    int worldHeight = 1000;
    float maxMovement = 3;
    float infectionRadius = 10;

    void drawGui() {
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
