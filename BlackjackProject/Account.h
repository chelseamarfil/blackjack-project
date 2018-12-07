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

public:
    Account();
    Account(int accountNum);
    Account(int accountNum, double money);
    int getAccountNumber() const;
    double getMoney() const;
private:
    int mAccountNumber;
    double mMoney;
    
};
#endif /* Account_h */
