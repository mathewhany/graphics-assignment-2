#include <GLUT/glut.h>
#include "GameOverScene.h"
#include "utils.h"

GameOverScene::GameOverScene() {
    camera.setEye({0, 0, 100});
    camera.setUp({0, 1, 0});
    camera.setCenter({0, 0, 0});
}

void GameOverScene::draw() {
    drawText("You lose", 0, 0, 0x000000);
}
