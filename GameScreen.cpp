//
// Created by vanes on 11/23/2021.
//

#include "GameScreen.h"

GameScreen::GameScreen() {

}

GameScreen::GameScreen(GameScreenName screenName) : States() {
    switch (screenName)
    {
        case SPLASH_SCREEN:
            screen = SPLASH_SCREEN;
            splashScreen();
            break;
        case GAME_SCREEN:
            screen = GAME_SCREEN;
            gameScreen();
            break;
        case ABOUT_SCREEN:
            screen = ABOUT_SCREEN;
            aboutScreen();
            break;
        case INSTRUCTIONS_SCREEN:
            screen = INSTRUCTIONS_SCREEN;
            instructionsScreen();
    }
}

void GameScreen::eventHandler(sf::RenderWindow& window, sf::Event event) {
    switch(screen)
    {
        case SPLASH_SCREEN:
            if(!isOn(HIDDEN))
            {
                button1.eventHandler(window, event);
                button2.eventHandler(window, event);
                button3.eventHandler(window, event);
            }
            break;
        case GAME_SCREEN:
            if(!isOn(HIDDEN))
                button1.eventHandler(window, event);
            break;
        case ABOUT_SCREEN:
            if(!isOn(HIDDEN))
                button1.eventHandler(window, event);
            break;
        case INSTRUCTIONS_SCREEN:
            if(!isOn(HIDDEN))
                button1.eventHandler(window, event);
    }
}


void GameScreen::update() {
    switch(screen)
    {
        case SPLASH_SCREEN:
            button1.update();
            button2.update();
            button3.update();
            break;
        case GAME_SCREEN:
            button1.update();
            break;
        case ABOUT_SCREEN:
            button1.update();
            break;
        case INSTRUCTIONS_SCREEN:
            button1.update();
            break;

    }

}

void GameScreen::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    switch(screen)
    {
        case SPLASH_SCREEN:
            window.draw(background1);
            window.draw(text1);
            window.draw(text2);
            window.draw(button1);
            window.draw(button2);
            window.draw(button3);
            break;
        case GAME_SCREEN:
            window.draw(background1);
            window.draw(image1);
            window.draw(image2);
            window.draw(text1);
            window.draw(text2);
            window.draw(button1);
            break;
        case ABOUT_SCREEN:
            window.draw(background1);
            window.draw(button1);
            break;
        case INSTRUCTIONS_SCREEN:
            window.draw(background1);
            window.draw(button1);
    }
}

void GameScreen::splashScreen() {
    // Background
    background1.setTexture(Assets<sf::Texture>::getAsset(SPLASH_BG));
    background1.setPosition((gameWindowWidth - background1.getGlobalBounds().width)/1.5, (gameWindowHeight - background1.getGlobalBounds().height)/1.5);

    // Title text
    text1.setString("Exploding");
    text1.setFont(Assets<sf::Font>::getAsset(PLAY_WITH_FIRE));
    text1.setCharacterSize(72);
    text1.setFillColor(sf::Color(255, 102, 0));
    text1.setPosition((gameWindowWidth - text1.getGlobalBounds().width)/2, (gameWindowHeight * 0.10));

    text2.setString("DICKENS");
    text2.setFont(Assets<sf::Font>::getAsset(BITTER_BOLD));
    text2.setCharacterSize(105);
    text2.setFillColor(sf::Color(0, 0, 0));
    text2.setPosition((gameWindowWidth - text2.getGlobalBounds().width)/2, (gameWindowHeight * 0.85 - text2.getGlobalBounds().height));

    // Buttons
    button1 = Button("start", 48, sf::Color(0, 0, 0), sf::Vector2f((gameWindowWidth - button1.text.getGlobalBounds().width)/2.1, (gameWindowHeight - button1.text.getGlobalBounds().height)/2.1), sf::Vector2f(175, 80), sf::Color(255, 102, 0), sf::Color(145, 111, 111), sf::Vector2f((gameWindowWidth - button1.text.getGlobalBounds().width)/2.25, (gameWindowHeight - button1.text.getGlobalBounds().height)/2.15));

    button2 = Button("about", 30, sf::Color(0, 0, 0), sf::Vector2f(gameWindowWidth * .07, gameWindowHeight * .75), sf::Vector2f(130, 60), sf::Color(255, 102, 0), sf::Color(145, 111, 111), sf::Vector2f(gameWindowWidth * .04575, gameWindowHeight * .7375));

    button3 = Button("instructions", 30, sf::Color(0, 0, 0), sf::Vector2f(button2.text.getGlobalBounds().left - 0.55 * button2.text.getGlobalBounds().width, button2.text.getGlobalBounds().top + 3 * button2.text.getGlobalBounds().height), sf::Vector2f(200, 60), sf::Color(255, 102, 0), sf::Color(145, 111, 111), sf::Vector2f(button2.text.getGlobalBounds().left - 1.125 * button2.text.getGlobalBounds().width, button2.text.getGlobalBounds().top + 2.6 * button2.text.getGlobalBounds().height));

}

