//
//  Account.h
//  BlackjackProject
//
//  Created by Chelsea Marfil on 11/5/18.
//  Copyright © 2018 ChelseaMarfil. All rights reserved.
//

#ifndef Account_h
#define Account_h

class Account {
static int lastAccountNum;

public:
    Account();
    addNewAccount(int lastAccountNum);
    findMoneyAmount(int accountNumber);
    updateAccount(int accountNumber, double amountToAdd);
    //printAll(); // might not be necessary
private:
    map<int accountNumber, double money> accountMap;
}
#endif /* Account_h */
