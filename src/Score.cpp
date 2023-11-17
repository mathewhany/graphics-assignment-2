#include "Score.h"
#include "utils.h"

void Score::draw() {
    drawText("Score: " + std::to_string(Game::getInstance()->getScore()), 0, 0, 0xFFFFFF);
}
