//
//  DeckOfCards.cpp
//  BlackjackProject
//
//  Created by Chelsea Marfil on 10/29/18.
//  Copyright © 2018 ChelseaMarfil. All rights reserved.
//

#include "DeckOfCards.h"
#include <ctime> //for time
#include <cstdlib> //for srand and rand
#include <iomanip>

DeckOfCards::DeckOfCards() {
    
    string faces[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "King", "Queen"};
    
    string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    
    currentCard = 0;
    
    deckOfCards = new Card[NUMBER_OF_CARDS];
    
    for(int i = 0; i < NUMBER_OF_CARDS; i++) {
        deckOfCards[i] = Card(faces[i % 13], suits[i/13]);
    }
}

//void DeckOfCards::shuffle() {
//    currentCard = 0;
//    for (int first = 0; first < NUMBER_OF_CARDS; first++) {
//        int second = (rand() +time(0)) % NUMBER_OF_CARDS;
//        Card temp = deckOfCards[first];
//        deckOfCards[first] = deckOfCards[second];
//        deckOfCards[second] = temp;
//    }
//}

/*
 Shuffles a deck of cards using srand
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
void DeckOfCards::printDeck() const{
    cout << left;
    for (int i = 0; i < NUMBER_OF_CARDS; i++) {
        cout << setw(19) << deckOfCards[i].print();
        if ((i+1) % 4 == 0)
            cout << endl;
    }
}
         
         
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
