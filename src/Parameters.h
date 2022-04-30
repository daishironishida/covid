#pragma once

class Parameters {
public:
    int worldWidth = 1000;
    int worldHeight = 1000;
    float maxMovement = 3;
    float directionChangeProbability = 0.1;
    float infectionRadius = 10;

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
