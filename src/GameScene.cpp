#include <GLUT/glut.h>
#include "GameScene.h"

void GameScene::draw() {
    for (auto &gameObject: gameObjects) {
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
    }
}

void GameScene::onKeyPressed(unsigned char key, int mouseX, int mouseY) {
    for (auto &gameObject: gameObjects) {
        gameObject->onKeyPressed(key, mouseX, mouseY);
    }
}

void GameScene::onSpecialKeyPressed(int key, int mouseX, int mouseY) {
    for (auto &gameObject: gameObjects) {
        gameObject->onSpecialKeyPressed(key, mouseX, mouseY);
    }
}

void GameScene::onIdle() {
    for (auto &gameObject: gameObjects) {
        gameObject->onIdle();
    }
}
