//
// Created by vanes on 11/25/2021.
//

#include "ExplodingDickens.h"


ExplodingDickens::ExplodingDickens() : States(), turnCounterOpponent(0), turnCounterPlayer(0) {
    // Seed random()
    srand(time(nullptr));

    // Create window
    unsigned int gameWindowWidth = 1440, gameWindowHeight = 810;
    sf::RenderWindow window(sf::VideoMode(gameWindowWidth, gameWindowHeight, 32), "Exploding Dickens!", sf::Style::Close);

    // Limit framerate to 60 fps
    window.setFramerateLimit(60);

    // Initialize class variables
    initializeVariables();

    // Bind sounds
    Sounds::bindSounds();

    // Declare game screen objects
    GameScreen splashScreen(SPLASH_SCREEN);
    GameScreen gameScreen(GAME_SCREEN);
    GameScreen aboutScreen(ABOUT_SCREEN);
    GameScreen instructionsScreen(INSTRUCTIONS_SCREEN);

     // Set gameState = first screen
    gameStateBG = SPLASH_SCREEN;


    // Set objects to hidden
    deck.stateOn(HIDDEN);
    discardPile.stateOn(HIDDEN);
    playerHand.stateOn(HIDDEN);
    opponentHand.stateOn(HIDDEN);
    this->stateOn(HIDDEN);

    // Put screens into map
    std::map<GameScreenName, GameScreen> background;

    background[SPLASH_SCREEN] = splashScreen;
    background[GAME_SCREEN] = gameScreen;
    background[ABOUT_SCREEN] = aboutScreen;
    background[INSTRUCTIONS_SCREEN] = instructionsScreen;


    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            // if user clicks the window's X button, the window closes
            if(event.type == sf::Event::Closed)
                window.close();

            // Track mouse position relative to game window
            sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

            // For SPLASH SCREEN:
            if(!splashScreen.isOn(HIDDEN))
            {
                // If mouse position is within the bounds of button1 background ("Start")
                if(splashScreen.button1.background.getGlobalBounds().contains(mousePos))
                {
                    // If mouse button is pressed
                    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                    {
                        // Play sound
                        Sounds::sounds[WOODEN_CLICK].play();

                        // Change gameState to GAME_SCREEN
                        gameStateBG = GAME_SCREEN;

                        // Set splash screen to hidden
                        splashScreen.stateOn(HIDDEN);

                        // Set game objects to visible
                        deck.stateOff(HIDDEN);
                        discardPile.stateOff(HIDDEN);
                        playerHand.stateOff(HIDDEN);
                        opponentHand.stateOff(HIDDEN);
                        this->stateOff(HIDDEN);

                        // Set game screen to visible
                        gameScreen.stateOff(HIDDEN);

                        // Run actual game
                        game();

                    }
                }

                // If mouse position is within the bounds of button2 background ("About")
                if(splashScreen.button2.background.getGlobalBounds().contains(mousePos))
                {
                    // If mouse button is pressed
                    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                    {
                        // Play sound
                        Sounds::sounds[WOODEN_CLICK].play();

                        // Change gameState to ABOUT_SCREEN
                        gameStateBG = ABOUT_SCREEN;

                        // Set splash screen to hidden
                        splashScreen.stateOn(HIDDEN);

                        // Set about to visible
                        aboutScreen.stateOff(HIDDEN);

                    }
                }

                // If mouse position is within the bounds of button3 background ("Instructions")
                if(splashScreen.button3.background.getGlobalBounds().contains(mousePos))
                {
                    // If mouse button is pressed
                    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                    {
                        // Play sound
                        Sounds::sounds[WOODEN_CLICK].play();

                        // Change gameState to INSTRUCTIONS_SCREEN
                        gameStateBG = INSTRUCTIONS_SCREEN;

                        // Set splash screen to hidden
                        splashScreen.stateOn(HIDDEN);

                        // Set Instructions to visible
                        instructionsScreen.stateOff(HIDDEN);
                    }
                }
            }

            // For ABOUT SCREEN:
            // If mouse position is within the bounds of button1 background ("go back")
            if(!aboutScreen.isOn(HIDDEN))
            {
                if(aboutScreen.button1.background.getGlobalBounds().contains(mousePos))
                {
                    // If mouse button is pressed
                    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                    {
                        // Play sound
                        Sounds::sounds[WOODEN_CLICK].play();

                        // Change gameState to SPLASH_SCREEN
                        gameStateBG = SPLASH_SCREEN;

                        // Set about screen to hidden
                        aboutScreen.stateOn(HIDDEN);

                        // Set splash screen to not hidden
                        splashScreen.stateOff(HIDDEN);
                    }
                }
            }

            // For INSTRUCTIONS SCREEN:
            // If mouse position is within the bounds of button1 background ("go back")
            if(!instructionsScreen.isOn(HIDDEN))
            {
                if(instructionsScreen.button1.background.getGlobalBounds().contains(mousePos))
                {
                    // If mouse button is pressed
                    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                    {
                        // Play sound
                        Sounds::sounds[WOODEN_CLICK].play();

                        // Change gameState to SPLASH_SCREEN
                        gameStateBG = SPLASH_SCREEN;

                        // Set about screen to hidden
                        instructionsScreen.stateOn(HIDDEN);

                        // Set splash screen to not hidden
                        splashScreen.stateOff(HIDDEN);
                    }
                }
            }



            // For GAME SCREEN:
            // If mouse position is within the bounds of button1 background ("Leave Game")
            if(!gameScreen.isOn(HIDDEN))
            {
                if(gameScreen.button1.background.getGlobalBounds().contains(mousePos))
                {
                    // If mouse button is pressed
                    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                    {
                        // Play sound
                        Sounds::sounds[WOODEN_CLICK].play();

                        // Change gameState to SPLASH_SCREEN
                        gameStateBG = SPLASH_SCREEN;

                        // Set game screen to hidden
                        gameScreen.stateOn(HIDDEN);

                        // Set objects to hidden
                        deck.stateOn(HIDDEN);
                        discardPile.stateOn(HIDDEN);
                        playerHand.stateOn(HIDDEN);
                        opponentHand.stateOn(HIDDEN);
                        this->stateOn(HIDDEN);

                        // Set splash screen to not hidden
                        splashScreen.stateOff(HIDDEN);

                    }
                }
            }


            // For SEE THE FUTURE screen:
            if(isOn(SEE_THE_FUTURE_OVERLAY))
            {
                // If mouse position is within the bounds of button background (
                if(button.background.getGlobalBounds().contains(mousePos))
                {
                    // If mouse button is pressed
                    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                    {
                        // Play sound
                        Sounds::sounds[WOODEN_CLICK].play();

                        // Change SEE_THE_FUTURE_OVERLAY to off
                        stateOff(SEE_THE_FUTURE_OVERLAY);
                    }
                }
            }

            // For DEFUSE_DICKENS_OVERLAY screen:
            if(isOn(DEFUSE_DICKENS_OVERLAY))
            {
                int count = 0;

                // Count number of Defuse cards in player's hand
                for (int i = 0; i < playerHand.size(); ++i) {
                    if(playerHand.cardHand[i].faceValue == DEFUSE_1 || playerHand.cardHand[i].faceValue == DEFUSE_2 || playerHand.cardHand[i].faceValue == DEFUSE_3)
                        count++;
                }

                // If player has no defuse cards
                if(count == 0)
                {
                    // If mouse button is pressed, call youExploded function
                    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                        youExploded();
                }
            }

            // For HIDE_DICKENS_OVERLAY screen:
            if(isOn(HIDE_DICKENS_OVERLAY))
            {
                if(deck.size() >= 5)
                {
                    // If mouse position is within the bounds of button1 background ("on the top")
                    if(hideDickens1.background.getGlobalBounds().contains(mousePos))
                        hideDickensMouseEvent(event, deck.size());

                    // If mouse position is within the bounds of button2 background ("second")
                    if(hideDickens2.background.getGlobalBounds().contains(mousePos))
                        hideDickensMouseEvent(event, deck.size() - 1);

                    // If mouse position is within the bounds of button3 background ("third")
                    if(hideDickens3.background.getGlobalBounds().contains(mousePos))
                        hideDickensMouseEvent(event, deck.size() - 2);

                    // If mouse position is within the bounds of button4 background ("fourth")
                    if(hideDickens4.background.getGlobalBounds().contains(mousePos))
                        hideDickensMouseEvent(event, deck.size() - 3);

                    // If mouse position is within the bounds of button5 background ("fifth")
                    if(hideDickens5.background.getGlobalBounds().contains(mousePos))
                        hideDickensMouseEvent(event, deck.size() - 4);

                    // If mouse position is within the bounds of button6 background ("on the bottom")
                    if(hideDickens6.background.getGlobalBounds().contains(mousePos))
                        hideDickensMouseEvent(event, 0);

                    // If mouse position is within the bounds of button7 background ("random")
                    if(hideDickens7.background.getGlobalBounds().contains(mousePos))
                        hideDickensMouseEvent(event, rand() % (deck.size() + 1));
                }

                if(deck.size() >= 4)
                {
                    // If mouse position is within the bounds of button1 background ("on the top")
                    if(hideDickens1.background.getGlobalBounds().contains(mousePos))
                        hideDickensMouseEvent(event, deck.size());

                    // If mouse position is within the bounds of button2 background ("second")
                    if(hideDickens2.background.getGlobalBounds().contains(mousePos))
                        hideDickensMouseEvent(event, deck.size() - 1);

                    // If mouse position is within the bounds of button3 background ("third")
                    if(hideDickens3.background.getGlobalBounds().contains(mousePos))
                        hideDickensMouseEvent(event, deck.size() - 2);

                    // If mouse position is within the bounds of button4 background ("fourth")
                    if(hideDickens4.background.getGlobalBounds().contains(mousePos))
                        hideDickensMouseEvent(event, deck.size() - 3);

                    // If mouse position is within the bounds of button6 background ("on the bottom")
                    if(hideDickens6.background.getGlobalBounds().contains(mousePos))
                        hideDickensMouseEvent(event, 0);

                    // If mouse position is within the bounds of button7 background ("random")
                    if(hideDickens7.background.getGlobalBounds().contains(mousePos))
                        hideDickensMouseEvent(event, rand() % (deck.size() + 1));
                }

                if(deck.size() >= 3)
                {
                    // If mouse position is within the bounds of button1 background ("on the top")
                    if(hideDickens1.background.getGlobalBounds().contains(mousePos))
                        hideDickensMouseEvent(event, deck.size());

                    // If mouse position is within the bounds of button2 background ("second")
                    if(hideDickens2.background.getGlobalBounds().contains(mousePos))
                        hideDickensMouseEvent(event, deck.size() - 1);

                    // If mouse position is within the bounds of button3 background ("third")
                    if(hideDickens3.background.getGlobalBounds().contains(mousePos))
                        hideDickensMouseEvent(event, deck.size() - 2);

                    // If mouse position is within the bounds of button6 background ("on the bottom")
                    if(hideDickens6.background.getGlobalBounds().contains(mousePos))
                        hideDickensMouseEvent(event, 0);

                    // If mouse position is within the bounds of button7 background ("random")
                    if(hideDickens7.background.getGlobalBounds().contains(mousePos))
                        hideDickensMouseEvent(event, rand() % (deck.size() + 1));
                }

                if(deck.size() >= 2)
                {
                    // If mouse position is within the bounds of button1 background ("on the top")
                    if(hideDickens1.background.getGlobalBounds().contains(mousePos))
                        hideDickensMouseEvent(event, deck.size());

                    // If mouse position is within the bounds of button2 background ("second")
                    if(hideDickens2.background.getGlobalBounds().contains(mousePos))
                        hideDickensMouseEvent(event, deck.size() - 1);

                    // If mouse position is within the bounds of button6 background ("on the bottom")
                    if(hideDickens6.background.getGlobalBounds().contains(mousePos))
                        hideDickensMouseEvent(event, 0);

                    // If mouse position is within the bounds of button7 background ("random")
                    if(hideDickens7.background.getGlobalBounds().contains(mousePos))
                        hideDickensMouseEvent(event, rand() % (deck.size() + 1));
                }

                else
                {
                    // If mouse position is within the bounds of button1 background ("on the top")
                    if(hideDickens1.background.getGlobalBounds().contains(mousePos))
                        hideDickensMouseEvent(event, deck.size());

                    // If mouse position is within the bounds of button6 background ("on the bottom")
                    if(hideDickens6.background.getGlobalBounds().contains(mousePos))
                        hideDickensMouseEvent(event, 0);

                    // If mouse position is within the bounds of button7 background ("random")
                    if(hideDickens7.background.getGlobalBounds().contains(mousePos))
                        hideDickensMouseEvent(event, rand() % (deck.size() + 1));
                }
            }


            // For PLAY AGAIN screen (both WIN and LOSE):
            // If mouse position is within the bounds of button background ("play again")
            if(isOn(PLAY_AGAIN_WIN) || isOn(PLAY_AGAIN_LOSE))
            {
                // Set game screen to hidden
                gameScreen.stateOn(HIDDEN);

                if(buttonPlayAgain.background.getGlobalBounds().contains(mousePos))
                {
                    // If mouse button is pressed
                    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                    {
                        // Play sound
                        Sounds::sounds[WOODEN_CLICK].play();

                        // Change the following states to off
                        stateOff(PLAYER_WINS);
                        stateOff(PLAYER_LOSES);
                        stateOff(PLAY_AGAIN_WIN);
                        stateOff(PLAY_AGAIN_LOSE);

                        // Set game screen to visible
                        gameScreen.stateOff(HIDDEN);

                        // Set game objects to visible
                        deck.stateOff(HIDDEN);
                        discardPile.stateOff(HIDDEN);
                        playerHand.stateOff(HIDDEN);
                        opponentHand.stateOff(HIDDEN);
                        this->stateOff(HIDDEN);

                        // Run actual game
                        game();
                    }
                }

                // If mouse position is within the bounds of button background ("leave game")
                if(buttonLeaveGame.background.getGlobalBounds().contains(mousePos))
                {
                    // If mouse button is pressed
                    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                    {
                        // Play sound
                        Sounds::sounds[WOODEN_CLICK].play();

                        // Change the following states to off
                        stateOff(PLAYER_WINS);
                        stateOff(PLAYER_LOSES);
                        stateOff(PLAY_AGAIN_WIN);
                        stateOff(PLAY_AGAIN_LOSE);

                        // Play sound
                        Sounds::sounds[WOODEN_CLICK].play();

                        // Set splash screen to visible
                        splashScreen.stateOff(HIDDEN);

                        // Change gameState to SPLASH_SCREEN
                        gameStateBG = SPLASH_SCREEN;

                        // Set objects to hidden
                        deck.stateOn(HIDDEN);
                        discardPile.stateOn(HIDDEN);
                        playerHand.stateOn(HIDDEN);
                        opponentHand.stateOn(HIDDEN);
                        this->stateOn(HIDDEN);
                    }
                }
            }

            // For DECK (game screen):
                if(deck.size() > 0)
                {
                    // If mouse position is within the bounds of deck AND it is the player's turn
                    if(deck.getGlobalBounds().contains(mousePos) && deck.isOn(PLAYER_TURN) && !isOn(SEE_THE_FUTURE_OVERLAY) && !isOn(HIDE_DICKENS_OVERLAY))
                    {
                        // If LEFT mouse button is pressed
                        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                        {
                            // Play sound
                            Sounds::sounds[TAKE_CARD].play();

                            if(deck.top().faceValue == DICKENS)
                            {
                                // Delete from deck
                                deck.pop();

                                // Update deck card counter
                                deck.updateCount();

                                drawExplodingDickens();

                                // Turn off ROLLOVER and ROLLEDOVER_ONCE
                                deck.stateOff(ROLLOVER);
                                deck.stateOff(ROLLEDOVER_ONCE);

                            }

                            else
                            {
                                // Push the card into player's hand
                                playerHand.push_back(deck.top());

                                // Set the card's position
                                playerHand.setPosition();

                                // Delete from deck
                                deck.pop();

                                // Update deck card counter
                                deck.updateCount();

                                // Turn off ROLLOVER and ROLLEDOVER_ONCE
                                deck.stateOff(ROLLOVER);
                                deck.stateOff(ROLLEDOVER_ONCE);

                                 // End player turn
                                 opponentTurn();
                            }

                        }
                    }
                }


            // For PLAYER HAND (game screen):
            // Variable to store clickable area for each card
                sf::FloatRect clickArea;

                // For each card in player hand
                for (int i = 0; i < playerHand.size(); ++i) {
                    // Create dummy card
                    Card dummyCard;
                    dummyCard.cardFrontPlayerHand.setTexture(Assets<sf::Texture>::getAsset(SKIP_PH));
                    dummyCard.cardFrontPlayerHand.setPosition(playerHand.cardHand[i].cardPos);

                    // clickable area based on card position
                    if(i <= 4)
                        clickArea = {dummyCard.cardFrontPlayerHand.getPosition().x, dummyCard.cardFrontPlayerHand.getPosition().y, static_cast<float>(dummyCard.cardFrontPlayerHand.getGlobalBounds().width * 0.75), dummyCard.cardFrontPlayerHand.getGlobalBounds().height};

                    else if(i == 5)
                        clickArea = dummyCard.cardFrontPlayerHand.getGlobalBounds();

                    else if(i == 6)
                        clickArea = {dummyCard.cardFrontPlayerHand.getPosition().x, dummyCard.cardFrontPlayerHand.getPosition().y, static_cast<float>(dummyCard.cardFrontPlayerHand.getGlobalBounds().width * 0.75), static_cast<float>(dummyCard.cardFrontPlayerHand.getGlobalBounds().height * 0.13)};

                    else if(i <= 10 || i == 12 || i == 13)
                        clickArea = {dummyCard.cardFrontPlayerHand.getPosition().x, dummyCard.cardFrontPlayerHand.getPosition().y, static_cast<float>(dummyCard.cardFrontPlayerHand.getGlobalBounds().width * 0.75), static_cast<float>(dummyCard.cardFrontPlayerHand.getGlobalBounds().height * 0.13)};

                    else if(i == 11 || i >= 14)
                        clickArea = {dummyCard.cardFrontPlayerHand.getPosition().x, dummyCard.cardFrontPlayerHand.getPosition().y, dummyCard.cardFrontPlayerHand.getGlobalBounds().width, static_cast<float>(dummyCard.cardFrontPlayerHand.getGlobalBounds().height * 0.13)};

                    // If mouse position is within the bounds of rollover area AND it is the player's turn
                    if(clickArea.contains(mousePos) && playerHand.isOn(PLAYER_TURN) && !isOn(SEE_THE_FUTURE_OVERLAY) && !isOn(HIDE_DICKENS_OVERLAY))
                    {
                        // If LEFT mouse button is pressed
                        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                        {
                            if(isOn(DEFUSE_DICKENS_OVERLAY))
                            {
                                if(playerHand.cardHand[i].faceValue == DEFUSE_1 || playerHand.cardHand[i].faceValue == DEFUSE_2 || playerHand.cardHand[i].faceValue == DEFUSE_3)
                                {
                                    // Play sound
                                    Sounds::sounds[PLAY_CARD].play();

                                    // Push the card into the discard pile
                                    discardPile.push_back(playerHand.cardHand[i]);

                                    // Set the card's position in the discard pile
                                    discardPile.setPosition();

                                    // Temporarily store card
                                    Card tempCard = playerHand.cardHand[i];

                                    // Delete from player card hand
                                    playerHand.cardHand.erase(playerHand.cardHand.begin() + i);

                                    // Rearrange player card hand
                                    playerHand.setPosition();

                                    // Perform different actions depending on which card was played
                                    cardEvent(tempCard);
                                }
                            }

                            else {
                                if(playerHand.cardHand[i].faceValue != DEFUSE_1 && playerHand.cardHand[i].faceValue != DEFUSE_2 && playerHand.cardHand[i].faceValue != DEFUSE_3)
                                {
                                    // Play sound
                                    Sounds::sounds[PLAY_CARD].play();

                                    // Push the card into the discard pile
                                    discardPile.push_back(playerHand.cardHand[i]);

                                    // Set the card's position in the discard pile
                                    discardPile.setPosition();

                                    // Temporarily store card
                                    Card tempCard = playerHand.cardHand[i];

                                    // Delete from player card hand
                                    playerHand.cardHand.erase(playerHand.cardHand.begin() + i);

                                    // Rearrange player card hand
                                    playerHand.setPosition();

                                    // Perform different actions depending on which card was played
                                    cardEvent(tempCard);
                                }
                            }
                        }
                }
            }

            // Look at events only for the current game screen
            background[gameStateBG].eventHandler(window, event);
            deck.eventHandler(window, event);
            playerHand.eventHandler(window, event);
//            overlay[gameStateOverlay].eventHandler(window, event);
        }

        // Update states for the current game state
        background[gameStateBG].update();
        deck.update();
        playerHand.update();
        eventHandler(window, event);
        update();

        window.clear(sf::Color::White);
        window.draw(background[gameStateBG]);
        window.draw(opponentHand);
        window.draw(deck);
        window.draw(discardPile);

        if(isOn(DEFUSE_DICKENS_OVERLAY))
        {
            window.draw(*this);
            window.draw(playerHand);
        }

        else
        {
            window.draw(playerHand);
            window.draw(*this);
        }


        window.display();
    }
}

