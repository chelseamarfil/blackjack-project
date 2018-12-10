//
//  Player.h
//  BlackjackProject
//
//  Created by Chelsea Marfil on 11/5/18.
//  Copyright Â© 2018 ChelseaMarfil. All rights reserved.
//

#ifndef Player_h
#define Player_h
#include "Account.h"
#include "Card.h"
#include <vector>


using namespace std;

class Player {
public:
    Player();
    Player(Account account);
    vector<Card> getHand();
    void setHand(vector <Card> newHand);
    vector<Card> getDeale rsHand();
    Account getAccount();
private:
    Account mAccount;
    vector<Card> playersHand;
    vector<Card> dealersHand;
};
#endif /* Player_h */
