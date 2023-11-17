#ifndef GRAPHICSASSIGNMENT2_FENCE_H
#define GRAPHICSASSIGNMENT2_FENCE_H


#include "GameObject.h"

class Fence : public GameObject {
    int currentColor = 0;
public:
    void onTimer(int value) override;

    void draw() override;
};


#endif //GRAPHICSASSIGNMENT2_FENCE_H