void ExplodingDickens::eventHandler(sf::RenderWindow& window, sf::Event event) {
    if(!isOn(HIDDEN))
    {
        // If it's the player's turn
        if(isOn(PLAYER_TURN))
        {
            // Only if the intro has not been shown yet
            if(!isOn(SHOWED_INTRO_ONCE))
            {
                if(clock.getElapsedTime().asSeconds() > 1)
                {
                    // Turn on PLAYER_TURN_INTRO state
                    stateOn(PLAYER_TURN_INTRO);

                    // restart the clock
                    clock.restart();
                }
            }
        }

        // Otherwise, turn off PLAYER_TURN_INTRO and SHOWED_INTRO_ONCE
        else
        {
            stateOff(PLAYER_TURN_INTRO);
            stateOff(SHOWED_INTRO_ONCE);
        }

        // If it's the first turn of the game
        if(isOn(FIRST_TURN))
        {
            // Only if the intro has not been shown yet
            if(!isOn(SHOWED_FIRST_TURN_ONCE))
            {
                // If it's not the player's turn
                if(!isOn(PLAYER_TURN))
                {
                    if(clock2.getElapsedTime().asSeconds() > 1)
                    {
                        // Turn on FIRST_TURN_INTRO state
                        stateOn(FIRST_TURN_INTRO);

                        // restart the clock
                        clock2.restart();
                    }
                }
                // If it is the player's turn
                else
                    if(clock2.getElapsedTime().asSeconds() > 3)
                    {
                        // Turn on FIRST_TURN_INTRO state
                        stateOn(FIRST_TURN_INTRO);

                        // restart the clock
                        clock2.restart();
                    }

            }
        }

        // Otherwise, turn off FIRST_TURN_INTRO and SHOWED_FIRST_TURN_ONCE
        else
        {
            stateOff(FIRST_TURN_INTRO);
            stateOff(SHOWED_FIRST_TURN_ONCE);
        }

        // If SEE_THE_FUTURE_OVERLAY is on
        if(isOn(SEE_THE_FUTURE_OVERLAY))
            button.eventHandler(window, event);

        // If HIDE_DICKENS_OVERLAY is on
        if(isOn(HIDE_DICKENS_OVERLAY))
        {
            if (deck.size() >= 5)
            {
                hideDickens1.eventHandler(window, event);
                hideDickens2.eventHandler(window, event);
                hideDickens3.eventHandler(window, event);
                hideDickens4.eventHandler(window, event);
                hideDickens5.eventHandler(window, event);
                hideDickens6.eventHandler(window, event);
                hideDickens7.eventHandler(window, event);
            }

            else if (deck.size() >= 4)
            {
                hideDickens1.eventHandler(window, event);
                hideDickens2.eventHandler(window, event);
                hideDickens3.eventHandler(window, event);
                hideDickens4.eventHandler(window, event);
                hideDickens6.eventHandler(window, event);
                hideDickens7.eventHandler(window, event);
            }

            else if (deck.size() >= 3)
            {
                hideDickens1.eventHandler(window, event);
                hideDickens2.eventHandler(window, event);
                hideDickens3.eventHandler(window, event);
                hideDickens6.eventHandler(window, event);
                hideDickens7.eventHandler(window, event);
            }

            else if (deck.size() >= 2)
            {
                hideDickens1.eventHandler(window, event);
                hideDickens2.eventHandler(window, event);
                hideDickens6.eventHandler(window, event);
                hideDickens7.eventHandler(window, event);
            }

            else
            {
                hideDickens1.eventHandler(window, event);
                hideDickens6.eventHandler(window, event);
                hideDickens7.eventHandler(window, event);
            }
        }



        // If TAUNTS is on
        if(isOn(TAUNTS))
        {
            // Only if the intro has not been shown yet
            if(!isOn(SHOWED_TAUNTS_INTRO_ONCE))
            {
                if(clock3.getElapsedTime().asSeconds() > 1)
                {
                    // Turn on TAUNTS_INTRO state
                    stateOn(TAUNTS_INTRO);

                    // restart the clock
                    clock3.restart();
                }
            }
        }

        // Otherwise, turn off TAUNTS_INTRO and SHOWED_TAUNTS_INTRO_ONCE
        else
        {
            stateOff(TAUNTS_INTRO);
            stateOff(SHOWED_TAUNTS_INTRO_ONCE);
        }

        // If SHUFFLE is on
        if(isOn(SHUFFLE_CARDS))
        {
            if(!isOn(SHUFFLED_ONCE))
            {
                // Turn on SHUFFLE_EVENT state
                stateOn(SHUFFLE_EVENT);

                // restart the clock
                clock4.restart();
            }
        }


        // Otherwise, turn off SHUFFLE_EVENT and SHUFFLED_ONCE
        else
        {
            stateOff(SHUFFLE_EVENT);
            stateOff(SHUFFLED_ONCE);
        }

        // If HIDE_DICKENS_CARD is on
        if(isOn(HIDE_DICKENS_CARD))
        {
            if(!isOn(HID_DICKENS_ONCE))
            {
                // Turn on SHUFFLE_EVENT state
                stateOn(HIDE_DICKENS_EVENT);

                // restart the clock
                clock6.restart();
            }
        }

        // Otherwise, turn off HIDE_DICKENS_EVENT and HID_DICKENS_ONCE
        else
        {
            stateOff(HIDE_DICKENS_EVENT);
            stateOff(HID_DICKENS_ONCE);
        }


        // If CHARLES_STEALS is on
        if(isOn(CHARLES_STEALS))
        {
            if(!isOn(CHARLES_STOLE_ONCE))
            {
                // Turn on state
                stateOn(CHARLES_STEALS_EVENT);

                // restart the clock
                clock8.restart();
            }
        }

        // Otherwise, turn off events
        else
        {
            stateOff(CHARLES_STEALS_EVENT);
            stateOff(CHARLES_STOLE_ONCE);
        }

        // If CHARLES_DREW_EXP_DICKENS is on
        if(isOn(CHARLES_DREW_EXP_DICKENS))
        {
            if(!isOn(SHOWED_CHARLES_DICKENS_EXP_EVENT_ONCE))
            {
                // Turn on SHUFFLE_EVENT state
                stateOn(CHARLES_DICKENS_EXP_EVENT);

                // restart the clock
                clock9.restart();
            }
        }


        // Otherwise, turn off states
        else
        {
            stateOff(CHARLES_DICKENS_EXP_EVENT);
            stateOff(SHOWED_CHARLES_DICKENS_EXP_EVENT_ONCE);
        }

        // If CHARLES_HIDES_DICKENS_CARD is on
        if(isOn(CHARLES_HIDES_DICKENS_CARD))
        {
            if(!isOn(CHARLES_HID_DICKENS_ONCE))
            {
                // Turn on state
                stateOn(CHARLES_HIDES_DICKENS_EVENT);

                // restart the clock
                clock10.restart();
            }
        }


        // Otherwise, turn off states
        else
        {
            stateOff(CHARLES_HIDES_DICKENS_EVENT);
            stateOff(CHARLES_HID_DICKENS_ONCE);
        }

        // If PLAY AGAIN WIN or PLAY AGAIN LOSE is on
        if(isOn(PLAY_AGAIN_WIN) || isOn(PLAY_AGAIN_LOSE))
        {
            buttonPlayAgain.eventHandler(window, event);
            buttonLeaveGame.eventHandler(window, event);
        }

        // For YOU EXPLODED screen:
        if(isOn(PLAYER_LOSES))
        {
            // If some time has passed
            if(clock7.getElapsedTime().asSeconds() > 2)
            {
                // Turn on PLAY AGAIN (LOSE) SCREEN
                stateOn(PLAY_AGAIN_LOSE);
            }
        }

        // For YOU WON screen:
        if(isOn(PLAYER_WINS))
        {
            // If some time has passed
            if(clock7.getElapsedTime().asSeconds() > 2)
            {
                // Turn on PLAY AGAIN SCREEN
                stateOn(PLAY_AGAIN_WIN);
            }
        }
    }
}

