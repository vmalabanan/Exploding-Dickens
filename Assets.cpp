//
// Created by vanes on 11/18/2021.
//

#ifndef MAIN_CPP_ASSETS_CPP
#define MAIN_CPP_ASSETS_CPP
#include "Assets.h"

template<class T>
// Returns a sf::Texture, sf::Font, sf::Music, or sf::SoundBuffer object
T& Assets<T>::getAsset(AssetName asset) {
    loadAsset(asset);
    return assets[asset];
}

template<class T>
std::string Assets<T>::getAssetPath(AssetName asset){
    switch(asset)
    {
        // FONTS
        case BITTER_BOLD: return "Assets/Fonts/Bitter-Bold.otf";
        case OSWALD: return "Assets/Fonts/Oswald-VariableFont_wght.ttf";
        case PLAY_WITH_FIRE: return "Assets/Fonts/Play With Fire.ttf";

        // IMAGES
        // Cards
        case CARD_BACK: return "Assets/Images/Cards/card back.png";
        case GLOWING_CARD_BACK: return "Assets/Images/Cards/card back glow.png";
        case EXPLODING_DICKENS: return "Assets/Images/Cards/exploding dickens v2.png";
        case DEFUSE1: return "Assets/Images/Cards/defuse1.png";
        case DEFUSE2: return "Assets/Images/Cards/defuse2.png";
        case DEFUSE3: return "Assets/Images/Cards/defuse3.png";
        case DOUBLE_SLAP: return "Assets/Images/Cards/double slap1.png";
        case DRAW_FROM_BOTTOM: return "Assets/Images/Cards/draw from bottom1.png";
        case SEE_THE_FUTURE: return "Assets/Images/Cards/see the future1.png";
        case SHUFFLE: return "Assets/Images/Cards/shuffle1.png";
        case SKIP: return "Assets/Images/Cards/skip1.png";
        case STEAL_A_CARD: return "Assets/Images/Cards/steal a card1.png";

        // Smaller images of card fronts for player's hand
        case DEFUSE1_PH: return "Assets/Images/Cards/Player Hand/defuse1 ph.png";
        case DEFUSE2_PH: return "Assets/Images/Cards/Player Hand/defuse2 ph.png";
        case DEFUSE3_PH: return "Assets/Images/Cards/Player Hand/defuse3 ph.png";
        case DOUBLE_SLAP_PH: return "Assets/Images/Cards/Player Hand/double slap1 ph.png";
        case DRAW_FROM_BOTTOM_PH: return "Assets/Images/Cards/Player Hand/draw from bottom1 ph.png";
        case SEE_THE_FUTURE_PH: return "Assets/Images/Cards/Player Hand/see the future1 ph.png";
        case SHUFFLE_PH: return "Assets/Images/Cards/Player Hand/shuffle1.png";
        case SKIP_PH: return "Assets/Images/Cards/Player Hand/skip1 ph.png";
        case STEAL_A_CARD_PH: return "Assets/Images/Cards/Player Hand/steal a card1 ph.png";

        // Thumbnail image of card back for opponent's hand
        case OPPONENT_HAND_1: return "Assets/Images/Cards/Opponent Hand/opponent hand 1.png";
        case OPPONENT_HAND_2: return "Assets/Images/Cards/Opponent Hand/opponent hand 2.png";
        case OPPONENT_HAND_3: return "Assets/Images/Cards/Opponent Hand/opponent hand 3.png";
        case OPPONENT_HAND_4: return "Assets/Images/Cards/Opponent Hand/opponent hand 4.png";
        case OPPONENT_HAND_5: return "Assets/Images/Cards/Opponent Hand/opponent hand 5.png";

        // Card info blurbs
        case DEFUSE_BLURB: return "Assets/Images/Info Blurbs/defuse_blurb.png";
        case DOUBLE_SLAP_BLURB: return "Assets/Images/Info Blurbs/double slap_blurb.png";
        case DRAW_FROM_BOTTOM_BLURB: return "Assets/Images/Info Blurbs/draw from the bottom_blurb.png";
        case SEE_THE_FUTURE_BLURB: return "Assets/Images/Info Blurbs/see the future_blurb.png";
        case SHUFFLE_BLURB: return "Assets/Images/Info Blurbs/shuffle_blurb.png";
        case SKIP_BLURB: return "Assets/Images/Info Blurbs/skip_blurb.png";
        case STEAL_BLURB: return "Assets/Images/Info Blurbs/steal_blurb.png";

        // Charles' chat bubbles
        case GOOD_LUCK: return "Assets/Images/Charles' Chat Bubbles/good luck.png";
        case YOU_SHALL_NEVER: return "Assets/Images/Charles' Chat Bubbles/you shall never defeat me.png";
        case CRYING: return "Assets/Images/Charles' Chat Bubbles/crying.png";

        // Status blurbs
        case STATUS_SHUFFLING: return "Assets/Images/Status Blurbs/shuffling.png";
        case STATUS_HIDING: return "Assets/Images/Status Blurbs/hiding dickens.png";
        case STATUS_CHARLES_IS_STEALING: return "Assets/Images/Status Blurbs/stealing your card.png";
        case STATUS_CHARLES_DREW_EXPL_DICKENS: return "Assets/Images/Status Blurbs/charles drew expl dickens.png";
        case STATUS_CHARLES_IS_HIDING: return "Assets/Images/Status Blurbs/charles is hiding expl dickens.png";

        // Backgrounds
        case SPLASH_BG: return "Assets/Images/splash scrn bg.png";
        case WOOD_BG: return "Assets/Images/wood.png";

        // Screens
        case YOUR_TURN: return "Assets/Images/Screens/your turn.png";
        case SEE_FUTURE: return "Assets/Images/Screens/see the future.png";
        case DEFUSE_DICKENS: return "Assets/Images/Screens/defuse the exploding dickens.png";
        case YOU_EXPLODED: return "Assets/Images/Screens/you have exploded.png";
        case YOU_WON: return "Assets/Images/Screens/you won.png";
        case PLAY_AGAIN_W: return "Assets/Images/Screens/play again - win.png";
        case PLAY_AGAIN_L: return "Assets/Images/Screens/play again - lose.png";
        case HIDE_DICKENS: return "Assets/Images/Screens/hide the dickens.png";
        case ABOUT: return "Assets/Images/Screens/about.png";
        case INSTRUCTIONS: return "Assets/Images/Screens/instructions.png";

        // Avatars
        case PLAYER_AVATAR: return "Assets/Images/tiny tim.png";
        case OPPONENT_AVATAR: return "Assets/Images/charles.png";

        // SOUNDS
        // Button sounds
        case BUTTON_ROLLOVER: return "Assets/Sounds/button-rollover.ogg";
        case WOODEN_CLICK: return "Assets/Sounds/wooden-click.wav";

        // Card sounds
        case PLAY_CARD: return "Assets/Sounds/play_card.flac";
        case TAKE_CARD: return "Assets/Sounds/take_card.wav";
        case CARD_SHUFFLE: return "Assets/Sounds/card shuffle 2.wav";
        case BLURB_POP: return "Assets/Sounds/blurb_pop.wav";
        case CARD_ROLLOVER: return "Assets/Sounds/card_rollover.wav";

        // Game sounds
        case INTRO_WHISTLE: return "Assets/Sounds/intro whistle.wav";
        case EXPLOSION: return "Assets/Sounds/explosion.wav";
        case CHIMES: return "Assets/Sounds/chimes.wav";
        case HIDING_DICKENS_CARD: return "Assets/Sounds/jazzy-chords.wav";

        // Charles' sounds
        case CHARLES_YOUR_TURN: return "Assets/Sounds/Charles/your turn.wav";
        case CHARLES_GOOD_LUCK: return "Assets/Sounds/Charles/good luck.wav";
        case CHARLES_GOOD_GAME: return "Assets/Sounds/Charles/good game.wav";
        case CHARLES_YOU_SHALL_NEVER: return "Assets/Sounds/Charles/you shall never defeat me.wav";
        case CHARLES_CRYING: return "Assets/Sounds/Charles/crying.wav";

        // Sounds upon playing certain cards
        // Exploding Dickens
        case RED_ALERT: return "Assets/Sounds/red-alert-nuclear-buzzer.wav";

        // Defuse 1
        case DICKENS_WHAT_GREATER_GIFT: return "Assets/Sounds/Dickens/what greater gift.wav";

        // Defuse 2
        case GRIP_IM_A_DEVIL: return "Assets/Sounds/Grip-I'm a devil.wav";
        case RAVEN: return "Assets/Sounds/raven.wav";

        // Defuse 3
        case DICKENS_SHINY: return "Assets/Sounds/Dickens/ooh shiny.wav";

        // See the future
        case SEE_THE_FUTURE_SOUND: return "Assets/Sounds/see the future.wav";

        // Steal a card
        case SWIPE: return "Assets/Sounds/swipe.wav";

        // Skip
        case PING: return "Assets/Sounds/ping.wav";

        // Draw from bottom
        case WOOSH: return "Assets/Sounds/woosh.wav";

        // Double slap
        case PUNCH: return "Assets/Sounds/punch.wav";


    }
}

template<class T>
void Assets<T>::loadAsset(AssetName asset) {
    assets[asset].loadFromFile(getAssetPath(asset));
}

template<class T>
std::map<AssetName, T> Assets<T>::assets {

};

#endif