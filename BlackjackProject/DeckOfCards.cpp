//
//  DeckOfCards.cpp
//  BlackjackProject
//
//  Created by Chelsea Marfil on 10/29/18.
//  Copyright Ã¯Â¿Â½ 2018 ChelseaMarfil. All rights reserved.
//

#include "DeckOfCards.h"
#include <ctime> //for time
#include <cstdlib> //for srand and rand
#include <iomanip>

/**
Constructor for DeckOfCards. Contains an array of faces and suits with their string equivalents. The currentCard represents the current 
position within the deck of cards at the moment. (= 0). 
“Assembles” the deck of cards by pairing a face with a suit with a for loop.
*/
DeckOfCards::DeckOfCards() {
    
    string faces[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "King", "Queen"};
    
    string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    
    currentCard = 0;
    
    deckOfCards = new Card[NUMBER_OF_CARDS];
    
    for(int i = 0; i < NUMBER_OF_CARDS; i++) {
        deckOfCards[i] = Card(faces[i % 13], suits[i/13]);
    }
}


/*
 Shuffles a deck of cards using srand.
 With srand, we can generate random values to mix around the deck of cards 
 within each other by swapping positions within the deck. 
 */
void DeckOfCards::shuffle() {
    //srand for randomly generated time
    srand(time(0));
    //want to loop through the entire deck and randomize each card
    for(int i = 0; i < NUMBER_OF_CARDS; i++){
        int random = rand() % 52; //will give us a position from from 0 to 52
        //Swap method using a temporary variable
        Card temp = deckOfCards[i]; //set temp to a card in deck
        deckOfCards[i] = deckOfCards[random]; //now set that card to a random card in the deck
        deckOfCards[random] = temp; //finsh the swap by swapping the random card
    }

}
/*
Prints out the formatted deck of cards. 
*/
void DeckOfCards::printDeck() const{
    cout << left;
    for (int i = 0; i < NUMBER_OF_CARDS; i++) {
        cout << setw(19) << deckOfCards[i].print();
        if ((i+1) % 4 == 0)
            cout << endl;
    }
}
         
/*
Checks the current position of the deck of cards, through currentCard. If the position is 
greater than the amount of cards in the deck, then no card will be dealt. If the position is less
than the amount of cards in the deck, the card after the currentCard will be dealt. 
*/ 
Card DeckOfCards:: dealCard() {
	//if currentCard - index that moves along the deck of cards 
    if (currentCard > NUMBER_OF_CARDS) {
        //shuffle();
    	cout<<"No more cards in deck."<<endl;
    }
    if (currentCard < NUMBER_OF_CARDS) {
    	//update the deck of cards by moving index to next card
    	return(deckOfCards[currentCard++]);
    }
    return deckOfCards[0];
}
