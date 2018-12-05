//
//  DeckOfCards.cpp
//  BlackjackProject
//
//  Created by Chelsea Marfil on 10/29/18.
//  Copyright © 2018 ChelseaMarfil. All rights reserved.
//

#include "DeckOfCards.h"


DeckOfCards::DeckOfCards() {
    
    string faces[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "King", "Queen"};
    
    string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    
    currentCard = 0;
    
    deckOfCards = new Card[NUMBER_OF_CARDS];
    
    for(int i = 0; i < NUMBER_OF_CARDS; i++) {
        deckOfCards[i] = Card(faces[i % 13], suits[i/13]);
    }
}

void DeckOfCards::shuffle() {
    
}

Card DeckOfCards:: dealCard() {
    if (currentCard > NUMBER_OF_CARDS) {
        shuffle();
    }
    if (currentCard < NUMBER_OF_CARDS) {
        return(deckOfCards[currentCard++]);
    }
    return deckOfCards[0];
}


