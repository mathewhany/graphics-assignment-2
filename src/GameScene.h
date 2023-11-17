#ifndef GRAPHICSASSIGNMENT2_GAMESCENE_H
#define GRAPHICSASSIGNMENT2_GAMESCENE_H

#include <vector>
#include <string>
#include "GameObject.h"
#include "Camera.h"
#include "GameSettings.h"
#include "Game.h"

class Game;

class GameObject;

class GameScene {
protected:
    Camera camera;
    std::unordered_map<std::string, GameObject *> gameObjects;
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

    template<class T>
    T *getGameObjectByTag(const std::string &tag) const {
        if (gameObjects.find(tag) == gameObjects.end()) {
            return nullptr;
        }

        return dynamic_cast<T *>(gameObjects.at(tag));
    }
};


#endif //GRAPHICSASSIGNMENT2_GAMESCENE_H