void GameScreen::gameScreen() {
    //Background
    background1.setTexture(Assets<sf::Texture>::getAsset(WOOD_BG));
    background1.setPosition((gameWindowWidth - background1.getGlobalBounds().width)/2, (gameWindowHeight - background1.getGlobalBounds().height)/2);

    // Avatars
    image1.setTexture(Assets<sf::Texture>::getAsset(OPPONENT_AVATAR));
    image1.setPosition(gameWindowWidth * 0.42, gameWindowHeight * 0.02);

    image2.setTexture(Assets<sf::Texture>::getAsset(PLAYER_AVATAR));
    image2.setPosition(gameWindowWidth * 0.02, gameWindowHeight * 0.7);

    // Text
    text1.setString("Charles");
    text1.setFont(Assets<sf::Font>::getAsset(OSWALD));
    text1.setCharacterSize(39);
    text1.setFillColor(sf::Color(255, 255, 255));
    text1.setPosition(image1.getGlobalBounds().left + (image1.getGlobalBounds().width - text1.getGlobalBounds().width)/2.1, gameWindowHeight * 0.2225);

    text2.setString("Tiny Tim");
    text2.setFont(Assets<sf::Font>::getAsset(OSWALD));
    text2.setCharacterSize(39);
    text2.setFillColor(sf::Color(255, 255, 255));
    text2.setPosition(image2.getGlobalBounds().left + (image2.getGlobalBounds().width - text2.getGlobalBounds().width)/2.13, gameWindowHeight * 0.91);

    // Button
    button1 = Button("leave game", 37, sf::Color(159, 83, 29), sf::Vector2f(gameWindowWidth * 0.06, gameWindowHeight * 0.055), sf::Vector2f(240, 70), sf::Color(98, 39, 22), sf::Color(98, 39, 22), sf::Vector2f(gameWindowWidth * 0.03, gameWindowHeight * 0.0425));

}

void GameScreen::aboutScreen() {
    //Background
    background1.setTexture(Assets<sf::Texture>::getAsset(ABOUT));
    background1.setPosition((gameWindowWidth - background1.getGlobalBounds().width)/2, (gameWindowHeight - background1.getGlobalBounds().height)/2);

    // Button
    button1 = Button("go back", 30, sf::Color(255, 230, 213), sf::Vector2f((gameWindowWidth - button1.text.getGlobalBounds().width)/2.1, gameWindowHeight * 0.685), sf::Vector2f(175, 50), sf::Color(211, 95, 95), sf::Color(80, 22, 22), sf::Vector2f((gameWindowWidth - button1.text.getGlobalBounds().width)/2.25, gameWindowHeight * 0.68));


}

void GameScreen::instructionsScreen() {
    //Background
    background1.setTexture(Assets<sf::Texture>::getAsset(INSTRUCTIONS));
    background1.setPosition((gameWindowWidth - background1.getGlobalBounds().width)/2, (gameWindowHeight - background1.getGlobalBounds().height)/2);

    // Button
    button1 = Button("go back", 30, sf::Color(226, 219, 227), sf::Vector2f((gameWindowWidth - button1.text.getGlobalBounds().width)/2.1, gameWindowHeight * 0.785), sf::Vector2f(175, 50), sf::Color(69, 55, 72), sf::Color(31, 28, 36), sf::Vector2f((gameWindowWidth - button1.text.getGlobalBounds().width)/2.25, gameWindowHeight * 0.78));

}

