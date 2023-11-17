#include "MainScene.h"
#include "Player.h"
#include "Ground.h"
#include "Fence.h"
#include "FerrisWheel.h"
#include "Seesaw.h"
#include "Lamp.h"
#include "Swing.h"
#include "Roller.h"
#include "Goal.h"
#include "GameTimer.h"
#include "GameOverScene.h"

MainScene::MainScene() {
    gameObjects.push_back(
            (new Player)
                    ->setPosition({0, 0, 27})
                    ->setScale({0.8, 0.8, 0.8})
    );

    gameObjects.push_back(
            (new Ground)
                    ->setScale({10, -1, 10})
    );

    gameObjects.push_back(
            (new FerrisWheel)
                    ->setPosition({-20, 0, -20})
                    ->setScale({0.8, 0.8, 0.8})
    );

    gameObjects.push_back(
            (new Fence)
                    ->setPosition({0, 0, -30})
                    ->setScale({1.4, 1.4, 1.4})
                    ->setAngle({0, 90, 0})
    );

    gameObjects.push_back(
            (new Fence)
                    ->setPosition({30, 0, 0})
                    ->setScale({1.4, 1.4, 1.4})
    );

    gameObjects.push_back(
            (new Fence)
                    ->setPosition({-30, 0, 0})
                    ->setScale({1.4, 1.4, 1.4})
    );

    gameObjects.push_back(
            (new Seesaw)
                    ->setPosition({15, 0, 0})
    );

    gameObjects.push_back(
            (new Lamp)
                    ->setPosition({20, 0, 20})
                    ->setScale({0.8, 0.8, 0.8})
    );

    gameObjects.push_back(
            (new Swing)
                    ->setPosition({-20, 0, 10})
                    ->setScale({0.8, 0.8, 0.8})
    );

    gameObjects.push_back(
            (new Roller)
                    ->setPosition({0, 0, -20})
                    ->setScale({0.8, 0.8, 0.8})
    );

    gameObjects.push_back(
            (new Goal)
                    ->setScale({0.8, 0.8, 0.8})
                    ->setPosition({25, 0, -20})
    );

    camera.setEye({0, 30, 70});
    camera.setCenter({0, 0, 0});
    camera.setUp({0, 1, 0});

    // Invisible Walls
    gameObjects.push_back(
            (new GameObject({1, 1, 1}))
                    ->setPosition({-30, 0, 0})
                    ->setScale({2, 3, 100})
    );
    gameObjects.push_back(
            (new GameObject({1, 1, 1}))
                    ->setPosition({30, 0, 0})
                    ->setScale({2, 3, 100})
    );
    gameObjects.push_back(
            (new GameObject({1, 1, 1}))
                    ->setPosition({0, 0, -30})
                    ->setScale({100, 3, 2})
    );
    gameObjects.push_back(
            (new GameObject({1, 1, 1}))
                    ->setPosition({0, 0, 30})
                    ->setScale({100, 3, 2})
    );

    gameObjects.push_back(
            (new GameTimer())
                    ->setPosition({15, 25, -20})
    );
}

void MainScene::onTimer(int value) {
    GameScene::onTimer(value);

    if (value > 60) {
        Game::getInstance()->setScene(new GameOverScene());
    }
}
