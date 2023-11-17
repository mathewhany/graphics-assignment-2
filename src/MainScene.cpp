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
#include "Sounds.h"
#include "GameWin.h"
#include "Score.h"

MainScene::MainScene() {
    gameObjects["player"] = (new Player)
            ->setPosition({0, 0, 27})
            ->setScale({0.8, 0.8, 0.8});

    gameObjects["ground"] = (new Ground)
            ->setScale({10, -1, 10});

    gameObjects["ferris-wheel"] = (new FerrisWheel)
            ->setPosition({-20, 0, -20})
            ->setScale({0.8, 0.8, 0.8});

    gameObjects["fence"] = (new Fence)
            ->setPosition({0, 0, -30})
            ->setScale({1.4, 1.4, 1.4})
            ->setAngle({0, 90, 0});

    gameObjects["fence1"] = (new Fence)
            ->setPosition({30, 0, 0})
            ->setScale({1.4, 1.4, 1.4});

    gameObjects["fence2"] = (new Fence)
            ->setPosition({-30, 0, 0})
            ->setScale({1.4, 1.4, 1.4});

    gameObjects["fence3"] = (new Seesaw)
            ->setPosition({15, 0, 0});

    gameObjects["lamp"] = (new Lamp)
            ->setPosition({20, 0, 20})
            ->setScale({0.8, 0.8, 0.8});

    gameObjects["swing"] = (new Swing)
            ->setPosition({-20, 0, 10})
            ->setScale({0.8, 0.8, 0.8});

    gameObjects["roller"] = (new Roller)
            ->setPosition({0, 0, -20})
            ->setScale({0.8, 0.8, 0.8});

    gameObjects["goal1"] = (new Goal)
            ->setScale({0.8, 0.8, 0.8})
            ->setPosition({25, 0, -20});


    gameObjects["goal2"] = (new Goal)
            ->setScale({0.8, 0.8, 0.8})
            ->setPosition({-25, 0, 25});

    gameObjects["goal3"] = (new Goal)
            ->setScale({0.8, 0.8, 0.8})
            ->setPosition({10, 0, 10});

    camera.setEye({0, 30, 70});
    camera.setCenter({0, 0, 0});
    camera.setUp({0, 1, 0});

    // Invisible Walls
    gameObjects["bound1"] = (new GameObject({1, 1, 1}))
            ->setPosition({-30, 0, 0})
            ->setScale({2, 3, 100});
    gameObjects["bound2"] = (new GameObject({1, 1, 1}))
            ->setPosition({30, 0, 0})
            ->setScale({2, 3, 100});
    gameObjects["bound3"] = (new GameObject({1, 1, 1}))
            ->setPosition({0, 0, -30})
            ->setScale({100, 3, 2});
    gameObjects["bound4"] = (new GameObject({1, 1, 1}))
            ->setPosition({0, 0, 30})
            ->setScale({100, 3, 2});

    gameObjects["game-time"] = (new GameTimer)
            ->setPosition({15, 25, -20});

    gameObjects["game-win"] = (new GameWin)
            ->setShowing(false)
            ->setPosition({0, 20, 0});

    gameObjects["score"] = (new Score)
            ->setPosition({0, 25, -20});

    Sounds::resetAndPlay(Sounds::mainTheme);
}

void MainScene::onTimer(int value) {
    GameScene::onTimer(value);

    if (value > 60 && !gameObjects["game-win"]->isShowing()) {
        Sounds::mainTheme.stop();
        Game::getInstance()->setScene(new GameOverScene());
    }
}
