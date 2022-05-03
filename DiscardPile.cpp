//
// Created by vanes on 11/25/2021.
//

#include "DiscardPile.h"
//void DiscardPile::eventHandler(sf::RenderWindow& window, sf::Event event) {
//    if(!isOn(HIDDEN))
//    {
//
//    }
//}
//
//void DiscardPile::update() {
//    if(!isOn(HIDDEN))
//    {
//
//    }
//}

void DiscardPile::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    if(!isOn(HIDDEN))
    {
        if(discardPile.size() > 0)
            window.draw(discardPile[discardPile.size() - 1].cardFront);
    }
}

void DiscardPile::push_back(Card card) {
    discardPile.push_back(card);
}

void DiscardPile::setPosition() {
    for (int i = 0; i < discardPile.size(); ++i) {
        discardPile[i].cardFront.setPosition({gameWindowWidth * 0.565, static_cast<float>(gameWindowHeight / 2 - discardPile[i].cardFront.getGlobalBounds().height / 2)});
    }
}

int DiscardPile::size() {
    return discardPile.size();
}

