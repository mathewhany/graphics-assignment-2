#ifndef GRAPHICSASSIGNMENT2_GAMESCENE_H
#define GRAPHICSASSIGNMENT2_GAMESCENE_H

#include <vector>
#include "GameObject.h"

class GameScene {
protected:
    std::vector<GameObject *> gameObjects;
public:
    virtual ~GameScene() = default;

    virtual void draw();

    virtual void onKeyPressed(unsigned char key, int mouseX, int mouseY);

    virtual void onSpecialKeyPressed(int key, int mouseX, int mouseY);

    void onIdle();
};


#endif //GRAPHICSASSIGNMENT2_GAMESCENE_H
