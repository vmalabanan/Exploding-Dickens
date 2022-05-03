//
// Created by vanes on 11/29/2021.
//

#include "Sounds.h"

void Sounds::bindSounds() {
    // Button sounds
    sounds[BUTTON_ROLLOVER].setBuffer(Assets<sf::SoundBuffer>::getAsset(BUTTON_ROLLOVER));
    sounds[WOODEN_CLICK].setBuffer(Assets<sf::SoundBuffer>::getAsset(WOODEN_CLICK));

    // General card sounds
    sounds[PLAY_CARD].setBuffer(Assets<sf::SoundBuffer>::getAsset(PLAY_CARD));
    sounds[TAKE_CARD].setBuffer(Assets<sf::SoundBuffer>::getAsset(TAKE_CARD));
    sounds[CARD_SHUFFLE].setBuffer(Assets<sf::SoundBuffer>::getAsset(CARD_SHUFFLE));
    sounds[BLURB_POP].setBuffer(Assets<sf::SoundBuffer>::getAsset(BLURB_POP));
    sounds[CARD_ROLLOVER].setBuffer(Assets<sf::SoundBuffer>::getAsset(CARD_ROLLOVER));

    // Game sounds
    sounds[INTRO_WHISTLE].setBuffer(Assets<sf::SoundBuffer>::getAsset(INTRO_WHISTLE));
    sounds[EXPLOSION].setBuffer(Assets<sf::SoundBuffer>::getAsset(EXPLOSION));
    sounds[CHIMES].setBuffer(Assets<sf::SoundBuffer>::getAsset(CHIMES));
    sounds[HIDING_DICKENS_CARD].setBuffer(Assets<sf::SoundBuffer>::getAsset(HIDING_DICKENS_CARD));

    // Charles' sounds
    sounds[CHARLES_YOUR_TURN].setBuffer(Assets<sf::SoundBuffer>::getAsset(CHARLES_YOUR_TURN));
    sounds[CHARLES_GOOD_LUCK].setBuffer(Assets<sf::SoundBuffer>::getAsset(CHARLES_GOOD_LUCK));
    sounds[CHARLES_GOOD_GAME].setBuffer(Assets<sf::SoundBuffer>::getAsset(CHARLES_GOOD_GAME));
    sounds[CHARLES_YOU_SHALL_NEVER].setBuffer(Assets<sf::SoundBuffer>::getAsset(CHARLES_YOU_SHALL_NEVER));
    sounds[CHARLES_CRYING].setBuffer(Assets<sf::SoundBuffer>::getAsset(CHARLES_CRYING));

    // Sounds upon playing certain cards
    // Exploding Dickens
    sounds[RED_ALERT].setBuffer(Assets<sf::SoundBuffer>::getAsset(RED_ALERT));

    // Defuse 1
    sounds[DICKENS_WHAT_GREATER_GIFT].setBuffer(Assets<sf::SoundBuffer>::getAsset(DICKENS_WHAT_GREATER_GIFT));

    // Defuse 2
    sounds[GRIP_IM_A_DEVIL].setBuffer(Assets<sf::SoundBuffer>::getAsset(GRIP_IM_A_DEVIL));
    sounds[RAVEN].setBuffer(Assets<sf::SoundBuffer>::getAsset(RAVEN));

    // Defuse 3
    sounds[DICKENS_SHINY].setBuffer(Assets<sf::SoundBuffer>::getAsset(DICKENS_SHINY));

    // See the future
    sounds[SEE_THE_FUTURE_SOUND].setBuffer(Assets<sf::SoundBuffer>::getAsset(SEE_THE_FUTURE_SOUND));

    // Steal a card
    sounds[SWIPE].setBuffer(Assets<sf::SoundBuffer>::getAsset(SWIPE));

    // Skip
    sounds[PING].setBuffer(Assets<sf::SoundBuffer>::getAsset(PING));

    // Draw from bottom
    sounds[WOOSH].setBuffer(Assets<sf::SoundBuffer>::getAsset(WOOSH));

    // Double slap
    sounds[PUNCH].setBuffer(Assets<sf::SoundBuffer>::getAsset(PUNCH));
}

std::map<AssetName, sf::Sound> Sounds::sounds {

};

