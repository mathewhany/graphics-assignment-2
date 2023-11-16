#include <GLUT/glut.h>
#include <vector>
#include "FerrisWheel.h"
#include "utils.h"

FerrisWheel::FerrisWheel(Vector3f position) : GameObject(position, {10, 20, 10}) {}

void drawStand() {
    glPushMatrix();
    glTranslated(5, 1, 0);
    glRotated(30, 0, 0, 1);
    glScaled(0.75, 21, 0.75);
    color(0x2F8FFF);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-5, 1, 0);
    glRotated(-30, 0, 0, 1);
    glScaled(0.75, 21, 0.75);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, 10, 0);
    glutSolidSphere(1, 20, 20);
    glPopMatrix();
}

void FerrisWheel::draw() {
    glPushMatrix();
    glTranslated(0, 0, 7);
    drawStand();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, 0, -7);
    drawStand();
    glPopMatrix();


    color(0xFFFFFF);
    glPushMatrix();
    glTranslated(0, 10, 0);
    glRotated(rotation, 0, 0, 1);
    glPushMatrix();
    glTranslated(0, 0, -4);
    for (int i = 0; i < 4; i++) {
        glPushMatrix();
        glRotated(45 * i, 0, 0, 1);
        glScaled(0.5, 20, 0.5);
        glutSolidCube(1);
        glPopMatrix();
    }
    glPopMatrix();

    glPushMatrix();
    glScaled(0.5, 0.5, 12);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, 0, 4);
    for (int i = 0; i < 4; i++) {
        glPushMatrix();
        glRotated(45 * i, 0, 0, 1);
        glScaled(0.5, 20, 0.5);
        glutSolidCube(1);
        glPopMatrix();
    }
    glPopMatrix();

    for (int i = 0; i < 8; i++) {
        glPushMatrix();
        glRotated(45 * i, 0, 0, 1);
        glTranslated(0, 10, 0);
        glScaled(0.5, 0.5, 8);
        glutSolidCube(1);
        glPopMatrix();
    }

    std::vector<int> colors = {
            0x08FF00,
            0xFFFC19,
            0x00B3FF,
            0xFF3700
    };
    for (int i = 0; i < 8; i++) {
        color(colors[i % colors.size()]);
        glPushMatrix();
        glRotated(45 * i, 0, 0, 1);
        glTranslated(0, 10, 0);
        glRotated(-45 * i, 0, 0, 1);
        glScaled(1.25, 1.25, 1.25);
        glutSolidDodecahedron();
        glPopMatrix();
    }

    glPopMatrix();

//    glPushMatrix();
//    glTranslated(0, 0, 4);
//    for (int i = 0; i < 8; i++) {
//        glPushMatrix();
//        glRotated(45 * i, 0, 0, 1);
//        glTranslated(0, 10, 0);
//        glScaled(8, 0.5, 0.5);
//        glutSolidCube(1);
//        glPopMatrix();
//    }
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslated(0, 0, -4);
//    for (int i = 0; i < 8; i++) {
//        glPushMatrix();
//        glRotated(45 * i, 0, 0, 1);
//        glTranslated(0, 10, 0);
//        glScaled(8, 0.5, 0.5);
//        glutSolidCube(1);
//        glPopMatrix();
//    }
//    glPopMatrix();
}

void FerrisWheel::onKeyPressed(unsigned char key, int mouseX, int mouseY) {
    if (key == 'f') {
        shouldMove = !shouldMove;
    }
}

void FerrisWheel::onIdle() {
//    GameObject::onIdle();

    if (shouldMove) {
        rotation += 0.5;
    }
}
