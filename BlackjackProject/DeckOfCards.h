//
//  DeckOfCards.h
//  BlackjackProject
//
//  Created by Chelsea Marfil on 11/5/18.
//  Copyright © 2018 ChelseaMarfil. All rights reserved.
//

#ifndef DeckOfCards_h
#define DeckOfCards_h

#import "Card.h"

using namespace std;
#include <string>
#include <iostream>

class DeckOfCards {
public:
    DeckOfCards();
    void shuffle();
    Card dealCard();
    const int NUMBER_OF_CARDS = 52;
private:
    Card* deckOfCards;
    int currentCard;
    
};

#endif /* DeckOfCards_h */
