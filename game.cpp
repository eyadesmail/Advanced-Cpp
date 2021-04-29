/*  ----------------------------------------------------------------------------
//  Game Class file                          Game.cpp
//  Created by Chris Dowd and Eyad Esmail 
//  Created on 4/17/2021
*/
#include "game.hpp"
bool playing = true;
Game::Game(){
    // ofstream gamefile;
    // gamefile.open("boardtest.txt", ios_base::app);
    // if ( !gamefile.is_open()){ cout << "can not open file" << endl;}
    // gamefile << "\n--------------------------------" << endl;
    // gamefile << "-        TEST STARTED          -" << endl;
    // gamefile << "--------------------------------" << endl;
    // diceSet->print(cout);
    // b->print(gamefile);
    // b->startTurn(p);
    // gamefile << "==============================================" << endl;
    // b->move(3);
    // b->print(gamefile); 
    // gamefile << "==============================================" << endl;
    // b->move(3);
    // b->print(gamefile); 
    // gamefile << "==============================================" << endl;
    // b -> move(4);
    // b->print(gamefile); 
    // gamefile << "===============================================" << endl;
    	
    // b->stop();
    // b->print(gamefile); 
    
}
//-----------------------------------------------------------------------------
void Game::oneTurn(Player* pp){
    b -> startTurn(pp);
    b -> print(cout);
    menu(pp);
}
//-----------------------------------------------------------------------------
void Game::roll(){
    diceSet->roll();
    diceSet->print(cout);
    int totalpairs = diceSet->getValue(1)+diceSet->getValue(2)+diceSet->getValue(3)+diceSet->getValue(4);
    int firstpair = choosepair();
    int secondpair =totalpairs - firstpair; 
    b-> move(firstpair);
    b->print(cout);
    cout << "====================================" << endl;
    b-> move(secondpair);
    b->print(cout);
}
//----------------------------------------------------------------------------
void Game::stop(Player* pp){
    b->stop();
    b->print(cout);
}
//-----------------------------------------------------------------------------
void Game::resign(Player* pp){

}
//-----------------------------------------------------------------------------
int Game::choosepair(){
    string charpairs;
    cout << "choose a pair of dice by writing in the pairing letters; eg: ab" << endl;
    cin >> charpairs;
    int onepairtotal = 0;
    cout << "enterloop"<< endl;
    for (int n = 0;n <=1;n++ ){
        int index = int(charpairs[n]);
        index = index - 96;
        onepairtotal += diceSet->getValue(index);
    }
    
    return onepairtotal;
}
//-----------------------------------------------------------------------------
void Game::menu(Player* pp){
    bool playing = true;
    while(playing){
        char action;
        cout << "Choose an action: " << endl;
        cout << "r: roll \ns: stop \nx: resign" << endl;
        cin >> action;
        
        switch(action){
            case 'r': roll()    ;break;
            case 's': stop(pp)  ;playing = false;break;
            case 'x': resign(pp);break;
            break;
        }
    } 
    cout << "Game ended" << endl;   
}


//-----------------------------------------------------------------------------
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
