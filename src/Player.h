#ifndef GRAPHICSASSIGNMENT2_PLAYER_H
#define GRAPHICSASSIGNMENT2_PLAYER_H

#include "GameObject.h"

class Player : public GameObject {
    Vector3f direction{0, 0, -1};
public:
    Player();

    void draw() override;

    void onSpecialKeyPressed(int key, int mouseX, int mouseY) override;

    void onCollision(GameObject *&pObject) override;
};


#endif //GRAPHICSASSIGNMENT2_PLAYER_H
