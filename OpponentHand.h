//
// Created by vanes on 11/25/2021.
//

#ifndef CARD_CPP_OPPONENTCARDHAND_H
#define CARD_CPP_OPPONENTCARDHAND_H
#include "Card.h"
#include "Button.h"

class OpponentHand : public sf::Drawable, public States {
public:
    void setImages();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    void push_back(const Card& card);

    int size();

    friend class ExplodingDickens;

private:
    // Actual opponent hand
    std::vector<Card> opponentHand;

    // Images for opponent hand
    // (Using these pre-made images instead of rotating a series of cards
    // because SFML's rotate feature distorts the images)
    sf::Sprite hand1;
    sf::Sprite hand2;
    sf::Sprite hand3;
    sf::Sprite hand4;
    sf::Sprite hand5;
    sf::Sprite hand5b;
    sf::Sprite hand5c;

};


#endif //CARD_CPP_OPPONENTCARDHAND_H
