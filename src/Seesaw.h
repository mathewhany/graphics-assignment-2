#ifndef GRAPHICSASSIGNMENT2_SEESAW_H
#define GRAPHICSASSIGNMENT2_SEESAW_H


#include "GameObject.h"

class Seesaw : public GameObject {
    bool shouldMove = false;
    double angle = 0;
    double angleStep = 0.5;
public:
    Seesaw(Vector3f position);

    void draw() override;

    void onKeyPressed(unsigned char key, int mouseX, int mouseY) override;

    void onIdle() override;
};


#endif //GRAPHICSASSIGNMENT2_SEESAW_H
