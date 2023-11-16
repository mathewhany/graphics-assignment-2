#ifndef GRAPHICSASSIGNMENT2_FERRISWHEEL_H
#define GRAPHICSASSIGNMENT2_FERRISWHEEL_H


#include "GameObject.h"

class FerrisWheel : public GameObject {
    bool shouldMove = false;
    double rotation = 0;
public:
    void draw() override;

    void onIdle() override;

    void onKeyPressed(unsigned char key, int mouseX, int mouseY) override;
};


#endif //GRAPHICSASSIGNMENT2_FERRISWHEEL_H
