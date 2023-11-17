#include <GLUT/glut.h>
#include "Swing.h"
#include "utils.h"
#include "Sounds.h"


Swing::Swing()
        : GameObject({15, 10, 10}),
          swingAngle({0, 45, 1, true}) {}

void Swing::draw() {
    glPushMatrix();
    glTranslatef(0, 5, 0);

    glPushMatrix();
    glTranslatef(0, 10, 0);
    glRotated(swingAngle.getValue(), 1, 0, 0);
    glTranslatef(0, -10, 0);

    // Draw the seat
    color(0xFBFF57);
    glPushMatrix();
    glScalef(7.5, 0.5, 7.5);
    glutSolidCube(1);
    glPopMatrix();

    // Draw the left rope
    color(0x000000);
    glPushMatrix();
    glTranslatef(-3.75, 5, 0);
    glScalef(0.25, 10, 0.25);
    glutSolidCube(1);
    glPopMatrix();

    // Draw the right rope
    glPushMatrix();
    glTranslatef(3.75, 5, 0);
    glScalef(0.25, 10, 0.25);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();

    // Draw the left pole
    color(0x8B4513);
    glPushMatrix();
    glTranslatef(-7.5, 2.5, 0);
    glScalef(0.5, 15, 0.5);
    glutSolidCube(1);
    glPopMatrix();

    // Draw the right pole
    glPushMatrix();
    glTranslatef(7.5, 2.5, 0);
    glScalef(0.5, 15, 0.5);
    glutSolidCube(1);
    glPopMatrix();

    // Draw the top pole
    glPushMatrix();
    glTranslatef(0, 10, 0);
    glScalef(15, 0.5, 0.5);
    glutSolidCube(1);
    glPopMatrix();

    glPopMatrix();
}

void Swing::onKeyPressed(unsigned char key, int mouseX, int mouseY) {
    if (key == '3') {
        Sounds::togglePlay(Sounds::swingSound);
        swingAngle.toggle();
    }
}

void Swing::onIdle() {
    swingAngle.animate();
}

