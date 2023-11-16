#include <GLUT/glut.h>
#include "Ground.h"
#include "utils.h"

Ground::Ground(Vector3f position)
        : GameObject(position, {100, 1, 100}) {}

void Ground::draw() {
    glPushMatrix();
    glScaled(50, 1, 50);
    color(27, 105, 0);
    glutSolidCube(1);
    glPopMatrix();
}

