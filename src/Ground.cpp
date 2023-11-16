#include <GLUT/glut.h>
#include "Ground.h"
#include "utils.h"

void Ground::draw() {
    glPushMatrix();
    glTranslatef(0, 0.5, 0);
    glScaled(50, 1, 50);
    color(27, 105, 0);
    glutSolidCube(1);
    glPopMatrix();
}