void ExplodingDickens::update() {
    if(!isOn(HIDDEN))
    {
        // When PLAYER_TURN_INTRO is on
        if(isOn(PLAYER_TURN_INTRO))
        {
            if(!isOn(SHOWED_INTRO_ONCE))
            {
                // Play sound
                Sounds::sounds[CHARLES_YOUR_TURN].play();

                // Turn on SHOWED_INTRO_ONCE
                stateOn(SHOWED_INTRO_ONCE);
            }

            // Turn off PLAYER_TURN_INTRO after some time has elapsed
            if(clock.getElapsedTime().asSeconds() > 2 && clock.getElapsedTime().asSeconds() < 3)
                this->stateOff(PLAYER_TURN_INTRO);
        }

        // When FIRST_TURN_INTRO is on
        if(isOn(FIRST_TURN_INTRO))
        {
            if(!isOn(SHOWED_FIRST_TURN_ONCE))
            {
                // Play sound
                Sounds::sounds[CHARLES_GOOD_LUCK].play();

                // Turn on SHOWED_INTRO_ONCE
                stateOn(SHOWED_FIRST_TURN_ONCE);
            }

            // Turn off FIRST_TURN_INTRO after some time has elapsed
            if(clock2.getElapsedTime().asSeconds() > 2 && clock2.getElapsedTime().asSeconds() < 3)
                this->stateOff(FIRST_TURN_INTRO);
        }

        // If SEE_THE_FUTURE_OVERLAY is on
        if(isOn(SEE_THE_FUTURE_OVERLAY))
            button.update();

        // When TAUNTS is on
        if(isOn(TAUNTS_INTRO))
        {
            if(!isOn(SHOWED_TAUNTS_INTRO_ONCE))
            {
                // Play sound
                Sounds::sounds[CHARLES_YOU_SHALL_NEVER].play();

                // Turn on SHOWED_TAUNTS_INTRO_ONCE
                stateOn(SHOWED_TAUNTS_INTRO_ONCE);
            }

            // Turn off TAUNTS_INTRO after some time has elapsed
//            if(clock3.getElapsedTime().asSeconds() > 2 && clock3.getElapsedTime().asSeconds() < 3)
            if(clock3.getElapsedTime().asSeconds() > 2)
            {
                this->stateOff(TAUNTS_INTRO);
                this->stateOff(SHOWED_TAUNTS_INTRO_ONCE);
                this->stateOff(TAUNTS);
            }
        }

        // When SHUFFLE_EVENT is on
        if(isOn(SHUFFLE_EVENT))
        {
            if(!isOn(SHUFFLED_ONCE))
            {
                // Play sound
                Sounds::sounds[CARD_SHUFFLE].play();

                // Turn on SHUFFLED_ONCE
                stateOn(SHUFFLED_ONCE);
            }

            // Turn off states after some time has elapsed
            if(clock4.getElapsedTime().asSeconds() > 2)
            {
                this->stateOff(SHUFFLE_EVENT);
                this->stateOff(SHUFFLED_ONCE);
                this->stateOff(SHUFFLE_CARDS);
            }
        }

        // When CHARLES_STEALS_EVENT is on
        if(isOn(CHARLES_STEALS_EVENT))
        {
            if(!isOn(CHARLES_STOLE_ONCE))
            {
                // Turn on state
                stateOn(CHARLES_STOLE_ONCE);
            }

            // Turn off states after some time has elapsed
            if(clock8.getElapsedTime().asSeconds() > 2)
            {
                this->stateOff(CHARLES_STEALS_EVENT);
                this->stateOff(CHARLES_STOLE_ONCE);
                this->stateOff(CHARLES_STEALS);
            }
        }

        // When CHARLES_DICKENS_EXP_EVENT is on
        if(isOn(CHARLES_DICKENS_EXP_EVENT))
        {
            if(!isOn(SHOWED_CHARLES_DICKENS_EXP_EVENT_ONCE))
            {
                // Turn on SHUFFLED_ONCE
                stateOn(SHOWED_CHARLES_DICKENS_EXP_EVENT_ONCE);
            }

            // Turn off states after some time has elapsed
            if(clock9.getElapsedTime().asSeconds() > 2)
            {
                this->stateOff(CHARLES_DICKENS_EXP_EVENT);
                this->stateOff(SHOWED_CHARLES_DICKENS_EXP_EVENT_ONCE);
                this->stateOff(CHARLES_DREW_EXP_DICKENS);
            }
        }

        // When CHARLES_HIDES_DICKENS_EVENT is on
        if(isOn(CHARLES_HIDES_DICKENS_EVENT))
        {
            if(!isOn(CHARLES_HID_DICKENS_ONCE))
            {
                // Turn on SHUFFLED_ONCE
                stateOn(CHARLES_HID_DICKENS_ONCE);
            }

            // Turn off states after some time has elapsed
            if(clock10.getElapsedTime().asSeconds() > 2)
            {
                this->stateOff(CHARLES_HIDES_DICKENS_EVENT);
                this->stateOff(CHARLES_HID_DICKENS_ONCE);
                this->stateOff(CHARLES_HIDES_DICKENS_CARD);
            }
        }

        // When HIDE_DICKENS_EVENT is on
        if(isOn(HIDE_DICKENS_EVENT))
        {
            if(!isOn(HID_DICKENS_ONCE))
            {
                // Play sound
                Sounds::sounds[HIDING_DICKENS_CARD].play();

                // Turn on HID_DICKENS_ONCE
                stateOn(HID_DICKENS_ONCE);
            }

            // Turn off states after some time has elapsed
            if(clock6.getElapsedTime().asSeconds() > 2)
            {
                this->stateOff(HIDE_DICKENS_EVENT);
                this->stateOff(HID_DICKENS_ONCE);
                this->stateOff(HIDE_DICKENS_CARD);
            }
        }

        // If PLAY AGAIN WIN or PLAY AGAIN LOSE is on
        if(isOn(PLAY_AGAIN_WIN) || isOn(PLAY_AGAIN_LOSE))
        {
            buttonPlayAgain.update();
            buttonLeaveGame.update();
        }

        // If player's turn is off
//        if(!isOn(PLAYER_TURN) && turnCounterOpponent == 0)
//        if(!isOn(PLAYER_TURN))
//        {
//            // Turn on player's turn after a few seconds
//            if(clock5.getElapsedTime().asSeconds() > 2.5)
//                playerTurn();
//        }


        // If HIDE_DICKENS_OVERLAY is on
        if(isOn(HIDE_DICKENS_OVERLAY))
        {
            if (deck.size() >= 5)
            {
                hideDickens1.update();
                hideDickens2.update();
                hideDickens3.update();
                hideDickens4.update();
                hideDickens5.update();
                hideDickens6.update();
                hideDickens7.update();
            }

            else if (deck.size() >= 4)
            {
                hideDickens1.update();
                hideDickens2.update();
                hideDickens3.update();
                hideDickens4.update();
                hideDickens6.update();
                hideDickens7.update();
            }

            else if (deck.size() >= 3)
            {
                hideDickens1.update();
                hideDickens2.update();
                hideDickens3.update();
                hideDickens6.update();
                hideDickens7.update();
            }

            else if (deck.size() >= 2)
            {
                hideDickens1.update();
                hideDickens2.update();
                hideDickens6.update();
                hideDickens7.update();
            }

            else
            {
                hideDickens1.update();
                hideDickens6.update();
                hideDickens7.update();
            }
        }
    }
}

