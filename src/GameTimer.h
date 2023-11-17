#ifndef GRAPHICSASSIGNMENT2_GAMETIMER_H
#define GRAPHICSASSIGNMENT2_GAMETIMER_H


#include "GameObject.h"

class GameTimer : public GameObject {
    int time;
    bool running = true;
public:
    void draw() override;

    void onTimer(int value) override;

    bool isRunning() const;

    void setIsRunning(bool isRunning);
};


#endif //GRAPHICSASSIGNMENT2_GAMETIMER_H
