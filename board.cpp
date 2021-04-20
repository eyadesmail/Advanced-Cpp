/*  ----------------------------------------------------------------------------
//  Board Class file                          board.cpp
//  Created by Chris Dowd and Eyad Esmail 
//  Created on 4/19/2021
*/

#include "board.hpp"
Board::Board(){
    for( int j = 0; j < 13; j++){
        if( j < 2){ backBone[j] = NULL; } else
        backBone[j] = new Column(j);
    }
}
//-----------------------------------------------------------------------------
void Board::startTurn( Player* p) {
    currentPlayer = p;
    towerCounter = 0;
    for( int n = 0; n < 3 ; n++  ){ 
        towerColumn[n] = 0; 
    }  //set all tower columns to 0
}
//-----------------------------------------------------------------------------
bool Board::move( int column ){
    State cstate = backBone[column]-> getState();
    bool containsTower = backBone[column]->getContent()[0];
    if (cstate != available || (towerCounter >= 3 && !containsTower)){
        return false;
    }else {
        //if no tower, create tower
        if (!containsTower){
            backBone[column]->startTower(currentPlayer);
            towerColumn[towerCounter]=column;
            towerCounter++;
        }else{ //if there is tower, move tower
            backBone[column]->move();
        }
        return true;
    }
}
//-----------------------------------------------------------------------------
void Board::stop(){
    for( int n = 0; n < 3 ; n++  ){ 
        if (towerColumn[n] > 2){
            backBone[towerColumn[n]]->stop(currentPlayer);
        }
         
   }  
    
}
//-----------------------------------------------------------------------------
void Board::bust() {
    for( int n = 0; n < 3 ; n++  ){ 
        backBone[towerColumn[n]]->bust(); 
    }  
}
//-----------------------------------------------------------------------------
void Board::print(ostream &out) const {
    for (int n = 2; n < 13 ; n++ ){
        backBone[n]->print(out);
    }
}