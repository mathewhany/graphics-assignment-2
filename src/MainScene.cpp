#include "MainScene.h"
#include "Player.h"
#include "Ground.h"
#include "Fence.h"
#include "FerrisWheel.h"
#include "Seesaw.h"
#include "Lamp.h"

MainScene::MainScene() {
    auto *player = new Player({25, 5, 25});
    gameObjects.push_back(player);

    auto *ground = new Ground({0, 0, 0});
    ground->setScale({1.25, 1, 1.25});
    gameObjects.push_back(ground);

    auto *ferrisWheel = new FerrisWheel({-10, 6, -10});
    ferrisWheel->setScale({0.8, 0.8, 0.8});
    gameObjects.push_back(ferrisWheel);

    auto *topRight = new Fence({0, 0.5, -30}, 1.4, true);
    gameObjects.push_back(topRight);

    auto *topLeft = new Fence({-30, 0.5, 0}, 1.4, false);
    gameObjects.push_back(topLeft);

    auto *bottomRight = new Fence({30, 0.5, 0}, 1.4, false);
    gameObjects.push_back(bottomRight);

    auto *seesaw = new Seesaw({15, 1.25, -10});
    gameObjects.push_back(seesaw);

    auto *lamp = new Lamp({-25, 10, 25});
    lamp->setScale({0.8, 0.8, 0.8});
    gameObjects.push_back(lamp);
}
