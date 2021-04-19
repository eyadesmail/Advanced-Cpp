/*  ----------------------------------------------------------------------------
//  Dice Class file                          Dice.cpp
//  Created by Chris Dowd and Eyad Esmail 
//  Created on 1/21/2021
*/

#include "dice.hpp"

Dice::Dice() {}

//Constructor to create random numbers and call Dice::roll()
Dice::Dice( int n ) {
    cout <<n <<" Dice created!\n";
    this->numDice = n;
    diceValue = new int[ n ]; //pseudo-random values
    srand(time( NULL )); //create seed for rand()
    roll(); //to generate dice values
}
//Destructor of Dice and free allocated memory from Dice
Dice::~Dice() {
    cout <<"Dice destructor called\n";
    delete [] diceValue;
}
//Roll dice generating pseudo-random values for each roll
const int* Dice::roll() {
    cout <<"Dice::roll() called\n";
    for( int j = 1; j <= numDice; j++ ) {
        diceValue[ j ] = rand() % 6 + 1; 
    }
    return diceValue;
}
// ostream function 
void Dice::print(ostream& out) const {
    for (int j=1; j <= numDice; j++ ){ // printing dice output 
        out <<"Dice " <<j <<" = " <<diceValue[j] <<endl;
    }
}



