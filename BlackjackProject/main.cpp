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
    cout<<"----------------------------------------------"<<endl;
	cout <<"You won! "<< endl;
    
    cout << "The dealer's score: " << g.calcValueOfHand(dealersHand) << endl;
    cout << "Your score: " << g.calcValueOfHand(playersHand) << endl;
    //you will be taking their money, but giving it back to them + the amount they bet 
    double currMoney = userMoneyAmount  + betAmount; 
    
     moneyWon += (betAmount); //give thier money back and the amount they bet
//    currMoney += moneyWon;     
	
    updateAccount(acctNum, currMoney);
    cout << "Your balance is now: " << getMoneyAmount(acctNum) << endl << endl;
}

void userTies(Game g, vector<Card> &playersHand, vector<Card> &dealersHand, double userMoneyAmount, double betAmount, int acctNum, double &moneyWon) {
    cout<<"----------------------------------------------"<<endl;
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
    cout<<"----------------------------------------------"<<endl;
	cout << "Dealer won." << endl;
    cout << "The dealer's score: " << g.calcValueOfHand(dealersHand) << endl;
    cout << "Your score: " << g.calcValueOfHand(playersHand) << endl;
    double currMoney = userMoneyAmount - betAmount;
    updateAccount(acctNum, currMoney);
    cout << "Your balance is now: " << getMoneyAmount(acctNum) << endl << endl;
}

