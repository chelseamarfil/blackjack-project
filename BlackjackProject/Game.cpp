#include "Game.h"
#include <iostream>
#include<vector>

using namespace std;

Game::Game() {
    mDeck = DeckOfCards();
}

Game::Game(DeckOfCards& deck, Player player, Player dealer) {
    mDeck = deck;
    mPlayer = player;
    dealerScore = 0;
    playerScore = 0;
}

Game::Game(DeckOfCards& deck) {
    mDeck = deck;
    playerScore = 0;
}

void Game :: setPlayer(Player player) {
    mPlayer = player;
    
}
void Game::setDealer(Player dealer){
	mDealer = dealer;
} 
Player Game::getPlayer() const {
    return mPlayer;
}

Player Game::getDealer() const{
	return mDealer;
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

/** Randomly select and show the user two cards.
 * Only happens once at the beginning of the game
 @return a vector of the two cards
 */
vector<Card> Game::selectAndShowTwo(DeckOfCards &mDeck, vector<Card> &hand) {
	//Deal two from the array
	Card firstCard = mDeck.dealCard();
	Card secondCard = mDeck.dealCard(); 
	
	hand.push_back(firstCard);
	hand.push_back(secondCard);
	
	return hand;
    
}

/** Randomly select and show the user a card.
 @return their card
 */
Card Game::selectAndShowOne(DeckOfCards &mDeck, vector<Card> &hand) {
    //Deal two from the array
    Card firstCard = mDeck.dealCard();
    
    //&hand should update the hand because we pass a refrence
    hand.push_back(firstCard);
    
    return firstCard;
    
}

void Game::showHand(vector<Card> &hand){
	for(int i=0; i < hand.size(); i++){
		cout<<hand[i].print()<<" | ";
		
	}
	cout<<endl;
}
/**
Calculates the value of the cards in the player's hand.
@return: int - score
@parameter: vector<Card> &hand, the hand of the player.
**/
int Game::calcValueOfHand(vector<Card> &hand){
	playerScore = 0;
	for(int i=0; i < hand.size(); i++){
		//if the card is an Ace...
		if(hand[i].getFaceValue() == 1){
			//And if the score is less than 10
			if(playerScore <= 10){
				
				//make the ace worth 11 and add it to score
				playerScore += 11;
				//cout<<"playerscore1: "<<playerScore<<endl;
			}
			else{
				
				
				playerScore += 1;
				//cout<<"playerscore2: "<<playerScore<<endl;
			}
		}
		else{
			
			playerScore += hand[i].getFaceValue();
			//cout<<"playerscore3: "<<playerScore<<endl;
			
		} 
		
	}
	return playerScore;
	
}
///*
// Updates the money in an account.
// @param accountNumber of the player
// @param amountToAdd to the player's money - param will be negative if user loses money.
// */
//void Game::updateAccount(int accountNumber, double amountToAdd) {
//    for(int i = 0; i < accountsVector.size(); i++) {
//        if (accountsVector[i].getAccountNumber() == accountNumber) {
//            accountsVector[i].setMoney(amountToAdd);
//        }
//    }
////    map<int, double>::iterator p = mAccountMap.find(accountNumber);
////    if (p == mAccountMap.end()) {
////        cout << "Account doesn't exist." << endl;
////    } else {
////        mAccountMap[accountNumber] = getMoneyAmount(accountNumber) + amountToAdd;
////    }
//}
///**
// Adds a new account to the map. New account numbers will be incremented by 1, and will start off with $0.
// */
//void Game::addNewAccount() {
//    accountNumberCounter++;
//    Account a(accountNumberCounter, 0);
//    accountsVector.push_back(a);
//    //mAccountMap[accountNumberCounter] = 0;
//}
///**
// Adds a new account to the map. New account numbers will be incremented by 1, and will start off with a given amount of money.
// */
//void Game::addNewAccount(double money) {
//    accountNumberCounter++;
//    Account a(accountNumberCounter, money);
//    accountsVector.push_back(a);
//    //mAccountMap[accountNumberCounter] = money;
//}

/**
If the user decides to stand, decide how the program will
select a card for the dealer
**/
void Game :: stand (DeckOfCards &mDeck, vector<Card> &hand, vector<Card> &dealerHand )
{
	if(dealerScore >= 17 ){
		
	}
	else if (dealerScore < 17){
		selectAndShowOne(mDeck, dealerHand);
	}

}

/**
g. If the user decides to hit and the total value is less than 21, 
the program will select a card for the user. If the total value of the user’s 
cards is more than 21 during this process, the user will lose; otherwise, decide 
how the program will select a card for the dealer.
**/
Game :: hit(DeckOfCards &mDeck, vector<Card> &hand, vector<Card> &dealerHand)
{
	cout<<"Your new card is: "<< selectAndShowOne(mDeck, hand).print()<<endl;

	//if the dealer's score 
	if(dealerScore >= 17 ){
		stand(mDeck, hand, dealerHand);
	}
	else if(dealerScore < 17){
		selectAndShowOne(mDeck, dealerHand);
	}
	
}

/**
h. If the user decides to split, the dealer will draw two cards for the user. 
The user now has two hands. Also, an additional bet of equal value to the original bet is 
placed on the second hand. Proceed the game as in step f and/or g.
**/
void Game :: split(DeckOfCards &mDeck, vector<Card> &hand, vector<Card> &dealerHand, Player p1)
{
	vector<Card> hand2 = selectAndShowTwo(mDeck,hand);
	hand.erase(hand.begin(), hand.begin() +1);
	p1.setHand(hand2);
	//cout << "The dealer has drawn two cards for you: " << selectAndShowTwo(mDeck, hand) << endl;
	cout << "The dealer has drawn two cards for you." << endl;
	cout << "This will now be your second hand. " << endl;
	cout << "Your cards are: " << endl;
		
	for(int i = 0; i < hand2.size(); i++)
	{
		cout << hand2[i].print() << endl;
	}
	

}
/**
Asks the user if they want to Hit, Stand, or Split.
**/
void Game :: askHitStandOrSplit(DeckOfCards &mDeck, vector<Card> &hand, vector<Card> &dealerHand, Player p1)
{
	cout<<"Do you want to hit, stand, or split?"<<endl;
	string decision;
	cin >> decision;
	
	if (decision == "hit" || decision == "Hit")
	{
		hit(mDeck, hand, dealerHand);
	}
	
	else if(decision == "stand" || decision == "Stand")
	{
		stand(mDeck, hand, dealerHand);
	}
	
	else if (decision == "split" || decision == "Split")
	{
		split(mDeck, hand, dealerHand, p1);
	}
}
/**
 Gets the amount of money associated with an account number.
 @param accountNumber the account number being searched
 @return the amount of money in the account
 */
//double Game::getMoneyAmount(int accountNumber) {
//    for(int i = 0; i < accountsVector.size(); i++) {
//        if (accountsVector[i].getAccountNumber() == accountNumber) {
//            return accountsVector[i].getMoney();
//        }
//    }
//
//    return -1;
////    map<int, double>::iterator p = mAccountMap.find(accountNumber);
////    if (p == mAccountMap.end()) {
////        return 0;
////    } else {
////        return p->second;
////    }
//
////    if (accountExists(accountNumber)) {
////        map<int, double>::iterator p = mAccountMap.find(accountNumber);
////        return p->second;
////    } else {
////        return -1;
////    }
//}
/**
 */
//bool Game::accountExists(int accountNumber) {
//    for(int i = 0; i < accountsVector.size(); i++) {
//        if (accountsVector[i].getAccountNumber() == accountNumber) {
//            return 1;
//        }
//    }
//    return 0;
////    map<int, double>::iterator p = mAccountMap.find(accountNumber);
////    if (p == mAccountMap.end()) {
////        return 0;
////    } else {
////        return 1;
////    }
//}
//void Game::printMap() {
//    for (map<int, double>::iterator pos = mAccountMap.begin();
//         pos != mAccountMap.end(); pos++)
//    {
//        cout << pos->first << ": " << pos->second << "\n";
//    }
//}
//void Game::printAccounts() {
//    for(int i = 0; i < accountsVector.size(); i++) {
//        cout << accountsVector[i].getAccountNumber() << ": " << accountsVector[i].getMoney() << endl;
//    }
//}
