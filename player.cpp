/*  ----------------------------------------------------------------------------
//  Player Class file                          player.cpp
//  Created by Chris Dowd and Eyad Esmail 
//  Created on 2/4/2021
*/

#include "player.hpp"

bool Player::wonColumn(int colNum){
    //cout <<"Player::wonColumn called\n";
    sboard[score++] = colNum; // increment score and assign col number to sboard
    // testing if function works
    //cout<< "column won: " << sboard[score]; 
    return (score == 3); // check winning 
}
//-----------------------------------------------------------------------------
// ostream function 
void Player::print(ostream& out) const {
    //cout <<"Player::print called\n";
    out << "Name"<< "    " << "Color"       << "     " << "Score" << endl;
    out << name  << "    " << colors[color] << "     " <<  score  << endl;
}
