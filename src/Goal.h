#ifndef GRAPHICSASSIGNMENT2_GOAL_H
#define GRAPHICSASSIGNMENT2_GOAL_H


#include "GameObject.h"
#include "AnimatingValue.h"

class Goal : public GameObject {
    AnimatingValue balloonHeight{0, 2, 0.01};
    AnimatingValue balloonScale{0, 0.1, 0.001};
public:
    Goal();

    void draw() override;

    void onIdle() override;
};


#endif //GRAPHICSASSIGNMENT2_GOAL_H
