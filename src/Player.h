#ifndef GRAPHICSASSIGNMENT2_PLAYER_H
#define GRAPHICSASSIGNMENT2_PLAYER_H

#include "GameObject.h"

enum PlayerMovement {
    FORWARD,
    BACKWARD
};

class Player : public GameObject {
    Vector3f direction{0, 0, -0.5};
    PlayerMovement latestMovement;
public:
    Player();

    void draw() override;

    void onSpecialKeyPressed(int key, int mouseX, int mouseY) override;

    void onCollision(GameObject *&pObject) override;
};


#endif //GRAPHICSASSIGNMENT2_PLAYER_H
