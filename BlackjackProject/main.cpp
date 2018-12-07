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
    //TESTING!!!!
    
    DeckOfCards deck;
//    deck.printDeck();
//    cout << endl << endl << endl;
//    deck.shuffle();
//    deck.printDeck();
    Game g(deck);
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
    g.setPlayer(Player(acctNum));
    
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
    
    // f. If the user decides to stand, decide how the program will select a card for the dealer.
    // g. If the user decides to hit and the total value is less than 21, the program will select a card for the user. If the total value of the user’s cards is more than 21 during this process, the user will lose; otherwise, decide how the program will select a card for the dealer.
    // h. If the user decides to split, the dealer will draw two cards for the user. The user now has two hands. Also, an additional bet of equal value to the original bet is placed on the second hand. Proceed the game as in step f and/or g.
    // i. The winner is determined by the total value of the cards.
    // -If the value of the user’s cards is more than the dealer’s cards but less than 21, the user wins.
    // -If the value of the user’s cards and the dealer’s cards are the same, the game is a tie.
    // -Otherwise, the dealer wins.
    // j. If the user wins, the money inputted will be doubled. -If the user ties, the money inputted will be split in half. -If the user loses, the user win 0 dollars.
    // k. The program will ask whether the user wants to play again. If so, these steps are repeated. If not, the program displays the total amount of betting money and the total amount won.
    // l. Be sure to update the player’s account accordingly.

    
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



