//
//  Account.cpp
//  BlackjackProject
//
//  Created by Chelsea Marfil on 11/5/18.
//  Copyright © 2018 ChelseaMarfil. All rights reserved.
//

#include <stdio.h>
#include "Account.h"
#include <map>
#include <iostream>
using namespace std;

Account::Account() {
    
}

Account::Account(int accountNum) {
    mAccountNumber = accountNum;
}

Account::Account(int accountNum, double money) {
    mAccountNumber = accountNum;
    mMoney = money;
}

int Account::getAccountNumber() const {
    return mAccountNumber;
}
double Account::getMoney() const {
    return mMoney;
}

void Account::setMoney(double amount) {
    mMoney  = amount;
}




