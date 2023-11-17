#include <GLUT/glut.h>
#include "Roller.h"
#include "utils.h"

Roller::Roller() : GameObject({20, 3, 20}) {}

void drawRollerChair() {
    color(0xFF443C);
    glPushMatrix();
    glScaled(3, 0.25, 3);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(2, 1.25, 0);
    glRotated(-120, 0, 0, 1);
    glScaled(3, 0.25, 3);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1.5, 0.75, 0);
    glScaled(0.25, 0.25, 1.5);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1.5, 0.25, 0);
    glScaled(0.25, 1, 0.25);
    glutSolidCube(1);
    glPopMatrix();
}

void Roller::draw() {
    glPushMatrix();
    glTranslated(0, 1, 0);
    glRotated(rotation.getValue(), 0, 1, 0);
    color(0xF9FF7C);
    glPushMatrix();
    glRotated(-90, 1, 0, 0);
    cylinder(10, 1);
    glPopMatrix();


    for (int i = 0; i < 8; i++) {
        glPushMatrix();
        glRotated(i * 45, 0, 1, 0);
        glTranslated(8, 1.25, 0);
        drawRollerChair();
        glPopMatrix();
    }

    color(0x000000);
    glPushMatrix();
    glTranslated(0, -1, 0);
    glRotated(-90, 1, 0, 0);
    glutSolidCone(1, 3, 20, 20);
    glPopMatrix();
    glPopMatrix();
}

void Roller::onKeyPressed(unsigned char key, int mouseX, int mouseY) {
    if (key == '1') {
        rotation.toggle();
    }
}

void Roller::onIdle() {
    rotation.animate();
}
