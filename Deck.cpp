//
// Created by vanes on 11/22/2021.
//

#include "Deck.h"

Deck::Deck() : States() {
    // Push cards to deck
    for (int i = 0; i < DECK_SIZE; ++i)
        deck.push(Card(static_cast<CardName>(i)));

    // Set deck image and position
    deckImage = Card(static_cast<CardName>(0));
    deckImage.cardBack.setPosition({gameWindowWidth * 0.25, static_cast<float>(gameWindowHeight / 2 - deckImage.cardBack.getGlobalBounds().height / 2)});

    // Set position of glowing deck (for rollover)
    deckImage.cardBackGlow.setPosition({gameWindowWidth * 0.158, gameWindowHeight * 0.1717259725});

    // Set card counter text
    text.setString("cards left");
    text.setFont(Assets<sf::Font>::getAsset(OSWALD));
    text.setCharacterSize(39);
    text.setFillColor(sf::Color(255, 255, 255));
    text.setPosition(gameWindowWidth * 0.135, gameWindowHeight * 0.467);

    cardCount.setString(std::to_string(deck.size()));
    cardCount.setFont(Assets<sf::Font>::getAsset(OSWALD));
    cardCount.setCharacterSize(39);
    cardCount.setFillColor(sf::Color(255, 255, 255));
    cardCount.setPosition(text.getGlobalBounds().left - 1.38 * cardCount.getGlobalBounds().width, gameWindowHeight * 0.467);
}

void Deck::push(const Card& card) {
    deck.push(card);
}

void Deck::shuffle() {
    int temp = deck.size();

    for (int i = 0; i < temp; ++i) {
        // Fill cardOrder array with cards from deck
        cardOrder[i] = deck.top();
        // delete from deck
        deck.pop();
    }

    // Shuffle cardOrder array
    int j;
    for (int i = 0; i < temp; ++i) {
        j = rand() % temp;
        swap(i, j);
    }

    // Delete deck
    deck.list.~DoublyLinkedList<Card>();

    // Push cards to deck according to cardOrder order
    for (int i = 0; i < temp; ++i) {
        deck.push(cardOrder[i]);
    }
}

void Deck::deal(CardHand& cardHand) {
    // first return back(), then pop()
    // push back to cardHand, then pop

    // I'm assuming this will be used only by the computer

}

// FOR TESTING ONLY -- remove
void Deck::deal() {
    // first return back(), then pop()
    // push back to cardHand, then pop

    // Remove card from deck
    deck.pop();

    // Update card counter
    cardCount.setString(std::to_string(deck.size()));

    if(deck.size() < 10 && deck.size() > 1)
        cardCount.setPosition(text.getGlobalBounds().left - 1.76 * cardCount.getGlobalBounds().width, gameWindowHeight * 0.467);

    else if(deck.size() == 1)
    {
        cardCount.setPosition(text.getGlobalBounds().left - 2.1 * cardCount.getGlobalBounds().width, gameWindowHeight * 0.467);
        text.setString("card left");
    }

    // I'm assuming this will be used only by the computer

}

void Deck::drawCard(CardHand& cardHand) {
    // first return back(), then pop()
    // push back to cardHand, then pop

    // I'm assuming this will be used only by the computer
}




void Deck::eventHandler(sf::RenderWindow& window, sf::Event event) {
    if(!isOn(HIDDEN) && isOn(PLAYER_TURN))
    {
        if(deck.size() > 0)
        {
            // Track mouse position relative to game window
            sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

            // If mouse position is within the bounds of deckImage > cardBack
            if(deckImage.cardBack.getGlobalBounds().contains(mousePos))
                stateOn(ROLLOVER);
            else
                stateOff(ROLLOVER);
        }
    }

}

void Deck::update() {
    if(!isOn(HIDDEN) && isOn(PLAYER_TURN))
    {
        if(isOn(ROLLOVER))
        {
            if(!isOn(ROLLEDOVER_ONCE))
            {
                // Play sound
                Sounds::sounds[CARD_ROLLOVER].play();

                // Turn on ROLLEDOVER_ONCE
                stateOn(ROLLEDOVER_ONCE);
            }
        }

        else
        {
            // Reset ROLLEDOVER_ONCE
            stateOff(ROLLEDOVER_ONCE);
        }
    }
}


int Deck::size() const {
    return deck.size();
}

sf::FloatRect Deck::getGlobalBounds() {
    return deckImage.cardBack.getGlobalBounds();
}

void Deck::pop() {
    return deck.pop();
}

Card& Deck::top() {
    return deck.top();
}

void Deck::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    if(!isOn(HIDDEN))
    {
        if(deck.size() > 0)
        {
            if(!isOn(ROLLOVER))
            {
                window.draw(deckImage.cardBack);
                window.draw(cardCount);
                window.draw(text);
            }
            else
            {
                window.draw(deckImage.cardBackGlow);
                window.draw(cardCount);
                window.draw(text);
            }

        }
    }
}

void Deck::swap(int position1, int position2) {
// Declare a temp Card and set = to deckForShuffling position1
    Card temp;
    temp = cardOrder[position1];

    // Swap position1 and position2
    cardOrder[position1] = cardOrder[position2];

    // Set position2 = temp
    cardOrder[position2] = temp;
}

void Deck::updateCount() {
    cardCount.setString(std::to_string(deck.size()));

    if(deck.size() < 10 && deck.size() > 1)
        cardCount.setPosition(text.getGlobalBounds().left - 1.76 * cardCount.getGlobalBounds().width, gameWindowHeight * 0.467);

    else if(deck.size() == 1)
    {
        cardCount.setPosition(text.getGlobalBounds().left - 2.1 * cardCount.getGlobalBounds().width, gameWindowHeight * 0.467);
        text.setString("card left");
    }
}



std::ostream& operator <<(std::ostream& outs, const Deck& deck) {
    outs << deck.deck.list;
}

