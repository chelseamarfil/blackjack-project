//
//  Card.cpp
//  BlackjackProject
//
//  Created by Chelsea Marfil on 11/5/18.
//  Copyright © 2018 ChelseaMarfil. All rights reserved.
//

#include "Card.h"

Card::Card() {
    
}

Card::Card(string mFace, string mSuit) {
    face = mFace;
    suit = mSuit;
}

int Card::getFaceValue() {
    if (face == "Ace") {
        return 1;
    } else if (face == "Two") {
        return 2;
    } else if (face == "Three") {
        return 3;
    } else if (face == "Four") {
        return 4;
    } else if (face == "Five") {
        return 5;
    } else if (face == "Six") {
        return 6;
    } else if (face == "Seven") {
        return 7;
    } else if (face == "Eight") {
        return 8;
    } else if (face == "Nine") {
        return 9;
    } else if (face == "Ten") {
        return 10;
    } else if (face == "Jack") {
        return 10;
    } else if (face == "King") {
        return 10;
    } else if (face == "Queen") {
        return 10;
    } else {
        return 0;
    }
}

string Card::print() const {
    return (face + " of " + suit);
}
