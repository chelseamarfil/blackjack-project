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

int main(int argc, const char * argv[]) {
    Account a(1001, 100);
    Player p1 = Player(a);
    accountsVector.push_back(a);
    printAccounts();
    
    bool gameEnd = false;
    while(gameEnd == false){
	    DeckOfCards *deck = new DeckOfCards();
	
		//    deck.printDeck();
		//    cout << endl << endl << endl;
		//    deck.shuffle();
		//    deck.printDeck();
	    Game g(*deck);
	    //player's accounts 
//        cout<<"Player's Account: "<<endl;
//        g.addNewAccount(100);
//        g.addNewAccount(100);
//        g.addNewAccount(100);
//        g.addNewAccount(100);
//        g.printAccounts();
		
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
	    g.setDealer(Player(7777)); 
	    
	    // b. Ask the user to enter the amount of money he/she wants to bet, make sure it's a valid amount.
	    bool validBetAmount = 0;
	    double betAmount;
	    double userMoneyAmount = getMoneyAmount(acctNum);
	    cout << "You have $" << userMoneyAmount << " available to bet." << endl;
	    do {
	        betAmount = g.promptUserForAmountToBet();
	        if (betAmount <= userMoneyAmount) {
	            cout << "You are betting $" << betAmount << "." << endl;
	            validBetAmount = 1;
	        } else {
	            cout << "Can't bet more money than you have." << endl;
	        }
	    } while(!validBetAmount);
	    
        // Shuffle the card deck.
        cout << endl << endl;
	    deck->shuffle();
	    deck->printDeck();
        cout << endl << endl;
        
	    // c. The program will select and show the user two cards from the shuffled deck.
		vector<Card> playersHand = g.getPlayer().getHand();
		vector<Card> playersCards = g.selectAndShowTwo(*deck, playersHand);
		cout << "Your cards are: " << endl;
		for(int i = 0; i < playersCards.size(); i++){
			cout << playersCards[i].print() << endl;
		}
		
	    // d. The program will select another two cards and show one card (dealer's cards).
        vector<Card> dealersHand = g.getDealer().getHand();
        vector<Card> dealersCards = g.selectAndShowTwo(*deck,dealersHand);
        cout << endl << endl << "One of the dealer's cards is: " << endl;
        cout << dealersCards[0].print();
        cout << endl << endl;
        
	    // e. The program will show the value of user's cards and ask if the user wants to hit or stand or split.
	    //cout<<"The cards in your hand are: "<<endl;
	    //g.showHand(playersHand);
	    cout<<"The value of your hand is: "<< g.calcValueOfHand(playersHand)<<endl;
        
        
        // f. If the user decides to stand, decide how the program will select a card for the dealer.
	    // g. If the user decides to hit and the total value is less than 21, the program will select a card for the user. If the total value of the user’s cards is more than 21 during this process, the user will lose; otherwise, decide how the program will select a card for the dealer.
	    // h. If the user decides to split, the dealer will draw two cards for the user. The user now has two hands. Also, an additional bet of equal value to the original bet is placed on the second hand. Proceed the game as in step f and/or g.

	    
	    //if the user has not hit 21 yet he can keep going
	    while (g.calcValueOfHand(playersHand) < 21 ){
	    	g.askHitStandOrSplit(*deck, playersHand, dealersHand, p1);
	    	cout << "The value of your hand is now: " << g.calcValueOfHand(playersHand) << endl;
	    	cout << "\n" << endl;
	    	
		}
	    //The user has lost! 
	    // -Otherwise, the dealer wins.
	    //-If the user loses, the user win 0 dollars.
		if(g.calcValueOfHand(playersHand) > 21)
		{
	    	cout<<"Sorry you lost! The dealer won. "<< endl;
	    	cout << "The dealer's score: " << g.calcValueOfHand(dealersHand) << endl;
	    	cout << "Your score: " << g.calcValueOfHand(playersHand) << endl;
	    	int currMoney = userMoneyAmount - betAmount;
            updateAccount(acctNum, currMoney);
	    	cout << "Your balance is now: " << currMoney << endl << endl;
	    	
	    	// k. The program will ask whether the user wants to play again. 
			//If so, these steps are repeated. 
			//If not, the program displays the total amount of betting money and the total amount won.
	    	cout << "Do you want to play again?" << endl;
	    	string userInput;
	    	cin >> userInput;
	    	if(userInput == "yes" || userInput == "Yes"){
	    		gameEnd = false;
            } else{
				gameEnd = true;
				break; 
			}	
		// -If the value of the user's cards and the dealer's cards are the same, the game is a tie.
		//-If the user ties, the money inputted will be split in half.
		} else if(g.calcValueOfHand(playersHand) == g.calcValueOfHand(dealersHand)){
			cout<<"You've tied with the dealer. You will win half of what you've bet." <<endl; 

			int currMoney = userMoneyAmount + (betAmount / 2);
            updateAccount(acctNum, currMoney);
            //If the player ties with the dealer, then their betted money will be cut in half.
	    	cout << "Your balance is now: " << currMoney << endl << endl;
	    	
	    	// k. The program will ask whether the user wants to play again. 
			//If so, these steps are repeated. 
			//If not, the program displays the total amount of betting money and the total amount won.
			cout <<"Do you want to play again?" << endl;
	    	string userInput;
	    	cin >> userInput;
	    	if(userInput == "yes" || userInput == "Yes"){
	    		gameEnd = false;
			} else {
				gameEnd = true;
				break; 
			}	
		} 
		
		//-If the value of the user’s cards is more than the dealer’s cards but less than 21, the user wins.
		// j. If the user wins, the money inputted will be doubled.
		else if (g.calcValueOfHand(playersHand) > g.calcValueOfHand(dealersHand) && g.calcValueOfHand(playersHand) <= 21)
		{
			cout<<"You've won!! Congratulations! " <<endl; 

			int currMoney = userMoneyAmount + (betAmount * 2);
            updateAccount(acctNum, currMoney);
            //If the player ties with the dealer, then their betted money will be cut in half.
	    	cout << "Your balance is now: " << currMoney << endl << endl;
			
			// k. The program will ask whether the user wants to play again. 
			//If so, these steps are repeated. 
			//If not, the program displays the total amount of betting money and the total amount won.
			cout <<"Do you want to play again?" << endl;
	    	string userInput;
	    	cin >> userInput;
	    	if(userInput == "yes" || userInput == "Yes"){
	    		gameEnd = false;
			} else {
				gameEnd = true;
				break; 
			}	
		} else{
			g.askHitStandOrSplit(*deck, playersHand, dealersHand, p1);
				

	      
	    
	    // l. Be sure to update the player’s account accordingly.

		}
	}
    return 0;
}



