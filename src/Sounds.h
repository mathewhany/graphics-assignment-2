#ifndef GRAPHICSASSIGNMENT2_SOUNDS_H
#define GRAPHICSASSIGNMENT2_SOUNDS_H


#include "SFML/Audio/Music.hpp"

class Sounds {
public:
    static sf::Music mainTheme;
    static sf::Music gameOverTheme;
    static sf::Music gameWinTheme;

    static sf::Music buttonClick;

    static sf::Music lampSound;
    static sf::Music rollerSound;
    static sf::Music swingSound;
    static sf::Music balloonSound;
    static sf::Music seeSawSound;
    static sf::Music wheelSound;

    static int loadSounds();

    static void resetAndPlay(sf::Music &music);

    static void togglePlay(sf::Music &music);
};


#endif //GRAPHICSASSIGNMENT2_SOUNDS_H
