//
// Created by vanes on 11/23/2021.
//

#ifndef DECK_CPP_GAMESCREEN_H
#define DECK_CPP_GAMESCREEN_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Button.h"
#include "States.h"
#include "GameScreenName.h"
#include "Deck.h"

class GameScreen : public sf::Drawable, public States {
public:
    GameScreen();
    GameScreen(GameScreenName screenName);

    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    Button button1;
    Button button2;
    Button button3;

    friend class ExplodingDickens;

private:
    sf::Sprite background1;
    sf::Sprite image1;
    sf::Sprite image2;
    sf::Text text1;
    sf::Text text2;


    GameScreenName screen;
    void splashScreen();
    void gameScreen();
    void aboutScreen();
    void instructionsScreen();

};


#endif //DECK_CPP_GAMESCREEN_H
