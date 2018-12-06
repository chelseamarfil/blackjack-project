//
//  Card.h
//  BlackjackProject
//
//  Created by Chelsea Marfil on 11/5/18.
//  Copyright © 2018 ChelseaMarfil. All rights reserved.
//

#ifndef Card_h
#define Card_h
#import <string>

using namespace std;

class Card {
public:
    Card();
    Card(string face, string suit);
    string print() const;
    int getFaceValue();
    string getFace() const;
    string getSuit() const;
    
private:
    string face;
    string suit;
};

#endif /* Card_h */
