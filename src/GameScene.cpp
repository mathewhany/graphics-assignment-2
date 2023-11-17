#include <GLUT/glut.h>
#include "GameScene.h"

GameScene::GameScene()
        : camera(
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0},
        Game::getInstance()->getGameSettings()->getAspectRatio()) {}

void GameScene::draw() {
    for (auto &[_, gameObject]: gameObjects) {
        if (!gameObject->isShowing()) {
            continue;
        }

        glPushMatrix();
        glTranslatef(gameObject->getPosition().getX(),
                     gameObject->getPosition().getY(),
                     gameObject->getPosition().getZ());
        glRotated(gameObject->getAngle().getX(), 1, 0, 0);
        glRotated(gameObject->getAngle().getY(), 0, 1, 0);
        glRotated(gameObject->getAngle().getZ(), 0, 0, 1);
        glScaled(gameObject->getScale().getX(),
                 gameObject->getScale().getY(),
                 gameObject->getScale().getZ());
        gameObject->draw();
        glPopMatrix();

        if (Game::getInstance()->getGameSettings()->isCollisionBoxesShown()) {
            glPushMatrix();
            glTranslatef(gameObject->getStart().getX(),
                         gameObject->getStart().getY(),
                         gameObject->getStart().getZ());
            glTranslatef(
                    gameObject->getSize().getX() / 2,
                    gameObject->getSize().getY(),
                    gameObject->getSize().getZ() / 2
            );
            glScaled(gameObject->getSize().getX(),
                     gameObject->getSize().getY(),
                     gameObject->getSize().getZ());
            glutWireCube(1);
            glPopMatrix();
        }
    }
}

void GameScene::onKeyPressed(unsigned char key, int mouseX, int mouseY) {
    for (auto &[_, gameObject]: gameObjects) {
        gameObject->onKeyPressed(key, mouseX, mouseY);
    }

    float d = 1;
    float a = 1;
    switch (key) {
        case 'w':
            camera.moveY(d);
            break;
        case 's':
            camera.moveY(-d);
            break;
        case 'a':
            camera.moveX(d);
            break;
        case 'd':
            camera.moveX(-d);
            break;
        case 'q':
            camera.moveZ(d);
            break;
        case 'e':
            camera.moveZ(-d);
            break;
        case 'u':
            camera.rotateX(a);
            break;
        case 'j':
            camera.rotateX(-a);
            break;
        case 'h':
            camera.rotateY(a);
            break;
        case 'k':
            camera.rotateY(-a);
            break;
        case 'z':
            // Top View
            camera.setEye({0, 80, 0});
            camera.setCenter({0, 0, 0});
            camera.setUp({0, 0, -1});
            break;
        case 'x':
            // Front View
            camera.setEye({0, 20, 80});
            camera.setCenter({0, 0, 0});
            camera.setUp({0, 1, 0});
            break;
        case 'c':
            // Side View
            camera.setEye({80, 20, 0});
            camera.setCenter({0, 0, 0});
            camera.setUp({0, 1, 0});
            break;
        default:
            break;
    }
}

void GameScene::onSpecialKeyPressed(int key, int mouseX, int mouseY) {
    for (auto &[_, gameObject]: gameObjects) {
        gameObject->onSpecialKeyPressed(key, mouseX, mouseY);
    }
}

void GameScene::onIdle() {
    for (auto &[_, gameObject]: gameObjects) {
        gameObject->onIdle();

        if (!gameObject->isShowing()) continue;

        for (auto &[_, otherGameObject]: gameObjects) {
            if (gameObject != otherGameObject && otherGameObject->isShowing()) {
                if (gameObject->isColliding(*otherGameObject)) {
                    gameObject->onCollision(otherGameObject);
                }
            }
        }
    }
}

const Camera &GameScene::getCamera() const {
    return camera;
}

void GameScene::setupLights() {
    // Light 0
    GLfloat light0Position[] = {-7.0f, 6.0f, 3.0f, 0.0f};
    GLfloat light0Ambient[] = {0.3f, 0.3f, 0.3, 1.0f};
    GLfloat light0Diffuse[] = {0.6f, 0.6f, 0.6, 1.0f};
    GLfloat light0Specular[] = {1.0f, 1.0f, 1.0, 1.0f};
    GLfloat light0Shininess[] = {50.0f};

    glLightfv(GL_LIGHT0, GL_POSITION, light0Position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light0Ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0Diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0Specular);
    glLightfv(GL_LIGHT0, GL_SHININESS, light0Shininess);

    glShadeModel(GL_SMOOTH);
}

void GameScene::onTimer(int value) {
    for (auto &[_, gameObject]: gameObjects) {
        gameObject->onTimer(value);
    }
}

