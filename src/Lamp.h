#ifndef GRAPHICSASSIGNMENT2_LAMP_H
#define GRAPHICSASSIGNMENT2_LAMP_H


#include "GameObject.h"

class Lamp : public GameObject {
    double colorBrightness = 1;
    bool shouldAnimate = false;
    double colorAnimationSpeed = 0.01;
    double lampScale = 0;
    double scaleAnimationSpeed = 0.01;
public:
    void draw() override;

    void onKeyPressed(unsigned char key, int mouseX, int mouseY) override;

    void onIdle() override;
};


#endif //GRAPHICSASSIGNMENT2_LAMP_H
