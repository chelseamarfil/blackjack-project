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
	if(face == "Ace"){
		return 1;
	}
	
}

string Card::print() const {
    return (face + " of " + suit);
}
