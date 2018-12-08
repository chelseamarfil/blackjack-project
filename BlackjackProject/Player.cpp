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

Player::Player(Account account) {
    mAccount = account;
    playersHand = vector <Card>();
    dealersHand = vector <Card>();
}

vector <Card> Player::getHand(){
	return playersHand;
} 

vector <Card> Player::getDealersHand(){
	return dealersHand;
}

Account Player::getAccount(){
	return mAccount;
}



