//
//  Player.h
//  BlackjackProject
//
//  Created by Chelsea Marfil on 11/5/18.
//  Copyright © 2018 ChelseaMarfil. All rights reserved.
//

#ifndef Player_h
#define Player_h
#include "Account.h"
#include <vector>

using namespace std;

class Player {
public:
    Player();
    Player(Account account);
private:
    Account mAccount;
    vector<Card> playersHand;
};
#endif /* Player_h */
