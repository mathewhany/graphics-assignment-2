#include <GLUT/glut.h>
#include <cstdlib>
#include "Game.h"
#include "Sounds.h"

#define GLUT_KEY_ESCAPE 27

Game::Game(GameSettings *gameSettings) : gameSettings(gameSettings) {
    Sounds::loadSounds();
}

void Game::draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    scene->getCamera().setup();
    scene->setupLights();
    scene->draw();
    glFlush();
}

void Game::onKeyPressed(unsigned char key, int mouseX, int mouseY) {
//    Sounds::resetAndPlay(Sounds::buttonClick);
    scene->onKeyPressed(tolower(key), mouseX, mouseY);

    if (key == GLUT_KEY_ESCAPE) {
        exit(EXIT_SUCCESS);
    }

    glutPostRedisplay();
}

void Game::onSpecialKeyPressed(int key, int mouseX, int mouseY) {
//    Sounds::resetAndPlay(Sounds::buttonClick);
    scene->onSpecialKeyPressed(key, mouseX, mouseY);
    glutPostRedisplay();
}

void Game::init(int argc, char **argv) const {
    glutInit(&argc, argv);

    glutInitWindowSize(gameSettings->getWindowWidth(), gameSettings->getWindowHeight());

    glutCreateWindow("Game 6");

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glClearColor(127.0 / 255.0, 207.0 / 255.0, 255.0 / 255.0, 0.0f);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    glEnable(GL_LIGHT3);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
}

void Game::onIdle() {
    scene->onIdle();
    glutPostRedisplay();
}

void Game::onTimer(int value) {
    scene->onTimer(value);
}

GameSettings *Game::getGameSettings() const {
    return gameSettings;
}

void Game::setScene(GameScene *newScene) {
    scene = newScene;
}

Game *Game::instance;

Game *Game::getInstance(GameSettings *settings) {
    if (instance == nullptr) {
        instance = new Game(settings);
    }

    return instance;
}

GameScene *Game::getScene() const {
    return scene;
}

int Game::getScore() const {
    return score;
}

void Game::setScore(int newScore) {
    score = newScore;
}



