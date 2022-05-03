//
// Created by vanes on 11/22/2021.
//

#ifndef MAIN_CPP_CARD_H
#define MAIN_CPP_CARD_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "States.h"
#include "Assets.h"
#include "CardName.h"

class Card : public sf::Drawable, public States {
public:
    Card();
//    Card(AssetName faceValue);
    Card(CardName faceValue);

    // Sets the card's states based on certain conditions
    void eventHandler(sf::RenderWindow& window, sf::Event event);

    // Updates the card based on the state it's in
    void update();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    friend std::ostream& operator <<(std::ostream& outs, const Card& card); // Outputs card's face value to console

    std::string toString() const;

    CardName getFaceValue();

    friend class GameScreen;
    friend class Deck;
    friend class DiscardPile;
    friend class CardHand;
    friend class OpponentHand;
    friend class ExplodingDickens;

private:
    CardName faceValue;
    sf::Sprite cardFront;
    sf::Sprite cardFrontPlayerHand;
    sf::Sprite cardBack; // would making this static make sense?
    sf::Sprite cardBackGlow;
    sf::Sprite cardInfo;
    sf::Vector2f cardPos;

    sf::Clock clock;

    // Make these static?

//    sf::Sound soundCardRollover;
//    sf::Sound soundPlayCard;
//    sf::Sound soundTakeCard;
//    sf::Sound soundBlurb;

};




#endif //MAIN_CPP_CARD_H
