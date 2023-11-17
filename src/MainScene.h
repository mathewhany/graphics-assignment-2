#ifndef GRAPHICSASSIGNMENT2_MAINSCENE_H
#define GRAPHICSASSIGNMENT2_MAINSCENE_H

#include <SFML/Audio.hpp>
#include "GameScene.h"

class MainScene : public GameScene {
public:
    MainScene();

    void onTimer(int value) override;
};


#endif //GRAPHICSASSIGNMENT2_MAINSCENE_H
