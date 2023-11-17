#ifndef GRAPHICSASSIGNMENT2_FERRISWHEEL_H
#define GRAPHICSASSIGNMENT2_FERRISWHEEL_H


#include "GameObject.h"
#include "AnimatingValue.h"

class FerrisWheel : public GameObject {
    AnimatingValue rotation;
public:
    explicit FerrisWheel();

    void draw() override;

    void onIdle() override;

    void onKeyPressed(unsigned char key, int mouseX, int mouseY) override;
};


#endif //GRAPHICSASSIGNMENT2_FERRISWHEEL_H
