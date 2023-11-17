#ifndef GRAPHICSASSIGNMENT2_GAME_H
#define GRAPHICSASSIGNMENT2_GAME_H

#include "Camera.h"
#include "GameScene.h"

class GameScene;
class GameSettings;

class Game {
    int score = 0;

    GameScene *scene{};
    GameSettings *gameSettings;
    static Game *instance;

    explicit Game(GameSettings *gameSettings);

public:

    void draw();

    void setScene(GameScene *newScene);

    void onKeyPressed(unsigned char key, int mouseX, int mouseY);

    void onSpecialKeyPressed(int key, int mouseX, int mouseY);

    void init(int argc, char **argv) const;

    void onIdle();

    void onTimer(int value);

    [[nodiscard]] GameSettings *getGameSettings() const;

    static Game *getInstance(GameSettings *settings = nullptr);

    [[nodiscard]] GameScene *getScene() const;

    void setScore(int score);

    int getScore() const;
};


#endif //GRAPHICSASSIGNMENT2_GAME_H
