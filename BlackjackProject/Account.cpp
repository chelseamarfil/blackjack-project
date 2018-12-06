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
    accountMap = map<int, double>();
}

/**
 Adds a new account to the map. New account numbers will be incremented by 1, and will start off with $0.
 */
void Account::addNewAccount(int lastAccountNumber) {
    lastAccountNumber++;
    accountMap[lastAccountNumber] = 0;
}

/**
 Finds the amount of money associated with an account number.
 @param number the account number being searched
 @return the amount of money in the account
 */
double Account::findMoneyAmount(int accountNumber) {
    map<string, int>::iterator p = accountMap.find(accountNumber);
    if (p == accountMap.end()) {
        return 0;
    } else {
        return p->second;
    }
}

/**
 Updates the money in an account.
 @param account number of the player
 @param amount to add to the player's money - param will be negative if user loses money.
 */
void Account::updateAccount(int accountNumber, double amountToAdd) {
    map<string, int>::iterator p = accountMap.find(accountNumber);
    if (p == accountMap.end()) {
        cout << "Account doesn't exist." << endl;
    } else {
        accountMap[accountNumber] = findMoneyAmount(accountNumber) + amountToAdd;
    }
}


