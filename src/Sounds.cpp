#include "Sounds.h"

sf::Music Sounds::mainTheme;
sf::Music Sounds::gameOverTheme;
sf::Music Sounds::gameWinTheme;

sf::Music Sounds::buttonClick;

sf::Music Sounds::lampSound;
sf::Music Sounds::rollerSound;
sf::Music Sounds::swingSound;
sf::Music Sounds::balloonSound;
sf::Music Sounds::seeSawSound;
sf::Music Sounds::wheelSound;

int Sounds::loadSounds() {
    if (!mainTheme.openFromFile("resources/main.ogg")) {
        return -1;
    }
    mainTheme.setVolume(30);

    if (!gameOverTheme.openFromFile("resources/gameover.ogg")) {
        return -1;
    }

    if (!gameWinTheme.openFromFile("resources/gamewin.ogg")) {
        return -1;
    }

    if (!buttonClick.openFromFile("resources/button.ogg")) {
        return -1;
    }

    if (!lampSound.openFromFile("resources/lamp.ogg")) {
        return -1;
    }

    if (!rollerSound.openFromFile("resources/roller.ogg")) {
        return -1;
    }

    if (!swingSound.openFromFile("resources/swing.ogg")) {
        return -1;
    }

//    if (!balloonSound.openFromFile("resources/balloon.ogg")) {
//        return -1;
//    }

    if (!seeSawSound.openFromFile("resources/seesaw.ogg")) {
        return -1;
    }

    if (!wheelSound.openFromFile("resources/wheel.ogg")) {
        return -1;
    }

    return 0;
}

void Sounds::resetAndPlay(sf::Music &music) {
    if (music.getStatus() == sf::Music::Playing) {
        music.stop();
    }

    music.setPlayingOffset(sf::Time::Zero);
    music.play();
}

void Sounds::togglePlay(sf::Music &music) {
    if (music.getStatus() == sf::Music::Playing) {
        music.pause();
    } else {
        resetAndPlay(music);
    }
}