//
//  Card.cpp
//  BlackjackProject
//
//  Created by Chelsea Marfil on 11/5/18.
//  Copyright © 2018 ChelseaMarfil. All rights reserved.
//

#include "Card.h"

//default constructor
Card::Card() {
    
}
//Card constructor that takes in a face (string), and the suit (string) aka 10, hearts
Card::Card(string mFace, string mSuit) {
    face = mFace;
    suit = mSuit;
}
/**
* @return int - the integer value of the card 
*/
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

/*
* print out the face of suit aka Nine of hearts 
*@return string - a concatination of the face and suit 
*/
string Card::print() const{
	return(face + " of " + suit);
}
/*
*@return string - the face aka Nine 
*/
string Card::getFace() const {
	return  face; 
}
/*
*@return string - the suit - SPADES, DIAMONDS, HEARTS, CLUBS 
*/
string Card::getSuit() const{
	return suit;
}
