#include <GLUT/glut.h>
#include "Fence.h"
#include "utils.h"

Fence::Fence(const Vector3f &position, double scale, bool alongX)
        : GameObject(position, {0, 0, static_cast<float>(units * 3)}),
          units(scale),
          alongX(alongX) {}

void Fence::draw() {
    glPushMatrix();

    if (alongX) {
        glRotated(90, 0, 1, 0);
    }

    glScaled(1, 1, units);

    glPushMatrix();
    glTranslatef(0, 1.5, -20);
    glPushMatrix();
    glTranslatef(0, 1.5, 0);
    glRotated(-90, 1, 0, 0);
    color(182, 107, 0);
    glutSolidCone(0.7, 0.7, 255, 255);
    glPopMatrix();
    glPushMatrix();
    glScaled(0.5, 3, 0.5);
    color(182, 107, 0);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 1, 0);
    glScaled(0.5, 0.5, 40);
    color(182, 107, 0);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 2, 0);
    glScaled(0.5, 0.5, 40);
    color(182, 107, 0);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 1.5, 20);
    glPushMatrix();
    glTranslatef(0, 1.5, 0);
    glRotated(-90, 1, 0, 0);
    color(182, 107, 0);
    glutSolidCone(0.7, 0.7, 255, 255);
    glPopMatrix();
    glPushMatrix();
    glScaled(0.5, 3, 0.5);
    color(182, 107, 0);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
}