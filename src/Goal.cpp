#include <GLUT/glut.h>
#include "Goal.h"
#include "utils.h"

Goal::Goal() : GameObject({2, 20, 2}) {
    balloonHeight.start();
    balloonScale.start();
}

void drawBalloon(int c) {
    glPushMatrix();
    color(c);
    glScaled(1, 1.5, 1);
    glutSolidSphere(4, 255, 255);
    glPopMatrix();

    glPushMatrix();
    color(0xffffff);
    glTranslated(0, -10, 0);
    glScaled(0.2, 10, 0.2);
    glutSolidCube(1);
    glPopMatrix();
}

void Goal::draw() {
    glPushMatrix();
    glTranslated(-5, 20, 0);
    glTranslated(0, balloonHeight.getValue(), 0);
    glScaled(1 + balloonScale.getValue(), 1 + balloonScale.getValue(), 1 + balloonScale.getValue());
    glPushMatrix();
    glTranslated(10, 0, 0);
    glRotated(-20, 0, 0, 1);
    drawBalloon(0x91FF6A);
    glPopMatrix();


    glPushMatrix();
    glTranslated(5, 0, 5);
    glRotated(20, 1, 0, 0);
    drawBalloon(0xFF4146);
    glPopMatrix();

    glPushMatrix();
    glRotated(20, 0, 0, 1);
    drawBalloon(0x6983FF);
    glPopMatrix();

    glPushMatrix();
    glTranslated(5, -18, 0);
    glScaled(0.2, 10, 0.2);
    glutSolidCube(1);
    glPopMatrix();

    glPopMatrix();
}

void Goal::onIdle() {
    balloonHeight.animate();
    balloonScale.animate();
    rotateBy({0, 1, 0});
}
