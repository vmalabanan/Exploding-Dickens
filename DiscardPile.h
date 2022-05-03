//
// Created by vanes on 11/25/2021.
//

#ifndef CARD_CPP_DISCARDPILE_H
#define CARD_CPP_DISCARDPILE_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Card.h"
#include "Button.h"

class DiscardPile : public sf::Drawable, public States {
public:

    // Do I need a constructor? -- if not, I'll need some way to initialize States

//    // Sets the discard pile's states based on certain conditions
//    void eventHandler(sf::RenderWindow& window, sf::Event event);
//
//    // Updates the discard pile based on the state it's in
//    void update();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    void push_back(Card card);

    void setPosition();

    int size();

    friend class ExplodingDickens;
private:
    // Actual discard pile
    std::vector<Card> discardPile;

//    // Graphical representation of discard pile
//    Card discardPileImage;
};


#endif //CARD_CPP_DISCARDPILE_H
