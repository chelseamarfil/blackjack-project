/* Names: Tiffany Lam, Chelsea Marfil, Rachel Pai
 * ID: , 014400501,
 * Class: CECS 282 C++
 * Instructor: Minhthong Nguyen
 * Due Date: December 12, 2018
 * Purpose: Using what we've learned in this course to implement this final project.
 */

#include <iostream>
#include "DeckOfCards.h"
#include "Game.h"
#include <map>
using namespace std;

int main(int argc, const char * argv[]) {
    
    DeckOfCards deck;
//    deck.printDeck();
//    cout << endl << endl << endl;
//    deck.shuffle();
//    deck.printDeck();
    g.addNewAccount(100);
    g.addNewAccount(100);
    g.addNewAccount(100);
    g.printAccounts();

    // a. Ask the user to enter the account number, make sure it exists.
    bool validAccountNumber = 0;
    int acctNum;
    do {
        acctNum = g.promptUserForAccountNumber();
        if (!g.accountExists(acctNum)) {
            cout << "Account doesn't exist." << endl;
        } else {
            cout << "Account exists!" << endl;
            validAccountNumber = 1;
        }
    } while(!validAccountNumber);
    
    Game g(deck);
    
    // g.printAccounts();

    
    // b. Ask the user to enter the amount of money he/she wants to bet.
    bool validBetAmount = 0;
    double betAmount;
    double userMoneyAmount = g.getMoneyAmount(acctNum);
    cout << "You have $" << userMoneyAmount << " available to bet." << endl;
    do {
        betAmount = g.promptUserForAmountToBet();
        if (betAmount < userMoneyAmount) {
            cout << "You are betting $" << betAmount << "." << endl;
            validBetAmount = 1;
        } else {
            cout << "Can't bet more money than you have." << endl;
        }
    } while(!validBetAmount);
    
    
    // c. The program will randomly select and show the user two cards.
    
    // d. The program will randomly select another two cards and show one card (dealer’s cards).
    
    // e. The program will show the value of user’s cards and ask if the user wants to hit or stand or split.
    
    // testers
    cout << endl <<  "TESTING: " << endl;
    g.addNewAccount();
    // cout << "TEST" << g.accountExists(accountNumberCounter) << endl;
    g.printAccounts();
    
    
//    cout << g.getMoneyAmount(1000)<< endl;
//    g.updateAccount(1000, 100);
//    cout << g.getMoneyAmount(1000)<< endl;
//    g.updateAccount(1000, -100);
//    cout << g.getMoneyAmount(1000)<< endl;
    
    
    //menu
    return 0;
}



