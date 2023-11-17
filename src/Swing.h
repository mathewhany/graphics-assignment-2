#ifndef GRAPHICSASSIGNMENT2_SWING_H
#define GRAPHICSASSIGNMENT2_SWING_H


#include "GameObject.h"
#include "AnimatingValue.h"

class Swing : public GameObject {
private:
    AnimatingValue swingAngle;
public:
    Swing();

    void draw() override;

    void onKeyPressed(unsigned char key, int mouseX, int mouseY) override;

    void onIdle() override;
};


#endif //GRAPHICSASSIGNMENT2_SWING_H
