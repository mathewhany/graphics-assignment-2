#include <GLUT/glut.h>
#include <cstdlib>
#include "Game.h"

#define GLUT_KEY_ESCAPE 27

Game::Game(Camera camera, GameScene *scene, int windowWidth, int windowHeight)
        : camera(camera),
          scene(scene),
          windowWidth(windowWidth),
          windowHeight(windowHeight) {}

void Game::draw() {
    camera.setup();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    scene->draw();
    glFlush();
}

void Game::setScene(GameScene *newScene) {
    this->scene = newScene;
}

void Game::onKeyPressed(unsigned char key, int mouseX, int mouseY) {
    scene->onKeyPressed(key, mouseX, mouseY);

    switch (key) {
        case 's':
            camera.rotateX(1);
            camera.moveY(-1);
            break;
        case 'w':
            camera.rotateX(-1);
            camera.moveY(1);
            break;
        case 'a':
            camera.rotateY(1);
            camera.moveX(-1);
            break;
        case 'd':
            camera.rotateY(-1);
            camera.moveX(1);
            break;


    }
    if (key == GLUT_KEY_ESCAPE) {
        exit(EXIT_SUCCESS);
    }

    glutPostRedisplay();
}

void Game::onSpecialKeyPressed(int key, int mouseX, int mouseY) {
    scene->onSpecialKeyPressed(key, mouseX, mouseY);
    glutPostRedisplay();
}

const int &Game::getWindowWidth() const { return windowWidth; }

const int &Game::getWindowHeight() const { return windowHeight; }

void Game::init(int argc, char **argv) const {
    glutInit(&argc, argv);

    glutInitWindowSize(windowWidth, windowHeight);

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

    setupLights();

    glShadeModel(GL_FLAT);
}

void Game::setupLights() const {
    // Light 0
    GLfloat light0Position[] = {-1, -1, -1, 1};
    GLfloat light0Ambient[] = {0.2, 0.2, 0.2, 1};
    GLfloat light0Diffuse[] = {0.7, 0.7, 0.7, 1};
    GLfloat light0Specular[] = {0.1, 0.1, 0.1, 1};

    glLightfv(GL_LIGHT0, GL_POSITION, light0Position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light0Ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0Diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0Specular);

}

void Game::onIdle() {
    scene->onIdle();
    glutPostRedisplay();
}