void ExplodingDickens::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    if(!isOn(HIDDEN))
    {
        if(isOn(FIRST_TURN_INTRO))
            window.draw(goodLuckBubble);
        if(isOn(PLAYER_TURN_INTRO))
            window.draw(yourTurnScreen);
        if(isOn(TAUNTS_INTRO))
            window.draw(neverDefeatMeBubble);
        if(isOn(SHUFFLE_EVENT))
            window.draw(statusShuffling);
        if(isOn(CHARLES_DICKENS_EXP_EVENT))
            window.draw(statusCharlesDrewExplDickens);
        if(isOn(CHARLES_HIDES_DICKENS_EVENT))
            window.draw(statusCharlesIsHiding);
        if(isOn(CHARLES_STEALS_EVENT))
            window.draw(statusCharlesIsStealing);
        if(isOn(HIDE_DICKENS_EVENT))
            window.draw(statusHidingDickens);
        if(isOn(DEFUSE_DICKENS_OVERLAY))
        {
            window.draw(defuseExplodingDickensScreen);
            window.draw(explodingDickensCard.cardFront);
        }
        if(isOn(SEE_THE_FUTURE_OVERLAY))
        {
            window.draw(seeTheFutureScreen);
            window.draw(button);
            if (deck.size() >= 3)
            {
                window.draw(card3.cardFront);
                window.draw(card2.cardFront);
                window.draw(card1.cardFront);
            }

            if (deck.size() >= 2)
            {
                window.draw(card2.cardFront);
                window.draw(card1.cardFront);
            }

            if (deck.size() >= 1)
                window.draw(card1.cardFront);
        }

        if(isOn(HIDE_DICKENS_OVERLAY))
        {
            window.draw(hideDickensScreen);
            if (deck.size() >= 5)
            {
                window.draw(hideDickens1);
                window.draw(hideDickens2);
                window.draw(hideDickens3);
                window.draw(hideDickens4);
                window.draw(hideDickens5);
                window.draw(hideDickens6);
                window.draw(hideDickens7);
            }

            else if (deck.size() >= 4)
            {
                window.draw(hideDickens1);
                window.draw(hideDickens2);
                window.draw(hideDickens3);
                window.draw(hideDickens4);
                window.draw(hideDickens6);
                window.draw(hideDickens7);
            }

            else if (deck.size() >= 3)
            {
                window.draw(hideDickens1);
                window.draw(hideDickens2);
                window.draw(hideDickens3);
                window.draw(hideDickens6);
                window.draw(hideDickens7);
            }

            else if (deck.size() >= 2)
            {
                window.draw(hideDickens1);
                window.draw(hideDickens2);
                window.draw(hideDickens6);
                window.draw(hideDickens7);
            }

            else
            {
                window.draw(hideDickens1);
                window.draw(hideDickens6);
                window.draw(hideDickens7);
            }
        }

        if(isOn(PLAYER_WINS))
            window.draw(youWonScreen);
        if(isOn(PLAY_AGAIN_WIN))
        {
            window.draw(playAgainWinScreen);
            window.draw(buttonLeaveGame);
            window.draw(buttonPlayAgain);
        }
        if(isOn(PLAYER_LOSES))
            window.draw(youExplodedScreen);
        if(isOn(PLAY_AGAIN_LOSE))
        {
            window.draw(playAgainLoseScreen);
            window.draw(buttonLeaveGame);
            window.draw(buttonPlayAgain);
        }
    }

}

