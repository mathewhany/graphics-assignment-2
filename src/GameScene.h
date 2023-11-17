#ifndef GRAPHICSASSIGNMENT2_GAMESCENE_H
#define GRAPHICSASSIGNMENT2_GAMESCENE_H

#include <vector>
#include "GameObject.h"
#include "Camera.h"
#include "GameSettings.h"
#include "Game.h"

class Game;

class GameScene {
protected:
    Camera camera;
    std::vector<GameObject *> gameObjects;
public:
    GameScene();

    virtual ~GameScene() = default;

    virtual void draw();

    virtual void onKeyPressed(unsigned char key, int mouseX, int mouseY);

    virtual void onSpecialKeyPressed(int key, int mouseX, int mouseY);

    void onIdle();

    virtual void setupLights();

    [[nodiscard]] const Camera &getCamera() const;

    virtual void onTimer(int value);
};


#endif //GRAPHICSASSIGNMENT2_GAMESCENE_H
