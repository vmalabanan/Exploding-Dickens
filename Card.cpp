//
// Created by vanes on 11/22/2021.
//

#include "Card.h"

Card::Card() {

}

Card::Card(CardName faceValue) : States() {
    // Card back, card glow
    cardBack.setTexture(Assets<sf::Texture>::getAsset(CARD_BACK));
    cardBackGlow.setTexture(Assets<sf::Texture>::getAsset(GLOWING_CARD_BACK));

    // Sounds
//    soundCardRollover.setBuffer(Assets<sf::SoundBuffer>::getAsset(CARD_ROLLOVER));
//    soundPlayCard.setBuffer(Assets<sf::SoundBuffer>::getAsset(PLAY_CARD));
//    soundTakeCard.setBuffer(Assets<sf::SoundBuffer>::getAsset(TAKE_CARD));
//    soundBlurb.setBuffer(Assets<sf::SoundBuffer>::getAsset(BLURB_POP));

    this->faceValue = faceValue;

    switch(faceValue) {
        case DICKENS:
            // Smooth texture
            Assets<sf::Texture>::assets[EXPLODING_DICKENS].setSmooth(true);
            cardFront.setTexture(Assets<sf::Texture>::getAsset(EXPLODING_DICKENS));
            break;
        case SHUFFLE_1:
        case SHUFFLE_2:
        case SHUFFLE_3:
            cardFront.setTexture(Assets<sf::Texture>::getAsset(SHUFFLE));
            cardFrontPlayerHand.setTexture(Assets<sf::Texture>::getAsset(SHUFFLE_PH));
            cardInfo.setTexture(Assets<sf::Texture>::getAsset(SHUFFLE_BLURB));
            break;
        case SEE_THE_FUTURE_1:
        case SEE_THE_FUTURE_2:
        case SEE_THE_FUTURE_3:
            cardFront.setTexture(Assets<sf::Texture>::getAsset(SEE_THE_FUTURE));
            cardFrontPlayerHand.setTexture(Assets<sf::Texture>::getAsset(SEE_THE_FUTURE_PH));
            cardInfo.setTexture(Assets<sf::Texture>::getAsset(SEE_THE_FUTURE_BLURB));
            break;
        case STEAL_A_CARD_1:
        case STEAL_A_CARD_2:
        case STEAL_A_CARD_3:
            cardFront.setTexture(Assets<sf::Texture>::getAsset(STEAL_A_CARD));
            cardFrontPlayerHand.setTexture(Assets<sf::Texture>::getAsset(STEAL_A_CARD_PH));
            cardInfo.setTexture(Assets<sf::Texture>::getAsset(STEAL_BLURB));
            break;
        case DRAW_FROM_BOTTOM_1:
        case DRAW_FROM_BOTTOM_2:
        case DRAW_FROM_BOTTOM_3:
            cardFront.setTexture(Assets<sf::Texture>::getAsset(DRAW_FROM_BOTTOM));
            cardFrontPlayerHand.setTexture(Assets<sf::Texture>::getAsset(DRAW_FROM_BOTTOM_PH));
            cardInfo.setTexture(Assets<sf::Texture>::getAsset(DRAW_FROM_BOTTOM_BLURB));
            break;
        case SKIP_1:
        case SKIP_2:
        case SKIP_3:
        case SKIP_4:
        case SKIP_5:
            cardFront.setTexture(Assets<sf::Texture>::getAsset(SKIP));
            cardFrontPlayerHand.setTexture(Assets<sf::Texture>::getAsset(SKIP_PH));
            cardInfo.setTexture(Assets<sf::Texture>::getAsset(SKIP_BLURB));
            break;
        case DOUBLE_SLAP_1:
        case DOUBLE_SLAP_2:
            cardFront.setTexture(Assets<sf::Texture>::getAsset(DOUBLE_SLAP));
            cardFrontPlayerHand.setTexture(Assets<sf::Texture>::getAsset(DOUBLE_SLAP_PH));
            cardInfo.setTexture(Assets<sf::Texture>::getAsset(DOUBLE_SLAP_BLURB));
            break;
        case DEFUSE_1:
            cardFront.setTexture(Assets<sf::Texture>::getAsset(DEFUSE1));
            cardFrontPlayerHand.setTexture(Assets<sf::Texture>::getAsset(DEFUSE1_PH));
            cardInfo.setTexture(Assets<sf::Texture>::getAsset(DEFUSE_BLURB));
            break;
        case DEFUSE_2:
            cardFront.setTexture(Assets<sf::Texture>::getAsset(DEFUSE2));
            cardFrontPlayerHand.setTexture(Assets<sf::Texture>::getAsset(DEFUSE2_PH));
            cardInfo.setTexture(Assets<sf::Texture>::getAsset(DEFUSE_BLURB));
            break;
        case DEFUSE_3:
            cardFront.setTexture(Assets<sf::Texture>::getAsset(DEFUSE3));
            cardFrontPlayerHand.setTexture(Assets<sf::Texture>::getAsset(DEFUSE3_PH));
            cardInfo.setTexture(Assets<sf::Texture>::getAsset(DEFUSE_BLURB));
    }
}


void Card::eventHandler(sf::RenderWindow& window, sf::Event event) {

}

void Card::update() {

}

void Card::draw(sf::RenderTarget& window, sf::RenderStates states) const { // REMOVE FUNCTION

}

std::ostream& operator <<(std::ostream& outs, const Card& card) {
    outs << card.toString() << std::endl;
    return outs;
}

std::string Card::toString() const {
    std::vector<std::string> cardList = {"SHUFFLE_1", "SHUFFLE_2", "SHUFFLE_3",
                                         "SEE_THE_FUTURE_1", "SEE_THE_FUTURE_2", "SEE_THE_FUTURE_3",
                                         "STEAL_A_CARD_1", "STEAL_A_CARD_2", "STEAL_A_CARD_3",
                                         "DRAW_FROM_BOTTOM_1", "DRAW_FROM_BOTTOM_2", "DRAW_FROM_BOTTOM_3",
                                         "SKIP_1", "SKIP_2", "SKIP_3", "SKIP_4", "SKIP_5",
                                         "DOUBLE_SLAP_1", "DOUBLE_SLAP_2",
                                         "DEFUSE_1", "DEFUSE_2", "DEFUSE_3",
                                         "DICKENS"};

    return cardList[faceValue];
}

CardName Card::getFaceValue() {
    return faceValue;
}