#ifndef GRAPHICSASSIGNMENT2_SWING_H
#define GRAPHICSASSIGNMENT2_SWING_H


#include "GameObject.h"

class Swing : public GameObject {
private:
    float swingAngle = 0;
    float animationSpeed = 1;
    bool shouldRotate = false;
public:
    void draw() override;

    void onKeyPressed(unsigned char key, int mouseX, int mouseY) override;

    void onIdle() override;
};


#endif //GRAPHICSASSIGNMENT2_SWING_H
