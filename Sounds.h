//
// Created by vanes on 11/29/2021.
//

#ifndef BUTTON_H_LOADEDASSETS_H
#define BUTTON_H_LOADEDASSETS_H
#include "Assets.h"


class Sounds {
    // A static class that binds sf::Sound objects to their respective sf::SoundBuffers
public:
    static void bindSounds();

    static std::map<AssetName, sf::Sound> sounds;

};


#endif //BUTTON_H_LOADEDASSETS_H
