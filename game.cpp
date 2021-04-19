/*  ----------------------------------------------------------------------------
//  Game Class file                          Game.cpp
//  Created by Chris Dowd and Eyad Esmail 
//  Created on 4/17/2021
*/
#include "game.hpp"

Game::Game(){
    ofstream gamefile;
    gamefile.open("gametest.txt", ios_base::app);
    if ( !gamefile.is_open()){ cout << "can not open file" << endl;}
    gamefile << "\n--------------------------------" << endl;
    gamefile << "-        TEST STARTED          -" << endl;
    gamefile << "--------------------------------" << endl;
    diceSet->print(gamefile);
    p1->print(gamefile);
    p2->print(gamefile);
    c1->print(gamefile);
    c2->print(gamefile);
    gamefile << "------------place tower in col 7 and print---------"<< endl;
    c2->startTower(p1);
    c2->print(gamefile);
    gamefile << "------------Place a tower in column 2 and call move() three times---------"<< endl;
    gamefile << "initial column: "<< endl;
    c1 -> print(gamefile);
    c1-> startTower(p1);
    c1->move();
    c1->move();
    c1->move();
    gamefile << "final column: "<< endl;
    c1->print(gamefile);
}

Player* Game::getNewPlayer(){
    string pname;
    char pcolor;
    colorEnum pcolorval;
    cout << "Enter Player Name: " << endl;
    cin >> pname;
    cout << "Choose a color: " << endl;
    cout << "o: Orange" << "\n" << "y: Yellow" << "\n" << "g: Green" << "\n" << "b: Blue" << endl;
    cin >> pcolor;
    
    switch(pcolor){
        case 'o': pcolorval = orange; break;
        case 'y': pcolorval = yellow; break;
        case 'g': pcolorval = green;  break;
        case 'b': pcolorval = blue;   break;
        break;
        default : pcolorval = white;
    }
    return new Player(pname,pcolorval);
}
