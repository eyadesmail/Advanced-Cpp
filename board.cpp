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
    bool containsTower = backBone[column]->getContent()[0];
    cout << "contains tower: " << containsTower << endl;
    if (containsTower){ return backBone[column]->move();} 
        //if no tower, create tower
    if (towerCounter >= 3 ){
        return false;
    }
    backBone[column]->startTower(currentPlayer);
    towerColumn[towerCounter++]=column;
    return true;
}
//-----------------------------------------------------------------------------
void Board::stop(){
    for( int n = 0; n < 3 ; n++  ){ 
        if (towerColumn[n] > 1){
            backBone[towerColumn[n]]->stop(currentPlayer);
            currentPlayer -> wonColumn(towerColumn[n]);
        }
   }  
}
//-----------------------------------------------------------------------------
void Board::bust() {
    for( int n = 0; n < towerCounter ; n++  ){ 
         backBone[towerColumn[n]]->bust(); 
     }  
     towerCounter = 0;
}
//-----------------------------------------------------------------------------
void Board::print(ostream &out) const {
    for (int n = 2; n < 13 ; n++ ){
        backBone[n]->print(out);
    }
}