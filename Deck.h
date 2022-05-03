//
// Created by vanes on 11/22/2021.
//

#ifndef MAIN_CPP_DECK_H
#define MAIN_CPP_DECK_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Card.h"
#include "Stack.h"
#include "CardHand.h"
#include "CardName.h"
#include "Button.h"
#include "Sounds.h"

class Deck : public sf::Drawable, public States {
public:
    Deck(); // Builds standard game deck of 23 cards
    void push(const Card& card);
    void shuffle(); // Shuffles deck after deal
    void deal(CardHand& cardHand);

    void deal(); // FOR TESTING ONLY -- REMOVE

    void drawCard(CardHand& cardHand); // should this go here, or in CardHand?

    // Sets the deck's states based on certain conditions
    void eventHandler(sf::RenderWindow& window, sf::Event event);

    // Updates the object based on the state it's in
    void update();

    int size() const;

    sf::FloatRect getGlobalBounds();

    void pop();

    Card& top();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // Outputs deck to console
    friend std::ostream& operator <<(std::ostream& outs, const Deck& deck);

//private:
    // Swaps the position of two cards in the deck
    void swap(int position1, int position2);

    // Size of deck
    static const int DECK_SIZE = 23;

    // Actual deck
    Stack<Card> deck;

    // Array used to shuffle cards in the deck
    Card cardOrder[DECK_SIZE];

    // Count of cards left in deck, to be shown on the main game screen
    sf::Text cardCount;
    sf::Text text;

    // Update card count
    void updateCount();

    // Graphical representation of deck
    Card deckImage;

};




#endif //MAIN_CPP_DECK_H
