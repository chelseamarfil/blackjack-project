//
//  DeckOfCards.h
//  BlackjackProject
//
//  Created by Chelsea Marfil on 11/5/18.
//  Copyright © 2018 ChelseaMarfil. All rights reserved.
//

#ifndef DeckOfCards_h
#define DeckOfCards_h
#include <vector>

#include "Card.h"

using namespace std;
#include <string>
#include <iostream>

const int NUMBER_OF_CARDS = 52;

class DeckOfCards {
public:
    DeckOfCards();
    void shuffle();
    Card dealCard();
    void printDeck() const;
private:
    //deckOfCArds is a pointer to a Card type
    Card* deckOfCards;
    int currentCard;
    
};

#endif /* DeckOfCards_h */
