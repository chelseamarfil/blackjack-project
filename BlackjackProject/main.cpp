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
using namespace std;

static vector<Account> accountsVector;

void updateAccount(int accountNumber, double amountToAdd) {
    for(int i = 0; i < accountsVector.size(); i++) {
        if (accountsVector[i].getAccountNumber() == accountNumber) {
            accountsVector[i].setMoney(amountToAdd);
        }
    }
}

bool accountExists(int accountNumber) {
    for(int i = 0; i < accountsVector.size(); i++) {
        if (accountsVector[i].getAccountNumber() == accountNumber) {
            return 1;
        }
    }
    return 0;
}

double getMoneyAmount(int accountNumber) {
    for(int i = 0; i < accountsVector.size(); i++) {
        if (accountsVector[i].getAccountNumber() == accountNumber) {
            return accountsVector[i].getMoney();
        }
    }

    return -1;
}

void printAccounts() {
    for(int i = 0; i < accountsVector.size(); i++) {
        cout << accountsVector[i].getAccountNumber() << ": " << accountsVector[i].getMoney() << endl;
    }
}

void userWins(Game g, vector<Card> &playersHand, vector<Card> &dealersHand, double userMoneyAmount, double betAmount, int acctNum, double &moneyWon) {
    cout << endl << "You won! "<< endl;
    
    cout << "The dealer's score: " << g.calcValueOfHand(dealersHand) << endl;
    cout << "Your score: " << g.calcValueOfHand(playersHand) << endl;
    
    double currMoney = userMoneyAmount + (betAmount * 2);
    moneyWon += (betAmount * 2);
    
    updateAccount(acctNum, currMoney);
    cout << "Your balance is now: " << getMoneyAmount(acctNum) << endl << endl;
}

void userTies(Game g, vector<Card> &playersHand, vector<Card> &dealersHand, double userMoneyAmount, double betAmount, int acctNum, double &moneyWon) {
    cout<<"You've tied with the dealer. You will win half of what you've bet." <<endl;
    cout << "The dealer's score: " << g.calcValueOfHand(dealersHand) << endl;
    cout << "Your score: " << g.calcValueOfHand(playersHand) << endl;
    
    double currMoney = userMoneyAmount + (betAmount / 2);
    moneyWon += betAmount / 2;
    
    updateAccount(acctNum, currMoney);
    //If the player ties with the dealer, then their betted money will be cut in half.
    cout << "Your balance is now: " << getMoneyAmount(acctNum) << endl << endl;
}

void dealerWins(Game g, vector<Card> &playersHand, vector<Card> &dealersHand, double userMoneyAmount, double betAmount, int acctNum) {
    cout << "Dealer won." << endl;
    cout << "The dealer's score: " << g.calcValueOfHand(dealersHand) << endl;
    cout << "Your score: " << g.calcValueOfHand(playersHand) << endl;
    double currMoney = userMoneyAmount - betAmount;
    updateAccount(acctNum, currMoney);
    cout << "Your balance is now: " << getMoneyAmount(acctNum) << endl << endl;
}

void askPlayAgain(bool &gameEnd, double betTracker, double moneyWon) {
    cout << "Do you want to play again?" << endl;
    string userInput;
    cin >> userInput;
    if(userInput == "yes" || userInput == "Yes"){
        gameEnd = false;
    } else if (userInput == "no" || userInput == "No") {
        cout << "Total amount of betting money: " << betTracker << endl;
        cout << "Total amount of money won: " << moneyWon << endl;
        gameEnd = true;
    }
}

