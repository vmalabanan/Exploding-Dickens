//
// Created by vanes on 11/19/2021.
//

#include "Button.h"


//Button dummyButtonRollover;

Button::Button() {

}

// Call States() default constructor to add all states to map and set to false
Button::Button(std::string text, unsigned int textSize, sf::Color textColor, sf::Vector2f textPos, sf::Vector2f bgSize, sf::Color bgColor, sf::Color colorRollover, sf::Vector2f bgPos) : States() {
    // Button text
    this->text.setString(text);
    this->text.setFont(Assets<sf::Font>::getAsset(OSWALD));
    this->text.setCharacterSize(textSize);
    this->text.setFillColor(textColor);
    this->text.setPosition(textPos);

    // Button background
    background.setSize(bgSize);
    background.setFillColor(bgColor);
    background.setPosition(bgPos);

//    // Button sound
//    soundRollover.setBuffer(Assets<sf::SoundBuffer>::getAsset(BUTTON_ROLLOVER));
//    soundClick.setBuffer(Assets<sf::SoundBuffer>::getAsset(WOODEN_CLICK));

    // Save variables to use in eventHandler and to reset button to original specs after rollover
    this->textSize = textSize;
    this->bgSize = bgSize;
    color = bgColor;
    this->bgPos = bgPos;
    this->textPos = textPos;

    this->rolloverColor = colorRollover;
}

void Button::eventHandler(sf::RenderWindow& window, sf::Event event) {
    // Track mouse position relative to game window
    sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

    // Create dummy button
    Button dummyButton;
    dummyButton.background.setSize(bgSize);
    dummyButton.background.setPosition(bgPos);

    // If mouse position is within the bounds of dummy button background (aka background of button in original state, BEFORE rollover)
    if(dummyButton.background.getGlobalBounds().contains(mousePos))
        stateOn(ROLLOVER);

    else
        stateOff(ROLLOVER);
}


void Button::update() {
    // On button rollover, make changes to the button
    if(isOn(ROLLOVER))
    {
        if(!isOn(ROLLEDOVER_ONCE))
        {
            // Create dummy button
            Button dummyButton;
            dummyButton.text.setString(text.getString());
            dummyButton.text.setFont(Assets<sf::Font>::getAsset(OSWALD));
            dummyButton.text.setCharacterSize(textSize);
            dummyButton.text.setPosition(textPos);

            dummyButton.background.setSize(bgSize);
            dummyButton.background.setPosition(bgPos);

            // Change button font
            text.setCharacterSize(textSize * 0.85);

            if (dummyButton.text.getCharacterSize() < 40)
                text.setPosition(dummyButton.text.getGlobalBounds().left + (dummyButton.text.getGlobalBounds().width - text.getGlobalBounds().width) / 2, dummyButton.text.getGlobalBounds().top - (dummyButton.text.getGlobalBounds().height - text.getGlobalBounds().height) / 4);
            else
                text.setPosition(dummyButton.text.getGlobalBounds().left + (dummyButton.text.getGlobalBounds().width - text.getGlobalBounds().width) / 3, dummyButton.text.getGlobalBounds().top - (dummyButton.text.getGlobalBounds().height - text.getGlobalBounds().height) * 1.25);

            // Change button background
            background.setFillColor(rolloverColor);
            background.setSize(sf::Vector2f(background.getSize().x * 0.85, background.getSize().y * 0.85));
            background.setPosition(dummyButton.background.getGlobalBounds().left + (dummyButton.background.getGlobalBounds().width - background.getGlobalBounds().width) / 2, dummyButton.background.getGlobalBounds().top + (dummyButton.background.getGlobalBounds().height - background.getGlobalBounds().height) / 2);

            // Play sound
            Sounds::sounds[BUTTON_ROLLOVER].play();

            // Turn on ROLLEDOVER_ONCE
            stateOn(ROLLEDOVER_ONCE);
        }
     }

    else
    {
        // Revert button to original specs
        text.setCharacterSize(textSize);
        text.setPosition(textPos);
        background.setFillColor(color);
        background.setSize(bgSize);
        background.setPosition(bgPos);

        // Reset ROLLEDOVER_ONCE
        stateOff(ROLLEDOVER_ONCE);
    }
}


void Button::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    window.draw(background);
    window.draw(text);
}