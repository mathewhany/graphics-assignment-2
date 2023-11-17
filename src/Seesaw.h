#ifndef GRAPHICSASSIGNMENT2_SEESAW_H
#define GRAPHICSASSIGNMENT2_SEESAW_H


#include "GameObject.h"
#include "AnimatingValue.h"

class Seesaw : public GameObject {
    AnimatingValue angle;
public:
    Seesaw();

    void draw() override;

    void onKeyPressed(unsigned char key, int mouseX, int mouseY) override;

    void onIdle() override;
};


#endif //GRAPHICSASSIGNMENT2_SEESAW_H
