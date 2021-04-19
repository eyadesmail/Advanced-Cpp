/*  ----------------------------------------------------------------------------
//  Dice Header file                          Dice.hpp
//  Created by Chris Dowd and Eyad Esmail 
//  Created on 1/21/2021
*/

#ifndef CANTSTOP_DICE_H
#define CANTSTOP_DICE_H

#pragma once
#include "tools.hpp"


class Dice {
private:
    int numDice = 0;
    int* diceValue = NULL;
public:
    Dice(int n); //Constructor
    Dice();      //Default constructor
    ~Dice();     //Destructor
    const int* roll();
    void print( ostream& out) const;
};
inline ostream& operator << (ostream& out, Dice& d){
    d.print (out);
    return out;
}

#endif //CANTSTOP_DICE_H
