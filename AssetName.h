//
// Created by vanes on 11/18/2021.
//

#ifndef MAIN_CPP_ASSETNAME_H
#define MAIN_CPP_ASSETNAME_H

enum AssetName {
    // For classes that are loaded to RAM (e.g., sf::Texture, sf::SoundBuffer, sf::Font, etc.)
    // FONTS
    BITTER_BOLD, OSWALD, PLAY_WITH_FIRE,

    // IMAGES
    // Cards
    CARD_BACK, GLOWING_CARD_BACK, EXPLODING_DICKENS,
    SHUFFLE, SEE_THE_FUTURE, STEAL_A_CARD, DRAW_FROM_BOTTOM, SKIP, DOUBLE_SLAP, DEFUSE1, DEFUSE2, DEFUSE3,

    // Smaller versions of card front for player hand
    SHUFFLE_PH, SEE_THE_FUTURE_PH, STEAL_A_CARD_PH, DRAW_FROM_BOTTOM_PH, SKIP_PH, DOUBLE_SLAP_PH, DEFUSE1_PH, DEFUSE2_PH, DEFUSE3_PH,

    // Image of thumbnail card back for opponent's hand
    OPPONENT_HAND_1, OPPONENT_HAND_2, OPPONENT_HAND_3, OPPONENT_HAND_4, OPPONENT_HAND_5,

    // Card info blurbs
    DEFUSE_BLURB, DOUBLE_SLAP_BLURB, DRAW_FROM_BOTTOM_BLURB, SEE_THE_FUTURE_BLURB,
    SHUFFLE_BLURB, SKIP_BLURB, STEAL_BLURB,

    // Charles' chat bubbles
    GOOD_LUCK, YOU_SHALL_NEVER, CRYING,

    // Status blurbs
    STATUS_SHUFFLING, STATUS_HIDING, STATUS_CHARLES_IS_STEALING, STATUS_CHARLES_DREW_EXPL_DICKENS, STATUS_CHARLES_IS_HIDING,

    // Backgrounds
    SPLASH_BG, WOOD_BG,

    // Screens
    YOUR_TURN, SEE_FUTURE, DEFUSE_DICKENS, YOU_EXPLODED, YOU_WON, PLAY_AGAIN_W, PLAY_AGAIN_L, HIDE_DICKENS,
    ABOUT, INSTRUCTIONS,

    // Avatars
    PLAYER_AVATAR, OPPONENT_AVATAR,

    // SOUNDS
    // Button sounds
    BUTTON_ROLLOVER, WOODEN_CLICK,

    // General card sounds
    PLAY_CARD, TAKE_CARD, CARD_SHUFFLE, BLURB_POP, CARD_ROLLOVER,

    // General game sounds
    INTRO_WHISTLE, EXPLOSION, CHIMES, HIDING_DICKENS_CARD,

    // Charles' sounds
    CHARLES_YOUR_TURN, CHARLES_GOOD_LUCK, CHARLES_GOOD_GAME, CHARLES_YOU_SHALL_NEVER, CHARLES_CRYING,

    // Sounds upon playing certain cards
    // Exploding Dickens
    RED_ALERT,

    // Defuse 1
    DICKENS_WHAT_GREATER_GIFT,

    // Defuse 2
    GRIP_IM_A_DEVIL, RAVEN,

    // Defuse 3
    DICKENS_SHINY,

    // See the future
    SEE_THE_FUTURE_SOUND,

    // Steal
    SWIPE,

    // Skip
    PING,

    // Draw from bottom
    WOOSH,

    // Double slap
    PUNCH,



    LAST_ASSET
};
#endif //MAIN_CPP_ASSETNAME_H
