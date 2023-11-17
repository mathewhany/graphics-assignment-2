#include <GLUT/glut.h>
#include "GameOverScene.h"
#include "utils.h"
#include "Sounds.h"

GameOverScene::GameOverScene() {
    camera.setEye({0, 0, 100});
    camera.setUp({0, 1, 0});
    camera.setCenter({0, 0, 0});

    Sounds::resetAndPlay(Sounds::gameOverTheme);
}

void GameOverScene::draw() {
    drawText("You lose", 0, 0, 0x000000);
}
