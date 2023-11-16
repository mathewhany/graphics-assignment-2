#ifndef GRAPHICSASSIGNMENT2_GROUND_H
#define GRAPHICSASSIGNMENT2_GROUND_H

#include "GameObject.h"

class Ground : public GameObject {
public:
explicit Ground(Vector3f position);
    void draw() override;
};


#endif //GRAPHICSASSIGNMENT2_GROUND_H
