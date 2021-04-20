/*  ---------------------------------------------------------------------------
//  Column Header for the can't stop project                       column.hpp
//  Created by Chris Dowd and Eyad Esmail 
*/
#ifndef CANTSTOP_COLUMN_H
#define CANTSTOP_COLUMN_H
#include "tools.hpp"
#include "enums.hpp"
#include "player.hpp"

enum State {available, pending, captured };
const string myStates[] = {"Available","Pending", "Captured"};

class Column {
private:
    
    static constexpr int colLen[13]{0,0,3,5,7,9,11,13,11,9,7,5,3};
    int colNum;
    int mySize = colLen[colNum];
    State cState = available;
    int content[5]{0};
    
public:
    Column(int colNum): colNum (colNum){}
    ~Column() { cout <<"Column default constructor called\n"; }   //Destructor

    State getState(){return cState;}
    int* getContent(){return content;}
    void print( ostream& out) const;
    bool move();
    bool startTower(Player* p);
    void stop(Player* p);
    void bust();
};
inline ostream& operator << (ostream& out, Column& c){
    c.print(out);
    return out;
}

#endif //CANTSTOP_COLUMN_H