int main(int argc, const char * argv[]) {
    Account a(1001, 100);
    Player p1 = Player(a);
    accountsVector.push_back(a);
    printAccounts();

    double betTracker = 0;
    double moneyWon = 0;
    
    bool gameEnd = false;
    while(gameEnd == false){
	    DeckOfCards *deck = new DeckOfCards();
	    Game g(*deck);

	    // a. Ask the user to enter the account number, make sure it exists.
	    bool validAccountNumber = 0;
	    int acctNum;
	    do {
	        acctNum = g.promptUserForAccountNumber();
	        if (!accountExists(acctNum)) {
	            cout << "Account doesn't exist." << endl;
	        } else {
	            cout << "Account exists!" << endl;
	            validAccountNumber = 1;
	        }
	    } while(!validAccountNumber);
        
        // Set the player of the game.
	    g.setPlayer(Player(acctNum));
	    
	    // Set the dealer of the game.
	    //g.setDealer(Player(7777));
	    
	    // b. Ask the user to enter the amount of money he/she wants to bet, make sure it's a valid amount.
	    bool validBetAmount = 0;
        double betAmount;
	    double userMoneyAmount = getMoneyAmount(acctNum);
	    cout << "You have $" << userMoneyAmount << " available to bet." << endl;
	    do {
	        betAmount = g.promptUserForAmountToBet();
	        if (betAmount <= userMoneyAmount) {
	            cout << "You are betting $" << betAmount << "." << endl;
                betTracker += betAmount;
	            validBetAmount = 1;
	        } else {
	            cout << "Can't bet more money than you have." << endl;
	        }
	    } while(!validBetAmount);
	    
        // Shuffle the card deck.
	    deck->shuffle();
        cout << endl << endl;
        
	    // c. The program will select and show the user two cards from the shuffled deck.
		vector<Card> playersHand = g.getPlayer().getHand();
		playersHand = g.selectAndShowTwo(*deck, playersHand);
		cout << "Your cards are: " << endl;
		for(int i = 0; i < playersHand.size(); i++){
			cout << playersHand[i].print() << endl;
		}
		
	    // d. The program will select another two cards and show one card (dealer's cards).
        vector<Card> dealersHand = g.getDealer().getHand();
        dealersHand = g.selectAndShowTwo(*deck,dealersHand);
        cout << endl << "One of the dealer's cards is: " << endl;
        cout << dealersHand[0].print();
        cout << endl << endl;
        
	    // e. The program will show the value of user's cards

	    cout << "The value of your hand is: " << g.calcValueOfHand(playersHand)<<endl;
        
        
        bool userStands = false;
        while (!userStands && g.calcValueOfHand(playersHand) < 21) {
            // ask if the user wants to hit or stand or split.
            string user = g.askHitStandOrSplit(*deck, playersHand, dealersHand, p1);
            
            // f. If the user decides to stand, decide how the program will select a card for the dealer.
            if (user == "stand") {
                cout << endl << "The dealers hand contains the cards: " << endl;
                for (int i = 0; i < dealersHand.size(); i ++) {
                    cout << dealersHand[i].print() << endl;
                }
                
                cout << endl << "Dealer's hand value before dealing: " << g.calcValueOfHand(dealersHand) << endl;
                
                while (g.calcValueOfHand(dealersHand) < 17) {
                    Card newCard = g.selectAndShowOne(*deck, dealersHand);
                    cout << "Dealer's new card: " << newCard.print() << endl;
                }
                cout << "Dealers hand value after dealing: " << g.calcValueOfHand(dealersHand) << endl;
    
                userStands = true;
                
            // g. If the user decides to hit and the total value is less than 21, the program will select a card for the user. If the total value of the user's cards is more than 21 during this process, the user will lose; otherwise, decide how the program will select a card for the dealer.
            } else if (user == "hit") {
                cout<<"You have drawn a: "<< g.selectAndShowOne(*deck, playersHand).print()<<endl;
                cout << "The value of your hand is now: " << g.calcValueOfHand(playersHand) << endl;
            }
        }
        
        // h. TODO: If the user decides to split, the dealer will draw two cards for the user. The user now has two hands. Also, an additional bet of equal value to the original bet is placed on the second hand. Proceed the game as in step f and/or g.

        
            if(g.calcValueOfHand(playersHand) > 21) {
                dealerWins(g, playersHand, dealersHand, userMoneyAmount, betAmount, acctNum);
                
                askPlayAgain(gameEnd, betTracker, moneyWon);
                
                if (gameEnd == true) {
                    break;
                }
            } else if(g.calcValueOfHand(dealersHand) > 21) {
                userWins(g, playersHand, dealersHand, userMoneyAmount, betAmount, acctNum, moneyWon);
                
                askPlayAgain(gameEnd, betTracker, moneyWon);
                
                if (gameEnd == true) {
                    break;
                }

            } else if(g.calcValueOfHand(playersHand) == g.calcValueOfHand(dealersHand)){
                userTies(g, playersHand, dealersHand, userMoneyAmount, betAmount, acctNum, moneyWon);
                
                askPlayAgain(gameEnd, betTracker, moneyWon);
                
                if (gameEnd == true) {
                    break;
                }
            }
        
            else if (g.calcValueOfHand(playersHand) > g.calcValueOfHand(dealersHand) && g.calcValueOfHand(playersHand) <= 21)
            {
                userWins(g, playersHand, dealersHand, userMoneyAmount, betAmount, acctNum, moneyWon);
                
                askPlayAgain(gameEnd, betTracker, moneyWon);
                
                if (gameEnd == true) {
                    break;
                }
            } else {
                dealerWins(g, playersHand, dealersHand, userMoneyAmount, betAmount, acctNum);
                
                askPlayAgain(gameEnd, betTracker, moneyWon);
                
                if (gameEnd == true) {
                    break;
                }
            }
        
	}
    return 0;
}


