#include "GameTimer.h"
#include "utils.h"

void GameTimer::draw() {
    drawText(std::to_string(time) + "/60", 0, 0, 0xFFFFFF);
}

void GameTimer::onTimer(int value) {
    if (running) {
        time = value;
    }
}

bool GameTimer::isRunning() const {
    return running;
}

void GameTimer::setIsRunning(bool isRunning) {
    GameTimer::running = isRunning;
}
