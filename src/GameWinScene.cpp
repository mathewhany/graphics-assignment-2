#include "GameWinScene.h"
#include "utils.h"

GameWinScene::GameWinScene() {
    camera.setEye({0, 0, 100});
    camera.setUp({0, 1, 0});
    camera.setCenter({0, 0, 0});
}

void GameWinScene::draw() {
    drawText("You win!", 0, 0, 0x000000);
}

