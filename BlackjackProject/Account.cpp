//
//  Account.cpp
//  BlackjackProject
//
//  Created by Chelsea Marfil on 11/5/18.
//  Copyright Â© 2018 ChelseaMarfil. All rights reserved.
//

#include <stdio.h>
#include "Account.h"
#include <iostream>
using namespace std;

//Constructor for a default account.
Account::Account() {
    
}

/**
Constructor for an account where the account number is assigned via parameter.
@param: int accountNum
*/
Account::Account(int accountNum) {
    mAccountNumber = accountNum;
}

/**
Constructor for an account where the account number and money inside is assigned via parameter.
@param: int accountNum
@param: double money
*/
Account::Account(int accountNum, double money) {
    mAccountNumber = accountNum;
    mMoney = money;
}

/**
Returns the account number of the account. 
@return: int mAccountNumber
*/
int Account::getAccountNumber() const {
    return mAccountNumber;
}

/**
Returns the money inside the account.
@return: double mMoney
*/
double Account::getMoney() const {
    return mMoney;
}

/**
Allows the parameter�s amount to become what money amount inside the account. Allows for change of the amount of money inside the account.
*/
void Account::setMoney(double amount) {
    mMoney  = amount;
}



