#include <GLUT/GLUT.h>
#include "Lamp.h"
#include "utils.h"

Lamp::Lamp(Vector3f position)
    : GameObject(position, {1, 1, 1}) {}

void Lamp::draw() {
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

    color(128 + 128 * colorBrightness, 128 + 128 * colorBrightness, 0);
    glPushMatrix();
    glTranslated(0, 3, 0);
    glScaled(1 + lampScale, 1 + lampScale, 1 + lampScale);
    glutSolidSphere(2, 20, 20);
    glPopMatrix();
}

void Lamp::onKeyPressed(unsigned char key, int mouseX, int mouseY) {
    if (key == 'h') {
        shouldAnimate = !shouldAnimate;
    }
}

void Lamp::onIdle() {
    if (shouldAnimate) {
        colorBrightness += colorAnimationSpeed;
        lampScale += scaleAnimationSpeed;
        if (colorBrightness > 1 || colorBrightness < 0) {
            colorAnimationSpeed *= -1;
        }
        if (lampScale > 0.3 || lampScale < 0) {
            scaleAnimationSpeed *= -1;
        }
    }
    rotateBy({0, 0.5, 0});
}
