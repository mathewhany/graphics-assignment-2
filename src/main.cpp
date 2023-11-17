#include <GLUT/glut.h>
#include <cstdlib>
#include "MainScene.h"
#include "Game.h"
#include "utils.h"

GameSettings *gameSettings = GameSettingsBuilder()
        .setWindowWidth(1024)
        .setWindowHeight(1024)
        .build();

Game *game = Game::getInstance(gameSettings);

void timer(int value) {
    game->onTimer(value);
    glutTimerFunc(1000, timer, value + 1);
}

int main(int argc, char **argv) {
    game->setScene(new MainScene());

    game->init(argc, argv);

    glutDisplayFunc([]() {
        game->draw();
    });

    glutKeyboardFunc([](unsigned char key, int mouseX, int mouseY) {
        game->onKeyPressed(key, mouseX, mouseY);
    });

    glutSpecialFunc([](int key, int mouseX, int mouseY) {
        game->onSpecialKeyPressed(key, mouseX, mouseY);
    });

    glutIdleFunc([]() {
        game->onIdle();
    });

    timer(0);

    glutMainLoop();

    return EXIT_SUCCESS;
}
