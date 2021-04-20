/*  ---------------------------------------------------------------------------
//  Column class for the can't stop project                       column.cpp
//  Created by Chris Dowd and Eyad Esmail 
*/


#include "column.hpp"
//startTower function to place a new tower
bool Column::startTower(Player* p){
    colorEnum pcolor = p -> getColor();
    if(cState == captured){ 
        return false;
    }else if (content[white] == 0 && content[pcolor]==0){
        content[white] = 1;
        return true;
    }else{
        content[white] = content[pcolor] + 1;
        if (content[white] == mySize){
            cState = pending;
        }
        return true;
    }
}
//-----------------------------------------------------------------------------
// move function to advance the tower one square in the column
bool Column::move(){
    if (cState == captured){
        return false;
    }
    if (content[white] == 0){
        cout << "No Tower to move. Start Tower First."<< endl;
        return false;
    }
    ++content[white];
    if (content[white] == mySize){
        cState = pending;
        return true;
    }else {return true;}
}
//-----------------------------------------------------------------------------
// stop function to end a turn
void Column::stop(Player* p){
    colorEnum pcol = p-> getColor();
    content[pcol] = content[white];
    content[white] = 0;
    if (cState == pending){
        cState = captured;
        p -> wonColumn(colNum);
    }
}
//-----------------------------------------------------------------------------
void Column::bust(){
    content[white] = 0;
};
//-----------------------------------------------------------------------------
// ostream function 
void Column::print(ostream& out) const {
    string mycontent;
    for(int j = 1;j<= mySize;j++ ){
        string outarr[5]{"-"};
        if(content[white]  == j) {outarr[white]  = "T";}else{outarr[white]  = "-";};
        if(content[orange] == j) {outarr[orange] = "O";}else{outarr[orange] = "-";};
        if(content[yellow] == j) {outarr[yellow] = "Y";}else{outarr[yellow] = "-";};
        if(content[green]  == j) {outarr[green]  = "G";}else{outarr[green]  = "-";};
        if(content[blue]   == j) {outarr[blue]   = "B";}else{outarr[blue]   = "-";};
        string squarecontent;
        for(int i=0;i<5;i++){
            squarecontent.append(outarr[i]);
        }
        mycontent.append(" | ");
        mycontent.append(squarecontent);
    }
    out << "Column:" << colNum << ", State:" << myStates[cState] << ", Squares:" << mycontent << endl;
}
