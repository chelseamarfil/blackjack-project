//
//  Player.cpp
//  BlackjackProject
//
//  Created by Chelsea Marfil on 11/5/18.
//  Copyright © 2018 ChelseaMarfil. All rights reserved.
//

#include <stdio.h>
#include "Player.h"
using namespace std;

Player::Player() {
    
}

Player::Player(Account account) 
{
    mAccount = account;
    playersHand = vector <Card>();
    dealersHand = vector <Card>();
}

vector <Card> Player::getHand(){
	return playersHand;
} 

//For creating a second hand.
//This will replace the previous hand that they originally had.
void Player :: setHand(vector <Card> newHand)
{
	this -> playersH and = newHand;
}

vector <Card> Player::getDealersHand(){
	return dealersHand;
}

Account Player::getAccount(){
	return mAccount;
}



