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
#include <map>

static map<int, double> mAccountMap;
// = {{1000, 100.00}, {1001, 100.00}, {1002, 100.00}, {1003, 100.00}}

//static int accountNumberCounter = 1000;

class Game {
public:
    Game();
    Game(DeckOfCards deck);
    void setPlayer(Player player);
    
    int promptUserForAccountNumber();
    double promptUserForAmountToBet();
    
    vector<Card> selectAndShowTwo(); // array or vector
    Card selectAndShowOne();
    vector<Card> showValueOfCards(); // int value or Card value?
    void askHitStandOrSplit();
    void hit();
    void stand();
    void split();
    int calcValueOfCards(); // might be the same as showValueOfCards?
    
    void addNewAccount();
    void addNewAccount(double money);
    
    double getMoneyAmount(int accountNumber);
    bool accountExists(int accountNumber);
    void updateAccount(int accountNumber, double amountToAdd);
    
    void printMap(); // might not be necessary
private:
    Player mPlayer;
    DeckOfCards mDeck;
};

#endif /* Game_h */
