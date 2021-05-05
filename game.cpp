/*  ----------------------------------------------------------------------------
//  Game Class file                          Game.cpp
//  Created by Chris Dowd and Eyad Esmail 
//  Created on 4/17/2021
*/
#include "game.hpp"
bool playing = true;
Game::Game(){}
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
    bool firstmove  = b-> move(firstpair);
    bool secondmove = b-> move(secondpair);
    //cout << "Firstmove: " << firstmove << endl;
    //cout << "second move: " << secondmove << endl;
    b->print(cout);
    // if both moves fail, player goes bust, turn ends. 
    if (!firstmove && !secondmove){
        b->bust();
        playing = false;
        cout << "============ WENT BUST. ============" << endl;
        b->print(cout);
    }  
}
//----------------------------------------------------------------------------
void Game::stop(Player* pp){
    b->stop();
    b->print(cout);
    //playing = false;
    //bye();
}
//-----------------------------------------------------------------------------
void Game::resign(Player* pp){
    cout << " Player Resigned" << endl;
    //playing = false;
    //bye();
}
//-----------------------------------------------------------------------------
int Game::choosepair(){
    string charpairs;
    bool valid = true;
    int onepairtotal = 0;
    do{
        cout << "choose a pair of dice by writing in the pairing letters; eg: ab" << endl;
        cin >> charpairs;
        //cout << "enterloop"<< endl;
        for (int n = 0;n <=1;n++ ){
            int index = int(charpairs[n]);
            if ( index < 'a' || index > 'd'){
                cout << "Invalid input. Please try again." << endl;
                onepairtotal = 0;
                valid = false;
                break;
            }else {
                valid = true;
                //cout << "dice goes controll " << endl;
                index = index - 96;
                onepairtotal += diceSet->getValue(index);
            }
        }
    }while(!valid);
    return onepairtotal;
}
//-----------------------------------------------------------------------------
void Game::menu(Player* pp){
    bool valid = true; // validate input 
    do{
        while(playing){
            char action;
            cout << "Choose an action: " << endl;
            cout << "r: roll \ns: stop \nx: resign" << endl;
            cin >> action;
            switch(action){
                case 'r': roll()    ;break;
                case 's': stop(pp)  ;playing = false;break;
                case 'x': resign(pp);playing = false;break;
                default:
                    cout << "Invalid input. Please try again. " << endl;
                    valid = false;
            }
        }
    }while (!valid); 
    cout << "Game ended" << endl;   
}
//-----------------------------------------------------------------------------
Player* Game::getNewPlayer(){
    string pname;
    char pcolor;
    colorEnum pcolorval;
    bool valid = true;
    cout << "Enter Player Name: " << endl;
    cin >> pname;
    do{
        valid = true;
        cout << "Choose a color: " << endl;
        cout << "o: Orange" << "\n" << "y: Yellow" << "\n" << "g: Green" << "\n" << "b: Blue" << endl;
        cin >> pcolor;
        switch(pcolor){
            case 'o': pcolorval = orange; break;
            case 'y': pcolorval = yellow; break;
            case 'g': pcolorval = green;  break;
            case 'b': pcolorval = blue;   break;
            break;
            default : 
                pcolorval = white;  
                cout << "Invalid input. Please try again. " << endl;
                valid = false;
        }
    }while(!valid);
    return new Player(pname,pcolorval);
}
