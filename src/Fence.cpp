#include <GLUT/glut.h>
#include <iostream>
#include "Fence.h"
#include "utils.h"


std::array<int, 4> fenceColors = {
        0x92FF76,
        0xFF9214,
        0xFF5772,
        0xE8FF12
};

void Fence::draw() {
    color(fenceColors[currentColor]);
    glPushMatrix();
    glTranslatef(0, 0.5, 0);

    glPushMatrix();
    glTranslatef(0, 1.5, -20);
    glPushMatrix();
    glTranslatef(0, 1.5, 0);
    glRotated(-90, 1, 0, 0);
    glutSolidCone(0.7, 0.7, 255, 255);
    glPopMatrix();
    glPushMatrix();
    glScaled(0.5, 3, 0.5);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 1, 0);
    glScaled(0.5, 0.5, 40);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 2, 0);
    glScaled(0.5, 0.5, 40);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 1.5, 20);
    glPushMatrix();
    glTranslatef(0, 1.5, 0);
    glRotated(-90, 1, 0, 0);
    glutSolidCone(0.7, 0.7, 255, 255);
    glPopMatrix();
    glPushMatrix();
    glScaled(0.5, 3, 0.5);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
}

void Fence::onTimer(int value) {
    if (value % 5 == 0) {
        currentColor = (currentColor + 1) % fenceColors.size();
    }
}

