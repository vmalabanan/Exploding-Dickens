//
// Created by vanes on 11/25/2021.
//

#include "OpponentHand.h"

void OpponentHand::setImages() {
    // Set textures
    hand1.setTexture(Assets<sf::Texture>::getAsset(OPPONENT_HAND_1));
    hand2.setTexture(Assets<sf::Texture>::getAsset(OPPONENT_HAND_2));
    hand3.setTexture(Assets<sf::Texture>::getAsset(OPPONENT_HAND_3));
    hand4.setTexture(Assets<sf::Texture>::getAsset(OPPONENT_HAND_4));
    hand5.setTexture(Assets<sf::Texture>::getAsset(OPPONENT_HAND_5));
    hand5b.setTexture(Assets<sf::Texture>::getAsset(OPPONENT_HAND_5));
    hand5c.setTexture(Assets<sf::Texture>::getAsset(OPPONENT_HAND_5));

    // Smooth textures
    Assets<sf::Texture>::assets[OPPONENT_HAND_1].setSmooth(true);
    Assets<sf::Texture>::assets[OPPONENT_HAND_2].setSmooth(true);
    Assets<sf::Texture>::assets[OPPONENT_HAND_3].setSmooth(true);
    Assets<sf::Texture>::assets[OPPONENT_HAND_4].setSmooth(true);
    Assets<sf::Texture>::assets[OPPONENT_HAND_5].setSmooth(true);

    // Set positions
    sf::Vector2f topLeft = {gameWindowWidth * 0.6, gameWindowHeight * 0.04};
    sf::Vector2f bottomLeft = {gameWindowWidth * 0.6, gameWindowHeight * 0.16};
    sf::Vector2f right = {gameWindowWidth * 0.79, gameWindowHeight * 0.12};

    hand5.setPosition(bottomLeft);
    hand5b.setPosition(topLeft);
    hand5c.setPosition(right);

    if (opponentHand.size() <= 4)
    {
        hand1.setPosition(bottomLeft);
        hand2.setPosition(bottomLeft);
        hand3.setPosition(bottomLeft);
        hand4.setPosition(bottomLeft);
    }

    else if (opponentHand.size() <= 9)
    {
        hand1.setPosition(topLeft);
        hand2.setPosition(topLeft);
        hand3.setPosition(topLeft);
        hand4.setPosition(topLeft);
    }

    else
    {
        hand1.setPosition(right);
        hand2.setPosition(right);
        hand3.setPosition(right);
        hand4.setPosition(right);
    }

}

void OpponentHand::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    if(!isOn(HIDDEN))
    {
        switch(opponentHand.size())
        {
            case 1: window.draw(hand1); break;
            case 2: window.draw(hand2); break;
            case 3: window.draw(hand3); break;
            case 4: window.draw(hand4); break;
            case 5: window.draw(hand5); break;

            case 6:
                window.draw(hand5);
                window.draw(hand1);
                break;
            case 7:
                window.draw(hand5);
                window.draw(hand2);
                break;
            case 8:
                window.draw(hand5);
                window.draw(hand3);
                break;
            case 9:
                window.draw(hand5);
                window.draw(hand4);
                break;
            case 10:
                window.draw(hand5);
                window.draw(hand5b);
                break;
            case 11:
                window.draw(hand5);
                window.draw(hand5b);
                window.draw(hand1);
                break;
            case 12:
                window.draw(hand5);
                window.draw(hand5b);
                window.draw(hand2);
                break;
            case 13:
                window.draw(hand5);
                window.draw(hand5b);
                window.draw(hand3);
                break;
            case 14:
                window.draw(hand5);
                window.draw(hand5b);
                window.draw(hand4);
                break;
            case 15:
                window.draw(hand5);
                window.draw(hand5b);
                window.draw(hand5c);
                break;
    }
    }

}

void OpponentHand::push_back(const Card& card) {
    opponentHand.push_back(card);
}

int OpponentHand::size() {
    return opponentHand.size();
}

