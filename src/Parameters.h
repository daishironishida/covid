#pragma once

class Parameters {
public:
    int worldWidth = 1000;
    int worldHeight = 1000;
    int maxMovement = 10;
    int infectionRadius = 10;

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
