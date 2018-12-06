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

Player::Player(int accountNumber) {
    mAccountNumber = accountNumber;
}

int Player::getAccountNumber() {
    return mAccountNumber;
}

