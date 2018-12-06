//
//  Game.h
//  BlackjackProject
//
//  Created by Chelsea Marfil on 12/5/18.
//  Copyright © 2018 ChelseaMarfil. All rights reserved.
//

#ifndef Game_h
#define Game_h

// Would we include these or make them friend classes?
#include "Card.h"
#include "Player.h"
#include "DeckOfCards.h"

#include <vector>

class Game {
public:
    Game();
    void enterAccountNumber();
    void enterAmountToBet();
    vector<Card> selectAndShowTwo(); // array or vector
    Card selectAndShowOne();
    vector<Card> showValueOfCards(); // int value or Card value?
    void askHitStandOrSplit();
    void hit();
    void stand();
    void split();
    int calcValueOfCards(); // might be the same as showValueOfCards?
private:
    Player player;
    DeckOfCards deck;
};

#endif /* Game_h */
