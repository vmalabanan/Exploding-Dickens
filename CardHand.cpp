//
// Created by vanes on 11/22/2021.
//

#include "CardHand.h"
void CardHand::eventHandler(sf::RenderWindow& window, sf::Event event) {
    if(!isOn(HIDDEN))
    {
        // Track mouse position relative to game window
        sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

        // Variable to store rollover area for each card
        sf::FloatRect rolloverArea;

        // For each card in cardHand
        for (int i = 0; i < cardHand.size(); ++i) {
            // Create dummy card
            Card dummyCard;
            dummyCard.cardFrontPlayerHand.setTexture(Assets<sf::Texture>::getAsset(SKIP_PH));
            dummyCard.cardFrontPlayerHand.setPosition(cardHand[i].cardPos);

            // Rollover based on position in cardHand
            if(i <= 4)
                rolloverArea = {dummyCard.cardFrontPlayerHand.getPosition().x, dummyCard.cardFrontPlayerHand.getPosition().y, static_cast<float>(dummyCard.cardFrontPlayerHand.getGlobalBounds().width * 0.7), dummyCard.cardFrontPlayerHand.getGlobalBounds().height};

            else if(i == 5)
                rolloverArea = dummyCard.cardFrontPlayerHand.getGlobalBounds();

            else if(i == 6) // need to add side
            {
                rolloverArea = {dummyCard.cardFrontPlayerHand.getPosition().x, dummyCard.cardFrontPlayerHand.getPosition().y, static_cast<float>(dummyCard.cardFrontPlayerHand.getGlobalBounds().width * 0.7), static_cast<float>(dummyCard.cardFrontPlayerHand.getGlobalBounds().height * 0.15)};
            }

            else if(i <= 10 || i == 12 || i == 13)
                rolloverArea = {dummyCard.cardFrontPlayerHand.getPosition().x, dummyCard.cardFrontPlayerHand.getPosition().y, static_cast<float>(dummyCard.cardFrontPlayerHand.getGlobalBounds().width * 0.7), static_cast<float>(dummyCard.cardFrontPlayerHand.getGlobalBounds().height * 0.15)};

            else if(i == 11 || i >= 14)
                rolloverArea = {dummyCard.cardFrontPlayerHand.getPosition().x, dummyCard.cardFrontPlayerHand.getPosition().y, dummyCard.cardFrontPlayerHand.getGlobalBounds().width, static_cast<float>(dummyCard.cardFrontPlayerHand.getGlobalBounds().height * 0.15)};


            // If mouse position is within the bounds of rollover area
            if(rolloverArea.contains(mousePos))
            {
                cardHand[i].stateOn(ROLLOVER);

             // If RIGHT mouse button is pressed
                if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
                {
                    cardHand[i].stateOn(RIGHT_CLICK);

                    // Reset clock
                    clock.restart();
                }
            }

            else
            {
                cardHand[i].stateOff(ROLLOVER);
                cardHand[i].stateOff(RIGHT_CLICK);
            }

        }
    }
}

void CardHand::update() {
    // If cardHand is not hidden
    if(!isOn(HIDDEN))
    {
        // For all cards in cardHand
        for (int i = 0; i < cardHand.size(); ++i) {
                // On card rollover, move the card and play a sound
                if(cardHand[i].isOn(ROLLOVER))
                {
                    if(!cardHand[i].isOn(ROLLEDOVER_ONCE))
                    {
                        // Move card -- DO I WANT THE CARD TO ACTUALLY MOVE, or just appear in the new position?
                        cardHand[i].cardFrontPlayerHand.setPosition({cardHand[i].cardPos.x, cardHand[i].cardPos.y - 50});

                        // Play sound
//                        cardHand[i].soundCardRollover.play();
                        Sounds::sounds[CARD_ROLLOVER].play();

                        // Turn on ROLLEDOVER_ONCE
                        cardHand[i].stateOn(ROLLEDOVER_ONCE);
                    }
                }

                else
                {
                    // Revert card to original position
                    cardHand[i].cardFrontPlayerHand.setPosition(cardHand[i].cardPos);

                    // Reset ROLLEDOVER_ONCE
                    cardHand[i].stateOff(ROLLEDOVER_ONCE);
                }

                if(cardHand[i].isOn(RIGHT_CLICK))
                {
                    if(!cardHand[i].isOn(R_CLICKED_ONCE))
                    {
                        cardHand[i].cardFrontPlayerHand.setPosition({cardHand[i].cardPos.x, gameWindowHeight * 0.36});

                        // Position blurb
                        cardHand[i].cardInfo.setPosition({cardHand[i].cardPos.x - 90, gameWindowHeight * 0.36 - 200});

                        // Play sound
                        Sounds::sounds[BLURB_POP].play();

                        // Turn on R_CLICKED_ONCE
                        cardHand[i].stateOn(R_CLICKED_ONCE);
                    }

                    if(clock.getElapsedTime().asSeconds() > 2 && clock.getElapsedTime().asSeconds() < 3)
                    {
                        cardHand[i].stateOff(RIGHT_CLICK);

                        // Revert card to original position
                        cardHand[i].cardFrontPlayerHand.setPosition(cardHand[i].cardPos);
                    }
                }

                else
                {
                    // Reset R_CLICKED_ONCE
                    cardHand[i].stateOff(R_CLICKED_ONCE);
                }
        }
    }

}

