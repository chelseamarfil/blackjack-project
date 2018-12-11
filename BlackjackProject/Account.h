//
//  Account.h
//  BlackjackProject
//
//  Created by Chelsea Marfil on 11/5/18.
//  Copyright Â© 2018 ChelseaMarfil. All rights reserved.
//

#ifndef Account_h
#define Account_h

// static int accountNumberCounter = 1000;

class Account {

public:
    Account();
    Account(int accountNum);
    Account(int accountNum, double money);
    int getAccountNumber() const;
    double getMoney() const;
    void setMoney(double amount);
private:
    int mAccountNumber;
    double mMoney;
    
};
#endif /* Account_h */
