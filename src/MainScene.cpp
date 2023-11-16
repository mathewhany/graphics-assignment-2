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

MainScene::MainScene() {
    gameObjects.push_back(
            (new Player)
                ->withPosition({0, 0, 30})
    );

    gameObjects.push_back(
            (new Ground)
                    ->withScale({10, -1, 10})
    );

    gameObjects.push_back(
            (new FerrisWheel)
                    ->withPosition({-10, 0, -10})
                    ->withScale({0.8, 0.8, 0.8})
    );

    gameObjects.push_back(
            (new Fence)
                    ->withPosition({0, 0, -30})
                    ->withScale({1.4, 1.4, 1.4})
                    ->withAngle({0, 90, 0})
    );

    gameObjects.push_back(
            (new Fence)
                    ->withPosition({30, 0, 0})
                    ->withScale({1.4, 1.4, 1.4})
    );

    gameObjects.push_back(
            (new Fence)
                    ->withPosition({-30, 0, 0})
                    ->withScale({1.4, 1.4, 1.4})
    );

    gameObjects.push_back(
            (new Seesaw)
                    ->withPosition({20, 0, 10})
                    ->withAngle({0, 45, 0})
    );

    gameObjects.push_back(
            (new Lamp)
                    ->withPosition({-25, 0, 25})
                    ->withScale({0.8, 0.8, 0.8})
    );

    gameObjects.push_back(
            (new Swing)
                    ->withPosition({25, 0, 25})
                    ->withScale({0.8, 0.8, 0.8})
                    ->withAngle({0, 45, 0})
    );

    gameObjects.push_back(
            (new Roller)
                    ->withPosition({-15, 0, 10})
                    ->withScale({0.8, 0.8, 0.8})
    );

    gameObjects.push_back(
            (new Goal)
                ->withScale({0.8, 0.8, 0.8})
                ->withPosition({25, 0, -20})
    );
}
