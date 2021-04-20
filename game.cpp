/*  ----------------------------------------------------------------------------
//  Game Class file                          Game.cpp
//  Created by Chris Dowd and Eyad Esmail 
//  Created on 4/17/2021
*/
#include "game.hpp"

Game::Game(){
    ofstream gamefile;
    gamefile.open("boardtest.txt", ios_base::app);
    if ( !gamefile.is_open()){ cout << "can not open file" << endl;}
    gamefile << "\n--------------------------------" << endl;
    gamefile << "-        TEST STARTED          -" << endl;
    gamefile << "--------------------------------" << endl;
    diceSet->print(cout);
    b->print(gamefile);
    b->startTurn(p);
    gamefile << "==========================================================================" << endl;
    b->move(3);
    b->print(gamefile); 
    gamefile << "==========================================================================" << endl;
    b->move(3);
    b->print(gamefile); 
    gamefile << "==========================================================================" << endl;
    b -> move(4);
    b->print(gamefile); 
    gamefile << "==========================================================================" << endl;
    
    b->stop();
    b->print(gamefile); 
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
