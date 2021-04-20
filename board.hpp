/*  ----------------------------------------------------------------------------
//  Board Header file                          board.hpp
//  Created by Chris Dowd and Eyad Esmail 
//  Created on 4/19/2021
*/
#ifndef CANTSTOP_BOARD_HPP
#define CANTSTOP_BOARD_HPP
#include "enums.hpp"
#include "column.hpp"
#include "player.hpp"

class Board{
private:
    int towerCounter = 0;
    int towerColumn[2];
    Column* backBone[13];
    Player* currentPlayer;
public:
    Board();
    ~Board();
    void startTurn( Player* );
    bool move ( int column );
    void stop();
    void bust();
    void print( ostream& out) const;
};
inline ostream& operator << (ostream& out, Board& b){
    b.print(out);
    return out;
}
#endif //CANTSTOP_BOARD_HPP