#include "Game.h"
#include <iostream>

using namespace std;

Game::Game() {
    mDeck = DeckOfCards();
}

Game::Game(DeckOfCards deck) {
    mDeck = deck;
}

void Game :: setPlayer(Player player) 
	{
        mPlayer = player;
    }

/** Ask the user to enter the account number.
 @return acctNum - the user's account number.
 */
int Game::promptUserForAccountNumber() {
    cout << "Enter your account number: ";
    int acctNum;
    cin >> acctNum;
    return acctNum;
}

/** Ask the user to enter the amount of money he/she wants to bet.
 @return betAmt - the amount of money user wants to bet.
 */
double Game::promptUserForAmountToBet() {
    cout << "Enter the amount of money to bet: ";
    int betAmt;
    cin >> betAmt;
    return betAmt;
}

///** Randomly select and show the user two cards.
// @return
// */
//vector<Card> selectAndShowTwo() {
//    DeckOfCards deck;
//}

/**
 Updates the money in an account.
 @param accountNumber of the player
 @param amountToAdd to the player's money - param will be negative if user loses money.
 */
void Game::updateAccount(int accountNumber, double amountToAdd) {
    map<int, double>::iterator p = mAccountMap.find(accountNumber);
    if (p == mAccountMap.end()) {
        cout << "Account doesn't exist." << endl;
    } else {
        mAccountMap[accountNumber] = getMoneyAmount(accountNumber) + amountToAdd;
    }
}

/**
 Adds a new account to the map. New account numbers will be incremented by 1, and will start off with $0.
 */
void Game::addNewAccount() {
    accountNumberCounter++;
    mAccountMap[accountNumberCounter] = 0;
}

/**
 Adds a new account to the map. New account numbers will be incremented by 1, and will start off with a given amount of money.
 */
void Game::addNewAccount(double money) {
    accountNumberCounter++;
    mAccountMap[accountNumberCounter] = money;
}

/**
If the user decides to stand, decide how the program will
select a card for the dealer
**/

void Game :: stand ()
{
    int decision;
    cin>>decision;

    if (decision < 5 )
    {
        hit();
    }

    else if (decision > 5)
    {
        split();
    }
}


/**
 Gets the amount of money associated with an account number.
 @param accountNumber the account number being searched
 @return the amount of money in the account
 */
double Game::getMoneyAmount(int accountNumber) {
//    map<int, double>::iterator p = mAccountMap.find(accountNumber);
//    if (p == mAccountMap.end()) {
//        return 0;
//    } else {
//        return p->second;
//    }
    
    if (accountExists(accountNumber)) {
        map<int, double>::iterator p = mAccountMap.find(accountNumber);
        return p->second;
    } else {
        return -1;
    }
}

/**

 */
bool Game::accountExists(int accountNumber) {
    map<int, double>::iterator p = mAccountMap.find(accountNumber);
    if (p == mAccountMap.end()) {
        return 0;
    } else {
        return 1;
    }
}

void Game::printMap() {
    for (map<int, double>::iterator pos = mAccountMap.begin();
         pos != mAccountMap.end(); pos++)
    {
        cout << pos->first << ": " << pos->second << "\n";
    }
}