int CardHand::size() {
    return cardHand.size();
}

void CardHand::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    if(!isOn(HIDDEN))
    {
        if(cardHand.size() > 0)
        {
            // for card hand with 1-6 cards
            if(cardHand.size() <= 6)
            {
                for (int i = 0; i < cardHand.size(); ++i) {
                    window.draw(cardHand[i].cardFrontPlayerHand);
                }
            }

            // for card hand with 7-12 cards
            else if(cardHand.size() <= 12)
            {
                // second row
                for (int i = 6; i < cardHand.size(); ++i) {
                    window.draw(cardHand[i].cardFrontPlayerHand);
                }

                // front row
                for (int i = 0; i < 6; ++i) {
                    window.draw(cardHand[i].cardFrontPlayerHand);
                }
            }

            // for card hand with 13+ cards
            else
            {
                // third row
                for (int i = 12; i < cardHand.size(); ++i) {
                    window.draw(cardHand[i].cardFrontPlayerHand);
                }

                // second row
                for (int i = 6; i < 12; ++i) {
                    window.draw(cardHand[i].cardFrontPlayerHand);
                }

                // front row
                for (int i = 0; i < 6; ++i) {
                    window.draw(cardHand[i].cardFrontPlayerHand);
                }
            }

            // When a card is right clicked, draw card info blurb
            for (int i = 0; i < cardHand.size(); ++i) {
                if(cardHand[i].isOn(RIGHT_CLICK))
                    window.draw(cardHand[i].cardInfo);
            }
        }
    }
}

void CardHand::push_back(const Card& card) {
    cardHand.push_back(card);
}

void CardHand::setPosition() {
    int xOffset = 0;
    int yOffset = 0;

    if(cardHand.size() > 0) // DO I NEED THIS?
    {
        if(cardHand.size() <= 6)
        {
            for (int i = 0; i < cardHand.size(); ++i) {
                cardHand[i].cardFrontPlayerHand.setPosition({static_cast<float>(gameWindowWidth * 0.227 + xOffset), static_cast<float>(gameWindowHeight * 0.78 + yOffset)});
                xOffset += cardHand[i].cardFrontPlayerHand.getGlobalBounds().width * 0.75;
                if (i % 2 == 0)
                    yOffset += 15;
                else
                    yOffset *= 0;
            }
        }

        else if(cardHand.size() <= 12)
        {
            for (int i = 0; i < 6; ++i) {
                cardHand[i].cardFrontPlayerHand.setPosition({static_cast<float>(gameWindowWidth * 0.227 + xOffset), static_cast<float>(gameWindowHeight * 0.78 + yOffset)});
                xOffset += cardHand[i].cardFrontPlayerHand.getGlobalBounds().width * 0.75;
                if (i % 2 == 0)
                    yOffset += 15;
                else
                    yOffset *= 0;
            }

            // reset x offset
            xOffset = 0;

            for (int i = 6; i < cardHand.size(); ++i) {
                cardHand[i].cardFrontPlayerHand.setPosition({static_cast<float>(gameWindowWidth * 0.205 + xOffset), static_cast<float>(gameWindowHeight * 0.74)});
                xOffset += cardHand[i].cardFrontPlayerHand.getGlobalBounds().width * 0.75;

            }
        }

        else
        {
            for (int i = 0; i < 6; ++i) {
                cardHand[i].cardFrontPlayerHand.setPosition({static_cast<float>(gameWindowWidth * 0.227 + xOffset), static_cast<float>(gameWindowHeight * 0.78 + yOffset)});
                xOffset += cardHand[i].cardFrontPlayerHand.getGlobalBounds().width * 0.75;
                if (i % 2 == 0)
                    yOffset += 15;
                else
                    yOffset *= 0;
            }

            // reset x offset
            xOffset = 0;

            for (int i = 6; i < 12; ++i) {
                cardHand[i].cardFrontPlayerHand.setPosition({static_cast<float>(gameWindowWidth * 0.205 + xOffset), static_cast<float>(gameWindowHeight * 0.74)});
                xOffset += cardHand[i].cardFrontPlayerHand.getGlobalBounds().width * 0.75;
            }

            // reset x offset
            xOffset = 0;

            for (int i = 12; i < cardHand.size(); ++i) {
                cardHand[i].cardFrontPlayerHand.setPosition({static_cast<float>(gameWindowWidth * 0.24 + xOffset), static_cast<float>(gameWindowHeight * 0.7)});
                xOffset += cardHand[i].cardFrontPlayerHand.getGlobalBounds().width * 0.75;
            }
        }

        // Save position to cardPos (will be used in eventHandler function)
        for (int i = 0; i < cardHand.size(); ++i)
            cardHand[i].cardPos = cardHand[i].cardFrontPlayerHand.getPosition();
    }
}

//void CardHand::deleteCard(const Card& faceValue) {
//
//}