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

// static vector<Account> accountsVector;

class Game {
public:
    Game(); //done

    Game(DeckOfCards &deck);
    Game(DeckOfCards &deck, Player player, Player dealer); //done
    void setPlayer(Player player); // done
    void setDealer(Player dealer); //done
    Player getPlayer() const; //done
    Player getDealer() const; //done
    
    int promptUserForAccountNumber(); //done
    double promptUserForAmountToBet(); //done
    
    vector<Card> selectAndShowTwo(DeckOfCards &mDeck, vector<Card> &hand); //done
    Card selectAndShowOne(DeckOfCards &mDeck, vector<Card> &hand); //done
    void showHand(vector<Card> &hand); //done
    
    void askHitStandOrSplit(DeckOfCards &mDeck, vector<Card> &hand, vector<Card> &dealerHand, Player p1); // done
    
    void hit(DeckOfCards &mDeck, vector<Card> &hand, vector<Card> &dealerHand);
    void stand(DeckOfCards &mDeck, vector<Card> &hand, vector<Card> &dealerHand);
    void split(DeckOfCards &mDeck, vector<Card> &hand, vector<Card> &dealerHand, Player p1);
    
    int calcValueOfHand(vector<Card> &hand); 
    
//    void addNewAccount(); //done
//    void addNewAccount(double money); //done
//    
//    double getMoneyAmount(int accountNumber);
//    bool accountExists(int accountNumber);
//    void updateAccount(int accountNumber, double amountToAdd);
    
    // void printMap(); // might not be necessary
    void printAccounts();
private:
    Player mPlayer;
    Player mDealer;
    int playerScore;
    int dealerScore;
    DeckOfCards mDeck;
};

#endif /* Game_h */
