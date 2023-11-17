#include <GLUT/glut.h>
#include "GameWin.h"
#include "utils.h"

void GameWin::draw() {
    glPushMatrix();
    glTranslated(-5, 0, 0);
    drawText("You win!", 0, 0, 0x000000);
    glPopMatrix();
}

