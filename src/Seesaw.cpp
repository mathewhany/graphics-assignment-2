#include <GLUT/glut.h>
#include "Seesaw.h"
#include "utils.h"

void drawSeesawStand() {
    color(0x0A8AFF);
    glPushMatrix();
    glTranslated(0.25, 0, 0);
    glRotated(30, 0, 0, 1);
    glScaled(0.3, 1.5, 0.3);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-0.25, 0, 0);
    glRotated(-30, 0, 0, 1);
    glScaled(0.3, 1.5, 0.3);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, 0.75, 0);
    glutSolidSphere(0.75, 20, 20);
    glPopMatrix();
}


void drawSeesawChair() {
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

void Seesaw::draw() {
    glPushMatrix();
    glTranslated(0, 1.25, 0);

    glPushMatrix();
    glTranslated(0, 0.75, 0);
    glRotated(angle, 0, 0, 1);

    glPushMatrix();
    glTranslated(9, 0.55, 0);
    drawSeesawChair();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-9, 0.55, 0);
    glRotated(180, 0, 1, 0);
    drawSeesawChair();
    glPopMatrix();

    color(0xFFDF91);
    glPushMatrix();
    glScaled(20, 0.5, 2.5);
    glutSolidCube(1);
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glTranslated(0, 0, 2.25);
    drawSeesawStand();
    glPopMatrix();


    glPushMatrix();
    glTranslated(0, 0, -2.25);
    drawSeesawStand();
    glPopMatrix();

    glPopMatrix();
}

void Seesaw::onKeyPressed(unsigned char key, int mouseX, int mouseY) {
    if (key == 'g') {
        shouldMove = !shouldMove;
    }
}

void Seesaw::onIdle() {
    if (shouldMove) {
        if (angle >= 8) {
            angleStep = -0.5;
        } else if (angle <= -8) {
            angleStep = 0.5;
        }

        angle += angleStep;
    }
}
