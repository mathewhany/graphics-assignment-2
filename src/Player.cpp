#include <GLUT/glut.h>
#include "Player.h"
#include "utils.h"
#include "Goal.h"
#include "Game.h"
#include "GameWin.h"
#include "Sounds.h"
#include "GameTimer.h"

Player::Player() : GameObject({3, 10, 3}) {}

void Player::draw() {
    glPushMatrix();
    glTranslatef(0, 5, 0);
    glScaled(0.2, 0.2, 0.2);

    // Hat
    color(30, 13, 19);
    glPushMatrix();
    glTranslatef(0, 20, 0);
    glRotated(90, 1, 0, 0);
    glPushMatrix();
    glTranslatef(0, 0, 3);
    glPopMatrix();
    cylinder(4, 3);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 17, 0);
    glRotated(90, 1, 0, 0);
    glPushMatrix();
    glTranslatef(0, 0, 3);
    glPopMatrix();
    cylinder(7, 0.5);
    glPopMatrix();

    // Head
    glPushMatrix();
    glTranslatef(0, 12, 0);
    glScaled(1, 1.1, 1);
    color(255, 224, 164);
    glutSolidSphere(5, 255, 255);
    glPopMatrix();

    // Eyes
    glPushMatrix();
    glTranslatef(-1.5, 13, -4.5);
    glScaled(0.5, 0.5, 0.5);
    color(0, 0, 0);
    glutSolidSphere(1, 255, 255);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5, 13, -4.5);
    glScaled(0.5, 0.5, 0.5);
    color(0, 0, 0);
    glutSolidSphere(1, 255, 255);
    glPopMatrix();

    // Body
    glPushMatrix();
    glScaled(7.5, 10, 5);
    color(255, 122, 183);
    glutSolidSphere(1, 255, 255);
    glPopMatrix();

    // Skirt
    glPushMatrix();
    glTranslatef(0, -10, 0);
    glScaled(10, 20, 10);
    glRotated(-90, 1, 0, 0);
    color(255, 122, 183);
    glutSolidCone(1, 1, 255, 255);
    glPopMatrix();

    // Left Arm
    glPushMatrix();
    glRotated(-45, 0, 0, 1);
    glTranslatef(5, 8, 0);
    glScaled(5, 1, 1);
    color(255, 224, 164);
    glutSolidSphere(1, 255, 255);
    glPopMatrix();

    // Right Arm
    glPushMatrix();
    glRotated(45, 0, 0, 1);
    glTranslatef(-5, 8, 0);
    glScaled(5, 1, 1);
    color(255, 224, 164);
    glutSolidSphere(1, 255, 255);
    glPopMatrix();

    // Left Leg
    glPushMatrix();
    glTranslatef(-2.5, -15, 0);
    glScaled(1.5, 10, 1.5);
    color(255, 224, 164);
    glutSolidSphere(1, 255, 255);
    glPopMatrix();

    // Right Leg
    glPushMatrix();
    glTranslatef(2.5, -15, 0);
    glScaled(1.5, 10, 1.5);
    color(255, 224, 164);
    glutSolidSphere(1, 255, 255);
    glPopMatrix();
    glPopMatrix();
}

void Player::onSpecialKeyPressed(int key, int mouseX, int mouseY) {
    switch (key) {
        case GLUT_KEY_UP:
            latestMovement = FORWARD;
            smoothMoveBy(direction);
            break;
        case GLUT_KEY_DOWN:
            latestMovement = BACKWARD;
            smoothMoveBy(direction * -1);
            break;
        case GLUT_KEY_LEFT:
            direction = direction.rotateY(10);
            smoothRotateBy({0, 10, 0});
            break;
        case GLUT_KEY_RIGHT:
            direction = direction.rotateY(-10);
            smoothRotateBy({0, -10, 0});
            break;
        default:
            break;
    }
}

void Player::onCollision(GameObject *&pObject) {
    auto *goal = dynamic_cast<Goal *>(pObject);

    if (goal != nullptr) {
        goal->setShowing(false);

        Sounds::resetAndPlay(Sounds::buttonClick);

        Game *game = Game::getInstance();
        game->setScore(game->getScore() + 1);

        if (game->getScore() == 3) {
            Sounds::resetAndPlay(Sounds::gameWinTheme);

            Game::getInstance()->getScene()->getGameObjectByTag<GameTimer>("game-time")->setIsRunning(false);
            Game::getInstance()->getScene()->getGameObjectByTag<GameWin>("game-win")->setShowing(true);
        }
    }

    switch (latestMovement) {
        case FORWARD:
            moveBy(direction * -1);
            break;
        case BACKWARD:
            moveBy(direction);
            break;
    }
}
