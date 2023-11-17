#ifndef GRAPHICSASSIGNMENT2_GAMETIMER_H
#define GRAPHICSASSIGNMENT2_GAMETIMER_H


#include "GameObject.h"

class GameTimer : public GameObject {
    int time;
public:
    void draw() override;

    void onTimer(int value) override;
};


#endif //GRAPHICSASSIGNMENT2_GAMETIMER_H
