#include <GLUT/GLUT.h>
#include "Lamp.h"
#include "utils.h"
#include "Sounds.h"

Lamp::Lamp() : GameObject({2, 15, 2}) {}

void Lamp::draw() {
    glPushMatrix();
    glTranslated(0, 10, 0);
    color(0x00970A);
    glPushMatrix();
    glRotated(90, 1, 0, 0);
    GLUquadric *quad = gluNewQuadric();
    gluCylinder(quad, 0.5, 0.5, 15, 20, 20);
    glPopMatrix();
    gluDeleteQuadric(quad);

    color(0x004B0D);
    glPushMatrix();
    glTranslated(0, 1, 0);
    glRotated(90, 1, 0, 0);
    glutSolidCone(2, 2, 20, 20);
    glPopMatrix();

    color(128 + 128 * colorBrightness.getValue(), 128 + 128 * colorBrightness.getValue(), 0);
    glPushMatrix();
    glTranslated(0, 3, 0);
    glScaled(1 + lampScale.getValue(), 1 + lampScale.getValue(), 1 + lampScale.getValue());
    glutSolidSphere(2, 255, 255);
    glPopMatrix();

    glPopMatrix();
}

void Lamp::onKeyPressed(unsigned char key, int mouseX, int mouseY) {
    if (key == '4') {
        Sounds::togglePlay(Sounds::lampSound);
        colorBrightness.toggle();
        lampScale.toggle();
    }
}

void Lamp::onIdle() {
    colorBrightness.animate();
    lampScale.animate();
}