void ExplodingDickens::game() {
    // Reset states
    resetStates();

    // Reset cards
    resetCards();

    // Create deck
    deck = Deck();

    // Deal cards
    dealCards();

    // Shuffle deck
    deck.shuffle();

    // Set the cards' positions in player hand
    playerHand.setPosition();

    // Initialize the images for opponent's hand
    opponentHand.setImages();

    // Turn on first turn
    firstTurn();

    // Randomly choose who goes first
    int i = rand() % 2;

    if (i == 0)
        playerTurn();
    else
        opponentTurn();

}

void ExplodingDickens::firstTurn() {
    // Turn on FIRST_TURN for ExplodingDickens object
    stateOn(FIRST_TURN);

    // Play sound
    Sounds::sounds[INTRO_WHISTLE].play();

    // restart the clock
    clock2.restart();
}


void ExplodingDickens::playerTurn() {
    // Turn on PLAYER_TURN for deck, player hand, ExplodingDickens object
    stateOn(PLAYER_TURN);
    deck.stateOn(PLAYER_TURN);
    playerHand.stateOn(PLAYER_TURN);

    // restart the clock
    clock.restart();

}

void ExplodingDickens::opponentTurn() {
    // Restart clock
    clock5.restart();

    // Turn off PLAYER_TURN for deck, player hand, ExplodingDickens object
    stateOff(PLAYER_TURN);
    deck.stateOff(PLAYER_TURN);
    playerHand.stateOff(PLAYER_TURN);

    // Algorithm for opponent to choose best move
    chooseBestMove();

}

