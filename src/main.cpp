#include <GLUT/glut.h>
#include <cstdlib>
#include "Camera.h"
#include "MainScene.h"
#include "Game.h"

Camera camera({0, 35, 70}, {0, 0, 0}, {0.0, 1.0, 0.0}, 1);
MainScene *scene = new MainScene();

Game game(camera, scene, 1024, 1024);

//
//void drawWall(double thickness) {
//    glPushMatrix();
//    glTranslated(0.5, 0.5 * thickness, 0.5);
//    glScaled(1.0, thickness, 1.0);
//    glutSolidCube(1);
//    glPopMatrix();
//}
//
//void drawTableLeg(double thick, double len) {
//    glPushMatrix();
//    glTranslated(0, len / 2, 0);
//    glScaled(thick, len, thick);
//    glutSolidCube(1.0);
//    glPopMatrix();
//}
//
//void drawJackPart() {
//    glPushMatrix();
//    glScaled(0.2, 0.2, 1.0);
//    glutSolidSphere(1, 15, 15);
//    glPopMatrix();
//    glPushMatrix();
//    glTranslated(0, 0, 1.2);
//    glutSolidSphere(0.2, 15, 15);
//    glTranslated(0, 0, -2.4);
//    glutSolidSphere(0.2, 15, 15);
//    glPopMatrix();
//}
//
//void drawJack() {
//    glPushMatrix();
//    drawJackPart();
//    glRotated(90.0, 0, 1, 0);
//    drawJackPart();
//    glRotated(90.0, 1, 0, 0);
//    drawJackPart();
//    glPopMatrix();
//}
//
//void drawTable(double topWid, double topThick, double legThick, double legLen) {
//    glPushMatrix();
//    glTranslated(0, legLen, 0);
//    glScaled(topWid, topThick, topWid);
//    glutSolidCube(1.0);
//    glPopMatrix();
//
//    double dist = 0.95 * topWid / 2.0 - legThick / 2.0;
//    glPushMatrix();
//    glTranslated(dist, 0, dist);
//    drawTableLeg(legThick, legLen);
//    glTranslated(0, 0, -2 * dist);
//    drawTableLeg(legThick, legLen);
//    glTranslated(-2 * dist, 0, 2 * dist);
//    drawTableLeg(legThick, legLen);
//    glTranslated(0, 0, -2 * dist);
//    drawTableLeg(legThick, legLen);
//    glPopMatrix();
//}
//
//void display() {
//    glPushMatrix();
//    glTranslated(0.4, 0.4, 0.6);
//    glRotated(45, 0, 0, 1);
//    glScaled(0.08, 0.08, 0.08);
//    drawJack();
//    glPopMatrix();
//    glPushMatrix();
//    glTranslated(0.6, 0.38, 0.5);
//    glRotated(30, 0, 1, 0);
//    glutSolidTeapot(0.08);
//    glPopMatrix();
//    glPushMatrix();
//    glTranslated(0.25, 0.42, 0.35);
//    glutSolidSphere(0.1, 15, 15);
//    glPopMatrix();
//    glPushMatrix();
//    glTranslated(0.4, 0.0, 0.4);
//    drawTable(0.6, 0.02, 0.02, 0.3);
//    glPopMatrix();
//    drawWall(0.02);
//    glPushMatrix();
//    glRotated(90, 0, 0, 1.0);
//    drawWall(0.02);
//    glPopMatrix();
//    glPushMatrix();
//    glRotated(-90, 1.0, 0.0, 0.0);
//    drawWall(0.02);
//    glPopMatrix();
//}

//void keyboard(unsigned char key, int mouseX, int mouseY) {
//    float d = 0.01;
//
//    switch (key) {
//        case 'w':
//            camera.moveY(d);
//            break;
//        case 's':
//            camera.moveY(-d);
//            break;
//        case 'a':
//            camera.moveX(d);
//            break;
//        case 'd':
//            camera.moveX(-d);
//            break;
//        case 'q':
//            camera.moveZ(d);
//            break;
//        case 'e':
//            camera.moveZ(-d);
//            break;
//
//        case GLUT_KEY_ESCAPE:
//            exit(EXIT_SUCCESS);
//    }
//
//    glutPostRedisplay();
//    game.onKeyPressed(key, mouseX, mouseY);
//}

//void special(int key, int mouseX, int mouseY) {
//    float a = 1.0;
//
//    switch (key) {
//        case GLUT_KEY_UP:
//            camera.rotateX(a);
//            break;
//        case GLUT_KEY_DOWN:
//            camera.rotateX(-a);
//            break;
//        case GLUT_KEY_LEFT:
//            camera.rotateY(a);
//            break;
//        case GLUT_KEY_RIGHT:
//            camera.rotateY(-a);
//            break;
//    }
//
//    glutPostRedisplay();
//    game.onSpecialKeyPressed(key, mouseX, mouseY);
//}

int main(int argc, char **argv) {
    game.init(argc, argv);

    glutDisplayFunc([]() {
        game.draw();
    });

    glutKeyboardFunc([](unsigned char key, int mouseX, int mouseY) {
        game.onKeyPressed(key, mouseX, mouseY);
    });

    glutSpecialFunc([](int key, int mouseX, int mouseY) {
        game.onSpecialKeyPressed(key, mouseX, mouseY);
    });

    glutIdleFunc([]() {
        game.onIdle();
    });

    glutMainLoop();

    return EXIT_SUCCESS;
}
