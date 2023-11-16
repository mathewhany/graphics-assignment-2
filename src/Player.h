#ifndef GRAPHICSASSIGNMENT2_PLAYER_H
#define GRAPHICSASSIGNMENT2_PLAYER_H

#include "GameObject.h"

class Player : public GameObject {
public:
    explicit Player(Vector3f position);

    void draw() override;

    void onIdle() override;

    void onSpecialKeyPressed(int key, int mouseX, int mouseY) override;
};


#endif //GRAPHICSASSIGNMENT2_PLAYER_H
