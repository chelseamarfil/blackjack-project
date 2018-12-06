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


///**
//If the user decides to stand, decide how the program will
//select a card for the dealer
//**/
//
//void stand ()
//{
//    int decision;
//    cin>>decision;
//
//    if (decision < 5 )
//    {
//        hit();
//    }
//
//    else if (decision > 5)
//    {
//        split();
//    }
//}

int main(int argc, const char * argv[]) {
    
    DeckOfCards deck;
    Game g(deck);
    
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
    cout << g.getMoneyAmount(1000)<< endl;
    g.updateAccount(1000, 100);
    cout << g.getMoneyAmount(1000)<< endl;
    g.updateAccount(1000, -100);
    cout << g.getMoneyAmount(1000)<< endl;
    
    
    //menu
    return 0;
}



