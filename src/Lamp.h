#ifndef GRAPHICSASSIGNMENT2_LAMP_H
#define GRAPHICSASSIGNMENT2_LAMP_H


#include "GameObject.h"
#include "AnimatingValue.h"

class Lamp : public GameObject {
    AnimatingValue colorBrightness{1, 1, 0.01};
    AnimatingValue lampScale{0, 0.3, 0.01};
public:
    Lamp();

    void draw() override;

    void onKeyPressed(unsigned char key, int mouseX, int mouseY) override;

    void onIdle() override;
};


#endif //GRAPHICSASSIGNMENT2_LAMP_H
