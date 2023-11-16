#ifndef GRAPHICSASSIGNMENT2_GAME_H
#define GRAPHICSASSIGNMENT2_GAME_H

#include "Camera.h"
#include "GameScene.h"

class Game {
    Camera camera;
    GameScene *scene;
    int windowWidth;
    int windowHeight;
public:
    Game(Camera camera, GameScene *scene, int windowWidth, int windowHeight);

    void draw();

    void setScene(GameScene *newScene);

    void onKeyPressed(unsigned char key, int mouseX, int mouseY);

    void onSpecialKeyPressed(int key, int mouseX, int mouseY);

    [[nodiscard]] const int& getWindowWidth() const;

    [[nodiscard]] const int& getWindowHeight() const;

    void init(int argc, char **argv) const;

    void setupLights() const;

    void onIdle();
};


#endif //GRAPHICSASSIGNMENT2_GAME_H
