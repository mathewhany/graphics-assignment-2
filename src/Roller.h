#ifndef GRAPHICSASSIGNMENT2_ROLLER_H
#define GRAPHICSASSIGNMENT2_ROLLER_H


#include "GameObject.h"
#include "AnimatingValue.h"

class Roller : public GameObject {
    AnimatingValue rotation{0, 360, 0.5};

public:
    Roller();

    void draw() override;

    void onIdle() override;

    void onKeyPressed(unsigned char key, int mouseX, int mouseY) override;
};


#endif //GRAPHICSASSIGNMENT2_ROLLER_H
