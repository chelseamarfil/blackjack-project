//
//  Player.h
//  BlackjackProject
//
//  Created by Chelsea Marfil on 11/5/18.
//  Copyright © 2018 ChelseaMarfil. All rights reserved.
//

#ifndef Player_h
#define Player_h

class Player {
public:
    Player();
    Player(int accountNumber);
    int getAccountNumber() const;
private:
    Account mAccountNumber;
}
#endif /* Player_h */
