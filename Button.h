//
// Created by vanes on 11/19/2021.
//

#ifndef MAIN_CPP_BUTTON_H
#define MAIN_CPP_BUTTON_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "States.h"
#include "Assets.h"
#include "Sounds.h"

class Button : public sf::Drawable, public States {
public:
    Button();

    Button(std::string text, unsigned int textSize, sf::Color textColor, sf::Vector2f textPos, sf::Vector2f bgSize, sf::Color bgColor, sf::Color colorRollover, sf::Vector2f bgPos);

    // Sets the button's states based on certain conditions
    void eventHandler(sf::RenderWindow& window, sf::Event event);

    // Updates the object based on the state it's in
    void update();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    friend class GameScreen;
    friend class ExplodingDickens;

private:
    sf::RectangleShape background;
    sf::Text text;
    sf::Color rolloverColor;

    unsigned int textSize;
    sf::Vector2f bgSize;
    sf::Color color;
    sf::Vector2f bgPos;
    sf::Vector2f textPos;

};

const unsigned int gameWindowWidth = 1440, gameWindowHeight = 810;

#endif //MAIN_CPP_BUTTON_H