void askPlayAgain(bool &gameEnd, double betTracker, double &moneyWon) {
    cout << "Do you want to play again?" << endl;
    string userInput;
    cin >> userInput;
    if(userInput == "yes" || userInput == "Yes"){
    	
        gameEnd = false;
    } else if (userInput == "no" || userInput == "No") {
        //TODO: not sure how exactly he wants us to calculate moneyWon...
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
	    
	    // b. Ask the user to enter the amount of money he/she wants to bet, make sure it's a valid amount.
	    bool validBetAmount = 0;
        double betAmount;
	    double userMoneyAmount = getMoneyAmount(acctNum);
	    cout << "You have $" << userMoneyAmount << " available to bet." << endl;
	    do {
	        betAmount = g.promptUserForAmountToBet();
	        if (betAmount <= userMoneyAmount) {
	            cout << "You are betting $" << betAmount << "." << endl;
	            cout<<"----------------------------------------------"<<endl;
                betTracker += betAmount;
	            validBetAmount = 1;
	        } else {
	            cout << "Can't bet more money than you have." << endl;
	        }
	    } while(!validBetAmount);
	    
        // Shuffle the card deck.
	    deck->shuffle();

        
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
        bool firstPrint = true;
        while (!userStands && g.calcValueOfHand(playersHand) < 21 && g.calcValueOfHand(dealersHand) < 21) {
            // ask if the user wants to hit or stand or split.
            string user;
            if(firstPrint == true){
              	cout<<"Do you want to hit, stand, or split? "<<endl;
              	cin>>user;
			}
			else{
				user = g.askHitOrStand(*deck,playersHand,dealersHand,p1);
			}
              
            
            // f. If the user decides to stand.
			if (user == "stand") {
				g.stand(*deck, playersHand, dealersHand, p1);
                userStands = true;
            // If user decides to hit.
           	} 
		   	else if (user == "hit") {
            	g.hit(*deck, playersHand);
            	firstPrint = false;
           	} 
        	
            // h. TODO: If the user decides to split, the dealer will draw two cards for the user. The user now has two hands.
			// Also, an additional bet of equal value to the original bet is placed on the second hand. Proceed the game as in step f and/or g.
        	else if (user == "split"){
        		//betAmount = betAmount * 2;
        		cout<<"----------------------------------------------"<<endl;
				cout << "You have decided to split your deck." << endl;
				cout<<"----------------------------------------------"<<endl;
           		//g.split(g, *deck, playersHand); 
           		//Seperate the hand into two vectors
           		vector<Card> hand1; 
           		vector<Card> hand2; 
				hand1.push_back(playersHand[0]);
				hand2.push_back(playersHand[1]);
				
				//we want to return the two decks so the player can play those 
				//cout << "The dealer has drawn two cards for you: " << selectAndShowTwo(mDeck, hand) << endl;
				g.split(*deck,hand1,hand2,p1);
				//the dealer gives each deck another card 
				cout<<"----------------------------------------------"<<endl;
				cout<<"The dealer will now deal a card for each hand"<<endl;
				cout<<"----------------------------------------------"<<endl;
				hand1.push_back(deck->dealCard());
				hand2.push_back(deck->dealCard());
           		if(g.calcValueOfHand(hand1) == 21){
           			playersHand = hand1;
           			g.split(*deck,hand1,hand2,p1);//displays the two hands
           			break;
				}
				if(g.calcValueOfHand(hand2) == 21){
					playersHand = hand2;
					g.split(*deck,hand1,hand2,p1);//displays the two hands
           			break;
				}
				g.split(*deck,hand1,hand2,p1);
           		string decision;
           		decision = g.askHitOrStand(*deck, playersHand, dealersHand, p1);
           		if (decision == "hit"){
                    
           			 
           			cout<<"What hand would you like to put it in? (1 or 2)? ";
           			int userHandChoice;
           			cin>>userHandChoice;

           			if(userHandChoice == 1){
           				g.hit(*deck, hand1);
           				playersHand = hand1;
           				
           				firstPrint = false; 
           				
					}
					else if(userHandChoice == 2){
						g.hit(*deck, hand2);
						playersHand = hand2;

						firstPrint = false;
					}
				}

				else if(decision == "stand"){
					cout<<"What hand would you like to stand? (1 or 2)? ";
           			int userHandChoice;
           			cin>>userHandChoice;
           			if(userHandChoice == 1){
           				playersHand = hand1;
           				g.stand(*deck, hand1, dealersHand, p1);
           				firstPrint = false;
           				userStands = true;
           				
					}
					else if(userHandChoice == 2){
						playersHand = hand2;
						g.stand(*deck, hand2, dealersHand, p1);
						
						firstPrint = false;
						userStands = true;
					
						
					}
					else{
						cout<<"error"<<endl;
						firstPrint = false;
					}
					
				} //end stand
				else{
					cout<<"error"<<endl;
					firstPrint = false; 
				}
           		
           		
		   } //end split
		
		
		}
        

        // If value of players hand is > 21, dealer wins.
        if(g.calcValueOfHand(playersHand) > 21) {
            dealerWins(g, playersHand, dealersHand, userMoneyAmount, betAmount, acctNum);
            
            askPlayAgain(gameEnd, betTracker, moneyWon);
            
        // If value of dealers hand is > 21, player wins.
        } else if(g.calcValueOfHand(dealersHand) > 21) {
            userWins(g, playersHand, dealersHand, userMoneyAmount, betAmount, acctNum, moneyWon);
            
            askPlayAgain(gameEnd, betTracker, moneyWon);
            
        // If value of the dealers hand and players hand are equal, there is a tie.
        } else if(g.calcValueOfHand(playersHand) == g.calcValueOfHand(dealersHand)){
            userTies(g, playersHand, dealersHand, userMoneyAmount, betAmount, acctNum, moneyWon);
            
            askPlayAgain(gameEnd, betTracker, moneyWon);
        
        // If the players hand is greater than the dealers hand and is <= 21, player wins.
        } else if (g.calcValueOfHand(playersHand) > g.calcValueOfHand(dealersHand) && g.calcValueOfHand(playersHand) <= 21)
        {
            userWins(g, playersHand, dealersHand, userMoneyAmount, betAmount, acctNum, moneyWon);
            
            askPlayAgain(gameEnd, betTracker, moneyWon);
            
        // Else dealer wins.
        } else {
            dealerWins(g, playersHand, dealersHand, userMoneyAmount, betAmount, acctNum);
            
            askPlayAgain(gameEnd, betTracker, moneyWon);
            
        }
    }
    return 0;
}


