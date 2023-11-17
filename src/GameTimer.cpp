#include "GameTimer.h"
#include "utils.h"

void GameTimer::draw() {
    drawText(std::to_string(time) + "/60", 0, 0, 0x00000);
}

void GameTimer::onTimer(int value) {
    time = value;
}