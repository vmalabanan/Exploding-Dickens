//
// Created by vanes on 11/25/2021.
//

#ifndef BUTTON_H_EXPLODINGDICKENS_H
#define BUTTON_H_EXPLODINGDICKENS_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include "GameScreen.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "OpponentHand.h"
#include "Sounds.h"

class ExplodingDickens: public sf::Drawable, public States {
public:
    ExplodingDickens();

    // Sets the object's states based on certain conditions
    void eventHandler(sf::RenderWindow& window, sf::Event event);

    // Updates the object based on the state it's in
    void update();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    void game();

private:
    void firstTurn();
    void playerTurn();
    void opponentTurn();
    void playSeeTheFutureCard();
    void playShuffleCard();
    void playStealCard();
    void playSkipCard();
    void playDrawFromBottomCard();
    void playDoubleSlapCard();
    void playDefuseCard();
    void hideDickens(int location);

    void drawExplodingDickens();
    void youExploded();
    void youWin();
    void cardEvent(Card card);
    void chooseBestMove();
    void initializeVariables();

    void charlesTaunts();

    void hideDickensMouseEvent(sf::Event& event, int cardPosition);

    void resetCards();
    void resetStates();
    void dealCards();

    // turn counter
    int turnCounterOpponent;
    int turnCounterPlayer;

    GameScreenName gameStateBG;

    Card card1;
    Card card2;
    Card card3;
    Card explodingDickensCard;
    Card defuse1;
    Card defuse2;

    Deck deck;
    DiscardPile discardPile;
    CardHand playerHand;
    OpponentHand opponentHand;

    // Overlays
    sf::Sprite yourTurnScreen;
    sf::Sprite seeTheFutureScreen;
    sf::Sprite defuseExplodingDickensScreen;
    sf::Sprite youExplodedScreen;
    sf::Sprite youWonScreen;
    sf::Sprite playAgainWinScreen;
    sf::Sprite playAgainLoseScreen;
    sf::Sprite hideDickensScreen;

    // Charles chat bubbles
    sf::Sprite goodLuckBubble;
    sf::Sprite neverDefeatMeBubble;
    sf::Sprite cryingBubble;

    // Status blurbs
    sf::Sprite statusShuffling;
    sf::Sprite statusHidingDickens;
    sf::Sprite statusCharlesIsStealing;
    sf::Sprite statusCharlesDrewExplDickens;
    sf::Sprite statusCharlesIsHiding;

    Button button;
    Button buttonPlayAgain;
    Button buttonLeaveGame;
    Button hideDickens1;
    Button hideDickens2;
    Button hideDickens3;
    Button hideDickens4;
    Button hideDickens5;
    Button hideDickens6;
    Button hideDickens7;

    // Clocks used to track time spent in different states
    sf::Clock clock;
    sf::Clock clock2;
    sf::Clock clock3;
    sf::Clock clock4;
    sf::Clock clock5;
    sf::Clock clock6;
    sf::Clock clock7;
    sf::Clock clock8;
    sf::Clock clock9;
    sf::Clock clock10;

};


#endif //BUTTON_H_EXPLODINGDICKENS_H
