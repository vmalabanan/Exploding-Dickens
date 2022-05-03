//
// Created by vanes on 11/22/2021.
//

#ifndef MAIN_CPP_CARDHAND_H
#define MAIN_CPP_CARDHAND_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Button.h"
#include "Card.h"
#include "DoublyLinkedList.h"
#include "Sounds.h"

class CardHand : public sf::Drawable, public States {
public:

    // Sets the player's card hand's states based on certain conditions
    void eventHandler(sf::RenderWindow& window, sf::Event event);

    // Updates the card hand based on the state it's in
    void update();

    int size();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    void push_back(const Card& card);

    // Position card depending on how many cards are in hand
    void setPosition();

    friend class ExplodingDickens;

private:
    // Actual player cardHand
    std::vector<Card> cardHand;

    // Clock used to track time spent in RIGHT_CLICK state
    sf::Clock clock;
};


#endif //MAIN_CPP_CARDHAND_H
