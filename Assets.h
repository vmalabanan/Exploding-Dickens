//
// Created by vanes on 11/18/2021.
//

#ifndef MAIN_CPP_ASSETS_H
#define MAIN_CPP_ASSETS_H

#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "AssetName.h"

template<class T>
class Assets {
    // For objects that are loaded to RAM (e.g., sf::Texture, sf::SoundBuffer, sf::Font, etc.)

public:
    // Calls loadAsset function and returns asset[AssetName]
    static T& getAsset(AssetName asset);

    friend class Card;
    friend class OpponentHand;
    friend class ExplodingDickens;

private:
    // Returns asset file path
    static std::string getAssetPath(AssetName asset);

    // Loads asset object to RAM and stores in assets map
    static void loadAsset(AssetName asset);

    // Map of AssetName to asset objects
    static std::map<AssetName, T> assets;
};

#include "Assets.cpp"
#endif //MAIN_CPP_ASSETS_H
