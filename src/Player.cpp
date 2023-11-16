#include <GLUT/glut.h>
#include "Player.h"
#include "utils.h"

Player::Player(Vector3f position)
        : GameObject(position, {10, 20, 10}) {}

void Player::draw() {
    glPushMatrix();
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
            if (position.getZ() < -27.5) {
                break;
            }
            smoothMoveBy({0, 0, -1});
            smoothRotateTo({0, 0, 0});
            break;
        case GLUT_KEY_DOWN:
            if (position.getZ() > 27.5) {
                break;
            }
            smoothMoveBy({0, 0, 1});
            smoothRotateTo({0, 180, 0});
            break;
        case GLUT_KEY_LEFT:
            if (position.getX() < -27.5) {
                break;
            }
            smoothMoveBy({-1, 0, 0});
            smoothRotateTo({0, 90, 0});
            break;
        case GLUT_KEY_RIGHT:
            if (position.getX() > 27.5) {
                break;
            }
            smoothMoveBy({1, 0, 0});
            smoothRotateTo({0, -90, 0});
            break;
        default:
            break;
    }
}

void Player::onIdle() {
    GameObject::onIdle();
//    rotateBy({0, 1, 0});
}


