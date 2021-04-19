/*  ----------------------------------------------------------------------------
//  Player header file                          player.hpp
//  Created by Chris Dowd and Eyad Esmail 
//  Created on 2/4/2021
*/

#ifndef CANTSTOP_PLAYER_HPP
#define CANTSTOP_PLAYER_HPP
#include "tools.hpp"
#include "enums.hpp"

class Player {
private:
    string name;
    colorEnum color;
    int score = 0;
    int sboard[3]{0};
public:
    Player(string name, colorEnum color ): name (name), color (color) {}
    ~Player() {cout <<"Player default constructor called\n"; }   //Destructor

    colorEnum getColor(){return color;}
    int getScore() {return score;}
    bool wonColumn(int colNum);
    void print( ostream& out) const;
};
inline ostream& operator << (ostream& out, Player& p){
    p.print (out);
    return out;
}
#endif //CANTSTOP_PLAYER_HPP