void ExplodingDickens::playSeeTheFutureCard() {
    // Turn on SEE_THE_FUTURE_OVERLAY for ExplodingDickens object
    stateOn(SEE_THE_FUTURE_OVERLAY);

    // Play sound
    Sounds::sounds[SEE_THE_FUTURE_SOUND].play();

    if (deck.size() >= 3)
    {
        // Set card values
        card1 = deck.deck.peek(deck.size() - 1);
        card2 = deck.deck.peek(deck.size() - 2);
        card3 = deck.deck.peek(deck.size() - 3);

        // Set card positions
        if(card1.faceValue == DICKENS)
        {
            card1.cardFront.setPosition(gameWindowWidth * 0.22, gameWindowHeight * 0.34); // adjusted positioning
            card2.cardFront.setPosition(card1.cardFront.getPosition().x + 300, card1.cardFront.getPosition().y + 5); // adjusted positioning
            card3.cardFront.setPosition(card2.cardFront.getPosition().x + 243, card2.cardFront.getPosition().y - 50); // regular positioning
        }

        else if(card2.faceValue == DICKENS)
        {
            card1.cardFront.setPosition(gameWindowWidth * 0.25, gameWindowHeight * 0.47); // regular positioning
            card2.cardFront.setPosition(card1.cardFront.getPosition().x + 185, card1.cardFront.getPosition().y - 100); // adjusted positioning
            card3.cardFront.setPosition(card2.cardFront.getPosition().x + 300, card2.cardFront.getPosition().y + 5); // adjusted positioning
        }

        else if(card3.faceValue == DICKENS)
        {
            card1.cardFront.setPosition(gameWindowWidth * 0.25, gameWindowHeight * 0.47); // regular positioning
            card2.cardFront.setPosition(card1.cardFront.getPosition().x + 243, card1.cardFront.getPosition().y - 50); // regular positioning
            card3.cardFront.setPosition(card2.cardFront.getPosition().x + 185, card2.cardFront.getPosition().y - 100); // adjusted positioning
        }

        else
        {
            card1.cardFront.setPosition(gameWindowWidth * 0.25, gameWindowHeight * 0.47); // regular positioning
            card2.cardFront.setPosition(card1.cardFront.getPosition().x + 243, card1.cardFront.getPosition().y - 50); // regular positioning
            card3.cardFront.setPosition(card2.cardFront.getPosition().x + 243, card2.cardFront.getPosition().y - 50); // regular positioning
        }

    }

    if (deck.size() >= 2)
    {
        // Set card values
        card1 = deck.deck.peek(deck.size() - 1);
        card2 = deck.deck.peek(deck.size() - 2);

        // Set card positions
        if(card1.faceValue == DICKENS)
        {
            card1.cardFront.setPosition(gameWindowWidth * 0.22, gameWindowHeight * 0.35); // adjusted positioning
            card2.cardFront.setPosition(card1.cardFront.getPosition().x + 285, card1.cardFront.getPosition().y + 5); // adjusted positioning
        }

        else if(card2.faceValue == DICKENS)
        {
            card1.cardFront.setPosition(gameWindowWidth * 0.25, gameWindowHeight * 0.47); // regular positioning
            card2.cardFront.setPosition(card1.cardFront.getPosition().x + 180, card1.cardFront.getPosition().y - 100); // adjusted positioning
        }

        else
        {
            card1.cardFront.setPosition(gameWindowWidth * 0.25, gameWindowHeight * 0.47); // regular positioning
            card2.cardFront.setPosition(card1.cardFront.getPosition().x + 243, card1.cardFront.getPosition().y - 50); // regular positioning
        }

    }

    if (deck.size() >= 1)
    {
        // Set card value
        card1 = deck.deck.peek(deck.size() - 1);

        // Set card position
        if(card1.faceValue == DICKENS)
            card1.cardFront.setPosition(gameWindowWidth * 0.22, gameWindowHeight * 0.35); // adjusted positioning

        else
            card1.cardFront.setPosition(gameWindowWidth * 0.25, gameWindowHeight * 0.47); // regular positioning
    }

}

void ExplodingDickens::playShuffleCard() {
    // Turn on SHUFFLE_CARDS for ExplodingDickens object
    stateOn(SHUFFLE_CARDS);

    // Shuffle deck
    deck.shuffle();

}

void ExplodingDickens::playStealCard() {
    // Play sound
    Sounds::sounds[SWIPE].play();

    // Turn on Charles' taunts
    charlesTaunts();

    // Randomly choose a card from opponent's hand and add to player's hand (except for Defuse)
    int num = rand() % opponentHand.size();
    while(opponentHand.opponentHand[num].faceValue == DEFUSE_1 || opponentHand.opponentHand[num].faceValue == DEFUSE_2 || opponentHand.opponentHand[num].faceValue == DEFUSE_3) {
        num = rand() % opponentHand.size();
    }

    // Push card to player's hand
    playerHand.push_back(opponentHand.opponentHand[num]);

    // Delete card from opponent's hand
    opponentHand.opponentHand.erase(opponentHand.opponentHand.begin() + num);

    // Rearrange player card hand and opponent card hand
    playerHand.setPosition();
    opponentHand.setImages();

}

void ExplodingDickens::playSkipCard() {
    // Play sound
    Sounds::sounds[PING].play();

    // Turn on opponent's turn
    opponentTurn();

}

void ExplodingDickens::playDrawFromBottomCard() {
    // Play sound
    Sounds::sounds[WOOSH].play();

    // If the deck is not empty
    if(deck.size() > 0)
    {
        // If the card is the Exploding Dickens card
        if(deck.deck.peek(deck.size() - 1).faceValue == DICKENS)
        {
            // Delete from deck
            deck.pop();

            // Update deck card counter
            deck.updateCount();

            drawExplodingDickens();
        }

        // Otherwise
        else
        {
            // Push the bottom card into player's hand
            playerHand.push_back(deck.deck.peek(0));

            // Set the card's position
            playerHand.setPosition();

            // Delete from deck
            deck.deck.list.pop_front();

            // Update deck card counter
            deck.updateCount();

            // Turn on opponent's turn
            opponentTurn();
        }
    }
}

void ExplodingDickens::playDoubleSlapCard() {
    // Play sound
    Sounds::sounds[PUNCH].play();

    turnCounterOpponent = 2;

    for (int i = 0; i < turnCounterOpponent; ++i) {
        opponentTurn();
    }
}

void ExplodingDickens::playDefuseCard() {
    // Turn off DEFUSE_DICKENS_OVERLAY
    stateOff(DEFUSE_DICKENS_OVERLAY);

    if(deck.size() > 0)
    {
        // Turn on HIDE_DICKENS_OVERLAY
        stateOn(HIDE_DICKENS_OVERLAY);
    }

    else
    {
        // push DICKENS card to deck
        deck.push(DICKENS);
    }

}

void ExplodingDickens::hideDickens(int location) {
    // Turn off HIDE_DICKENS_OVERLAY
    stateOff(HIDE_DICKENS_OVERLAY);

    // Turn on HIDE_DICKENS_CARD
    stateOn(HIDE_DICKENS_CARD);

    // Declare temp card array
    int deckSize = deck.size();
    int newDeckSize = deckSize + 1;

    Card tempArray[deckSize];
    Card tempArray2[newDeckSize];

    // Fill temp array with cards from deck
    for (int i = 0; i < deckSize; ++i) {
        tempArray[i] = deck.top();
        // delete from deck
        deck.pop();
    }

    for (int i = 0; i < location; ++i) {
        tempArray2[i] = tempArray[i];
    }

    for (int i = location + 1; i < newDeckSize; ++i) {
        tempArray2[i] = tempArray[i - 1];
    }

    tempArray2[location] = DICKENS;

    // Delete deck
    deck.deck.list.~DoublyLinkedList<Card>();

    // Push cards to deck according to tempArray2 order
    for (int i = 0; i < newDeckSize; ++i) {
        deck.push(tempArray2[i]);
    }

    // Update deck card counter
    deck.updateCount();

    opponentTurn();
}


void ExplodingDickens::drawExplodingDickens() {
    // Turn on DEFUSE_DICKENS_OVERLAY for ExplodingDickens object
    stateOn(DEFUSE_DICKENS_OVERLAY);

    Sounds::sounds[RED_ALERT].play();
}

void ExplodingDickens::youExploded() {
    // Set objects to hidden
    deck.stateOn(HIDDEN);
    discardPile.stateOn(HIDDEN);
    playerHand.stateOn(HIDDEN);
    opponentHand.stateOn(HIDDEN);

    // Turn off DEFUSE_DICKENS_OVERLAY
    stateOff(DEFUSE_DICKENS_OVERLAY);

    // Reset clock
    clock7.restart();

    // Turn on PLAYER_LOSES for ExplodingDickens object
    stateOn(PLAYER_LOSES);

    Sounds::sounds[EXPLOSION].play();
}

void ExplodingDickens::youWin() {
    // Set objects to hidden
    deck.stateOn(HIDDEN);
    discardPile.stateOn(HIDDEN);
    playerHand.stateOn(HIDDEN);
    opponentHand.stateOn(HIDDEN);

    // Turn on PLAYER_WINS for ExplodingDickens object
    stateOn(PLAYER_WINS);

    Sounds::sounds[CHIMES].play();
}

void ExplodingDickens::cardEvent(Card card) {
    int temp;

    switch (card.getFaceValue()) {
        case SHUFFLE_1:
        case SHUFFLE_2:
        case SHUFFLE_3:
            playShuffleCard();
            break;
        case SEE_THE_FUTURE_1:
        case SEE_THE_FUTURE_2:
        case SEE_THE_FUTURE_3:
            playSeeTheFutureCard();
            break;
        case STEAL_A_CARD_1:
        case STEAL_A_CARD_2:
        case STEAL_A_CARD_3:
            playStealCard();
            break;
        case DRAW_FROM_BOTTOM_1:
        case DRAW_FROM_BOTTOM_2:
        case DRAW_FROM_BOTTOM_3:
            playDrawFromBottomCard();
            break;
        case SKIP_1:
        case SKIP_2:
        case SKIP_3:
        case SKIP_4:
        case SKIP_5:
            playSkipCard();
            break;
        case DOUBLE_SLAP_1:
        case DOUBLE_SLAP_2:
            playDoubleSlapCard();
            break;
        case DEFUSE_1:
            Sounds::sounds[DICKENS_WHAT_GREATER_GIFT].play();
            playDefuseCard();
            break;
        case DEFUSE_2:
            temp = rand() % 2;
            if(temp == 1)
                Sounds::sounds[RAVEN].play();
            else
                Sounds::sounds[GRIP_IM_A_DEVIL].play();
            playDefuseCard();
            break;
        case DEFUSE_3:
            Sounds::sounds[DICKENS_SHINY].play();
            playDefuseCard();
            break;

    }
}

