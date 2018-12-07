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

// static map<int, double> mAccountMap;
// = {{1000, 100.00}, {1001, 100.00}, {1002, 100.00}, {1003, 100.00}}

static vector<Account> accountsVector;

class Game {
public:
    Game(); //done
    Game(DeckOfCards deck); //done
    void setPlayer(Player player); // done - how do we call this?
    
    int promptUserForAccountNumber(); //done
    double promptUserForAmountToBet(); //done
    
    vector<Card> selectAndShowTwo(); 
    Card selectAndShowOne();
    
    vector<Card> showValueOfCards(); // int value or Card value?
    
    void askHitStandOrSplit(); // done
    
    void hit();
    void stand();
    void split();
    
    int calcValueOfCards(); 
    
    void addNewAccount(); //done
    void addNewAccount(double money); //done
    
    double getMoneyAmount(int accountNumber);
    bool accountExists(int accountNumber);
    void updateAccount(int accountNumber, double amountToAdd);
    
    // void printMap(); // might not be necessary
    void printAccounts();
private:
    Player mPlayer;
    DeckOfCards mDeck;
};

#endif /* Game_h */
