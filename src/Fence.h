#ifndef GRAPHICSASSIGNMENT2_FENCE_H
#define GRAPHICSASSIGNMENT2_FENCE_H


#include "GameObject.h"

class Fence : public GameObject {
    double units;
    bool alongX;
public:
    Fence(const Vector3f &position, double units, bool alongX);

    void draw() override;
};


#endif //GRAPHICSASSIGNMENT2_FENCE_H