void ExplodingDickens::chooseBestMove() {
    // Counter variable
    int count = 0;
    int location = 0;

    // If Charles holds any steal cards, use them
    for (int i = 0; i < opponentHand.size(); ++i) {
        if(opponentHand.opponentHand[i].faceValue == STEAL_A_CARD_1 || opponentHand.opponentHand[i].faceValue == STEAL_A_CARD_2 || opponentHand.opponentHand[i].faceValue == STEAL_A_CARD_3)
        {
            location = i;

            // Push the steal card into the discard pile
            discardPile.push_back(opponentHand.opponentHand[location]);

            // Set the card's position in the discard pile
            discardPile.setPosition();

            // Delete from Charles' hand
            opponentHand.opponentHand.erase(opponentHand.opponentHand.begin() + location);

            // Rearrange Charles' hand
            opponentHand.setImages();

            // Turn on CHARLES_STEALS
            stateOn(CHARLES_STEALS);

            // Play sound
            Sounds::sounds[SWIPE].play();

            // Randomly choose a card from player's hand and add to Charles' hand (except for Defuse)
            int num = rand() % playerHand.size();
            while(playerHand.cardHand[num].faceValue == DEFUSE_1 || opponentHand.opponentHand[num].faceValue == DEFUSE_2 || opponentHand.opponentHand[num].faceValue == DEFUSE_3) {
                num = rand() % playerHand.size();
            }

            // Push card to Charles' hand
            opponentHand.push_back(playerHand.cardHand[num]);

            // Delete card from player's hand
            playerHand.cardHand.erase(opponentHand.opponentHand.begin() + num);

            // Rearrange player card hand and opponent card hand
            playerHand.setPosition();
            opponentHand.setImages();
        }
    }
    // Draw from deck
    if(deck.top().faceValue == DICKENS)
    {
        // Delete from deck
        deck.pop();

        // Update deck card counter
        deck.updateCount();

        // Play sound
        Sounds::sounds[RED_ALERT].play();

        // Turn on CHARLES_DREW_DICKENS
        stateOn(CHARLES_DREW_EXP_DICKENS);

        count = 0;
        location = 0;

        // Count number of Defuse cards in Charles' hand
        for (int i = 0; i < opponentHand.size(); ++i) {
            if(opponentHand.opponentHand[i].faceValue == DEFUSE_1 || opponentHand.opponentHand[i].faceValue == DEFUSE_2 || opponentHand.opponentHand[i].faceValue == DEFUSE_3)
            {
                count++;
                location = i;
            }
        }

        // If Charles has no defuse cards
        if(count == 0)
            youWin();
        else
        {
            // Turn on CHARLES_IS_HIDING
            stateOn(CHARLES_HIDES_DICKENS_CARD);

            // Push the Defuse card into the discard pile
            discardPile.push_back(opponentHand.opponentHand[location]);

            // Set the card's position in the discard pile
            discardPile.setPosition();

            // Delete from Charles' hand
            opponentHand.opponentHand.erase(opponentHand.opponentHand.begin() + location);

            // Rearrange Charles' hand
            opponentHand.setImages();

            // Hide Dickens at bottom of deck
            deck.deck.list.push_front(DICKENS);

            // End turn
            playerTurn();
        }
    }

    else
    {
        // Push the card into Charles' hand
        opponentHand.push_back(deck.top());

        // Set the card's position
        opponentHand.setImages();

        // Delete from deck
        deck.pop();

        // Update deck card counter
        deck.updateCount();

       // End turn
        playerTurn();
    }
}

