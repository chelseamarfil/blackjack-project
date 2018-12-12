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
    playerScore = 0;
    dealerScore = 0;
}

Game::Game(DeckOfCards& deck) {
    mDeck = deck;
    playerScore = 0;
    dealerScore = 0;
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

void Game :: hit(Game g, DeckOfCards &deck, vector<Card> &playersHand) {
    cout<<"You have drawn a: "<< g.selectAndShowOne(deck, playersHand).print()<<endl;
    cout << "The value of your hand is now: " << g.calcValueOfHand(playersHand) << endl;
}

string Game :: askHitStandOrSplit(DeckOfCards &mDeck, vector<Card> &hand, vector<Card> &dealerHand, Player p1)
{
    cout<<"Do you want to hit, stand, or split?"<<endl;
    string decision;
    cin >> decision;
    
    if (decision == "hit" || decision == "Hit")
    {
        //hit(mDeck, hand, dealerHand);
        return "hit";
    }
    
    else if(decision == "stand" || decision == "Stand")
    {
        //stand(mDeck, hand, dealerHand);
        return "stand";
    }
    
    else if (decision == "split" || decision == "Split")
    {
        //split(mDeck, hand, dealerHand, p1);
        return "split";
    }
    else {
        return "error";
        
    }
}