void ExplodingDickens::initializeVariables() {
    // SCREENS
    // Your turn screen
    yourTurnScreen.setTexture(Assets<sf::Texture>::getAsset(YOUR_TURN));

    // See the future screen
    seeTheFutureScreen.setTexture(Assets<sf::Texture>::getAsset(SEE_FUTURE));
    seeTheFutureScreen.setPosition((gameWindowWidth - seeTheFutureScreen.getGlobalBounds().width)/2, (gameWindowHeight - seeTheFutureScreen.getGlobalBounds().height)/2);
    button = Button("return", 37, sf::Color(233, 175, 175), sf::Vector2f(gameWindowWidth * 0.83, gameWindowHeight * 0.80), sf::Vector2f(172, 70), sf::Color(160, 44, 44), sf::Color(120, 33, 33), sf::Vector2f(gameWindowWidth * 0.8, gameWindowHeight * 0.789));

    // Defuse Exploding Dickens Screen
    defuseExplodingDickensScreen.setTexture(Assets<sf::Texture>::getAsset(DEFUSE_DICKENS));
    defuseExplodingDickensScreen.setPosition((gameWindowWidth - defuseExplodingDickensScreen.getGlobalBounds().width)/2, (gameWindowHeight - defuseExplodingDickensScreen.getGlobalBounds().height)/2);

    // You exploded screen
    Assets<sf::Texture>::assets[YOU_EXPLODED].setSmooth(true); // Smooth texture
    youExplodedScreen.setTexture(Assets<sf::Texture>::getAsset(YOU_EXPLODED));
    youExplodedScreen.setPosition((gameWindowWidth - youExplodedScreen.getGlobalBounds().width)/2, (gameWindowHeight - youExplodedScreen.getGlobalBounds().height)/2);

    // You won screen
    youWonScreen.setTexture(Assets<sf::Texture>::getAsset(YOU_WON));
    youWonScreen.setPosition((gameWindowWidth - youWonScreen.getGlobalBounds().width)/2, (gameWindowHeight - youWonScreen.getGlobalBounds().height)/2);

    // Play again (win) screen
    playAgainWinScreen.setTexture(Assets<sf::Texture>::getAsset(PLAY_AGAIN_W));
    playAgainWinScreen.setPosition((gameWindowWidth - playAgainWinScreen.getGlobalBounds().width)/2, (gameWindowHeight - playAgainWinScreen.getGlobalBounds().height)/2);
    buttonPlayAgain = Button("play again", 37, sf::Color(172, 147, 147), sf::Vector2f(gameWindowWidth * 0.443 - buttonPlayAgain.text.getGlobalBounds().width / 1.5, gameWindowHeight * 0.683), sf::Vector2f(190, 70), sf::Color(72, 55, 55), sf::Color(36, 28, 28), sf::Vector2f(gameWindowWidth * 0.425 - buttonPlayAgain.background.getGlobalBounds().width / 1.75, gameWindowHeight * 0.67));
    buttonLeaveGame = Button("leave game", 37, sf::Color(172, 147, 147), sf::Vector2f(gameWindowWidth * 0.437 - buttonLeaveGame.text.getGlobalBounds().width / 1.5, gameWindowHeight * 0.803), sf::Vector2f(215, 70), sf::Color(72, 55, 55), sf::Color(36, 28, 28), sf::Vector2f(gameWindowWidth * 0.415 - buttonLeaveGame.background.getGlobalBounds().width / 1.75, gameWindowHeight * 0.79));

    // Play again (lose) screen
    playAgainLoseScreen.setTexture(Assets<sf::Texture>::getAsset(PLAY_AGAIN_L));
    playAgainLoseScreen.setPosition((gameWindowWidth - playAgainLoseScreen.getGlobalBounds().width)/2, (gameWindowHeight - playAgainLoseScreen.getGlobalBounds().height)/2);

    // Hide the Dickens screen
    hideDickensScreen.setTexture(Assets<sf::Texture>::getAsset(HIDE_DICKENS));
    hideDickensScreen.setPosition((gameWindowWidth - hideDickensScreen.getGlobalBounds().width)/2, (gameWindowHeight - hideDickensScreen.getGlobalBounds().height)/2);
    hideDickens1 = Button("on the top", 28, sf::Color(170, 68, 0), sf::Vector2f(gameWindowWidth * 0.45, gameWindowHeight * 0.31), sf::Vector2f(175, 50), sf::Color(255, 127, 42), sf::Color(212, 85, 0), sf::Vector2f(gameWindowWidth * 0.425, gameWindowHeight * 0.3));
    hideDickens2 = Button("second", 28, sf::Color(170, 68, 0), sf::Vector2f(gameWindowWidth * 0.46, hideDickens1.text.getGlobalBounds().top + hideDickens1.text.getGlobalBounds().height * 1.95), sf::Vector2f(175, 50), sf::Color(255, 127, 42), sf::Color(212, 85, 0), sf::Vector2f(gameWindowWidth * 0.425, hideDickens1.background.getGlobalBounds().top + hideDickens1.background.getGlobalBounds().height * 1.25));
    hideDickens3 = Button("third", 28, sf::Color(170, 68, 0), sf::Vector2f(gameWindowWidth * 0.465, hideDickens2.text.getGlobalBounds().top + hideDickens2.text.getGlobalBounds().height * 2.48), sf::Vector2f(175, 50), sf::Color(255, 127, 42), sf::Color(212, 85, 0), sf::Vector2f(gameWindowWidth * 0.425, hideDickens2.background.getGlobalBounds().top + hideDickens2.background.getGlobalBounds().height * 1.25));
    hideDickens4 = Button("fourth", 28, sf::Color(170, 68, 0), sf::Vector2f(gameWindowWidth * 0.461, hideDickens3.text.getGlobalBounds().top + hideDickens3.text.getGlobalBounds().height * 2.5), sf::Vector2f(175, 50), sf::Color(255, 127, 42), sf::Color(212, 85, 0), sf::Vector2f(gameWindowWidth * 0.425, hideDickens3.background.getGlobalBounds().top + hideDickens3.background.getGlobalBounds().height * 1.25));
    hideDickens5 = Button("fifth", 28, sf::Color(170, 68, 0), sf::Vector2f(gameWindowWidth * 0.466, hideDickens4.text.getGlobalBounds().top + hideDickens4.text.getGlobalBounds().height * 2.44), sf::Vector2f(175, 50), sf::Color(255, 127, 42), sf::Color(212, 85, 0), sf::Vector2f(gameWindowWidth * 0.425, hideDickens4.background.getGlobalBounds().top + hideDickens4.background.getGlobalBounds().height * 1.25));
    hideDickens6 = Button("on the bottom", 28, sf::Color(170, 68, 0), sf::Vector2f(gameWindowWidth * 0.437, hideDickens5.text.getGlobalBounds().top + hideDickens5.text.getGlobalBounds().height * 2.35), sf::Vector2f(175, 50), sf::Color(255, 127, 42), sf::Color(212, 85, 0), sf::Vector2f(gameWindowWidth * 0.425, hideDickens5.background.getGlobalBounds().top + hideDickens5.background.getGlobalBounds().height * 1.25));
    hideDickens7 = Button("random", 28, sf::Color(170, 68, 0), sf::Vector2f(gameWindowWidth * 0.46, hideDickens6.text.getGlobalBounds().top + hideDickens5.text.getGlobalBounds().height * 2.4), sf::Vector2f(175, 50), sf::Color(255, 127, 42), sf::Color(212, 85, 0), sf::Vector2f(gameWindowWidth * 0.425, hideDickens6.background.getGlobalBounds().top + hideDickens6.background.getGlobalBounds().height * 1.25));

    // Exploding Dickens card (for Defuse Exploding Dickens Screen)
    explodingDickensCard = Card(DICKENS);
    explodingDickensCard.cardFront.setPosition(gameWindowWidth * 0.5 - (explodingDickensCard.cardFront.getGlobalBounds().width) / 2, gameWindowHeight * 0.5 - (explodingDickensCard.cardFront.getGlobalBounds().height) /2.5);

    // Charles' chat bubbles
    // Good luck
    goodLuckBubble.setTexture(Assets<sf::Texture>::getAsset(GOOD_LUCK));
    goodLuckBubble.setPosition(gameWindowWidth * 0.28, gameWindowHeight * 0.07);

    // You shall never defeat me
    neverDefeatMeBubble.setTexture(Assets<sf::Texture>::getAsset(YOU_SHALL_NEVER));
    neverDefeatMeBubble.setPosition(gameWindowWidth * 0.275, gameWindowHeight * 0.065);

    // Crying
    cryingBubble.setTexture(Assets<sf::Texture>::getAsset(CRYING));
    cryingBubble.setPosition(gameWindowWidth * 0.28, gameWindowHeight * 0.07);

    // Status blurbs
    // Shuffling
    statusShuffling.setTexture(Assets<sf::Texture>::getAsset(STATUS_SHUFFLING));
    statusShuffling.setPosition(gameWindowWidth * 0.435, gameWindowHeight * 0.46);

    // Hiding Exploding Dickens
    statusHidingDickens.setTexture(Assets<sf::Texture>::getAsset(STATUS_HIDING));
    statusHidingDickens.setPosition(gameWindowWidth * 0.435, gameWindowHeight * 0.46);

    // Charles is stealing one of your cards
    statusCharlesIsStealing.setTexture(Assets<sf::Texture>::getAsset(STATUS_CHARLES_IS_STEALING));
    statusCharlesIsStealing.setPosition(gameWindowWidth * 0.4, gameWindowHeight * 0.46);

    // Charles drew the Exploding Dickens
    statusCharlesDrewExplDickens.setTexture(Assets<sf::Texture>::getAsset(STATUS_CHARLES_DREW_EXPL_DICKENS));
    statusCharlesDrewExplDickens.setPosition(gameWindowWidth * 0.4, gameWindowHeight * 0.46);

    // Charles is hiding the Exploding Dickens
    statusCharlesIsHiding.setTexture(Assets<sf::Texture>::getAsset(STATUS_CHARLES_IS_HIDING));
    statusCharlesIsHiding.setPosition(gameWindowWidth * 0.4, gameWindowHeight * 0.46);

}

void ExplodingDickens::charlesTaunts() {
    // Turn on TAUNTS for ExplodingDickens object
    stateOn(TAUNTS);

    // restart the clock
    clock3.restart();
}

void ExplodingDickens::hideDickensMouseEvent(sf::Event& event, int cardPosition) {
    // If mouse button is pressed
    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        // Play sound
        Sounds::sounds[WOODEN_CLICK].play();

        // Change HIDE_DICKENS_OVERLAY to off
        stateOff(HIDE_DICKENS_OVERLAY);

        // Call hide Dickens function
        hideDickens(cardPosition);
    }
}

void ExplodingDickens::resetStates() {
    for (int i = 0; i < LAST; ++i) {
        stateOff(static_cast<StateName>(i));
    }
}

void ExplodingDickens::resetCards() {
    // Reset discard pile
    discardPile.discardPile.erase(discardPile.discardPile.begin(), discardPile.discardPile.end());

    // Reset player's hand
    playerHand.cardHand.erase(playerHand.cardHand.begin(), playerHand.cardHand.end());

    // Reset opponent's hand
    opponentHand.opponentHand.erase(opponentHand.opponentHand.begin(), opponentHand.opponentHand.end());
}

void ExplodingDickens::dealCards() {
    // Remove all 3 DEFUSE cards and the EXPLODING DICKENS card from deck
    for(int i = 0; i < 4; ++i) {
        deck.pop();
    }

    // Deal one DEFUSE card at random to each player
    std::map<CardName, bool> tempMap;

    int temp = rand() % 3 + 1;
    int temp2 = rand() % 2;
    if(temp == 1)
    {
        playerHand.push_back(DEFUSE_1);
        tempMap[DEFUSE_1] = true;

        if(temp2 == 0)
        {
            opponentHand.push_back(DEFUSE_2);
            tempMap[DEFUSE_2] = true;
        }
        else
        {
            opponentHand.push_back(DEFUSE_3);
            tempMap[DEFUSE_3] = true;
        }

    }
    else if(temp == 2)
    {
        playerHand.push_back(DEFUSE_2);
        tempMap[DEFUSE_2] = true;

        if(temp2 == 0)
        {
            opponentHand.push_back(DEFUSE_1);
            tempMap[DEFUSE_1] = true;
        }

        else
        {
            opponentHand.push_back(DEFUSE_3);
            tempMap[DEFUSE_3] = true;

        }

    }
    else
    {
        playerHand.push_back(DEFUSE_3);
        tempMap[DEFUSE_3] = true;

        if(temp2 == 0)
        {
            opponentHand.push_back(DEFUSE_1);
            tempMap[DEFUSE_1] = true;
        }

        else
        {
            opponentHand.push_back(DEFUSE_2);
            tempMap[DEFUSE_2] = true;
        }
    }

    // Shuffle deck
    deck.shuffle();

    // Deal 4 additional cards to each player
    for(int i = 0; i < 4; ++i) {
        // Deal to player's hand
        playerHand.push_back(deck.top());

        // Delete from deck
        deck.pop();

        // Deal to opponent's hand
        opponentHand.push_back(deck.top());

        // Delete from deck
        deck.pop();
    }

    // Add remaining DEFUSE back to deck
    if(!tempMap[DEFUSE_1])
        deck.push(DEFUSE_1);
    else if(!tempMap[DEFUSE_2])
        deck.push(DEFUSE_2);
    else
        deck.push(DEFUSE_3);

    // Add EXPLODING DICKENS back to deck
    deck.push(DICKENS);

    // Update deck card counter
    deck.updateCount();
}

