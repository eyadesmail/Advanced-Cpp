/*  ---------------------------------------------------------------------------
//  Main program for the can't stop project                         main.cpp
//  Created by Chris Dowd and Eyad Esmail 
*/

#include <iostream>
#include "dice.hpp"
#include "tools.hpp"
#include "enums.hpp"
#include "player.hpp"
#include "column.hpp"
#include "game.hpp"
#include "clist.hpp"
#define NUM_DICE 4


void unitDice(){    // dice testing function 
    ofstream dicefile;
    dicefile.open("dicetest.txt", ios_base::app); // file output with append mode
    Dice d(NUM_DICE);
    if ( dicefile.is_open()){   // checking if file is opened 
        dicefile << "-------------------------------------------" << endl;
        dicefile << "Dice Created: " << NUM_DICE << endl; 
        d.print(dicefile);} // output to file 
        else{cout << "can not open file"<< endl; }
    d.print(cout); // output to console 
    dicefile.close();}
//-----------------------------------------------------------------------------

void unitPlayer(){
    ofstream playerfile;
    playerfile.open("playertest.txt", ios_base::app);
    if ( !playerfile.is_open()){ cout << "can not open file" << endl;}
    cout << "Enter player name: " << endl;
    string pname;
    char colorchoice;
    cin >> pname;
    cout << "Choose a color: " << endl;
    cout << "o: Orange" << "\n" << "y: Yellow" << "\n" << "g: Green" << "\n" << "b: Blue" << endl;
    cin >> colorchoice;
    colorEnum tempcolor;
    switch(colorchoice){
        case 'o': tempcolor = orange; break;
        case 'y': tempcolor = yellow; break;
        case 'g': tempcolor = green;  break;
        case 'b': tempcolor = blue;   break;
        break;
        default : tempcolor = white;
    }
    Player p(pname,tempcolor);
    //cout<< "player created" << endl;
    playerfile << "\n--------------------------------" << endl;
    playerfile << "-        TEST STARTED          -" << endl;
    playerfile << "--------------------------------" << endl;
    
    playerfile << "// Player created" << endl;
    p.print(playerfile);
    playerfile << "// test player getcolor "<< endl;
    playerfile << "Color: " << colors[p.getColor()] << endl;
    playerfile << "// test won column: " << endl;    
    p.wonColumn(1);
    playerfile << "// test get score, should be 1" << endl;
    playerfile << "score: " << p.getScore() << endl;
    playerfile << "// test winning, assign 3 scores"<< endl;
    p.wonColumn(2);
    //p.wonColumn(3);
    if ( p.wonColumn(3)) { playerfile << "player won"<< endl;}
    playerfile << "// print player after testing" << endl;
    p.print(playerfile);

    playerfile << "--------------------------------" << endl;
    playerfile << "-        TEST COMPLETE         -" << endl;
    playerfile << "--------------------------------" << endl;
    playerfile.close();
}
//-----------------------------------------------------------------------------
void unitColumn(){
    Column c(4); 
    Column b(2); 
    Player* p = new Player("player",orange);
    Player* x = new Player("playerx",blue);
    c.startTower(p);
    c.print(cout);
    c.move();
    c.print(cout);
    c.stop(p);
    c.print(cout);
    b.startTower(x);
    b.print(cout);
    b.stop(x);
    b.print(cout);
    b.startTower(x);
    b.print(cout);
    b.move();
    b.print(cout);
    b.stop(x);
    b.print(cout);
}
void unitGame(){
    Game g =Game();
    g.oneTurn(g.getPlayer());
    
}
void unitList(){
    ofstream clistfile;
    clistfile.open("clisttestresult.txt", ios_base::app);
    if ( !clistfile.is_open()){ cout << "can not open file" << endl;}
    clistfile << "\n--------------------------------" << endl;
    clistfile << "-        TEST STARTED          -" << endl;
    clistfile << "--------------------------------" << endl;
// Create four dummy Players
    Player* p1 = new Player("player_o", orange);
    Player* p2 = new Player("player_y", yellow);
    Player* p3 = new Player("player_g", green);
    Player* p4 = new Player("player_b", blue);
// add Players.
    CList<Player> c;// player list
    clistfile << "========= test print empty list===========" << endl;
    c.printlist(clistfile);
    clistfile << "==========================================" << endl;
    clistfile << "========== add players to list ===========" << endl;
    c.addItem(p1);
    c.addItem(p2);
    c.addItem(p3);
    c.addItem(p4);
    c.init();
    c.printlist(clistfile);
    clistfile << "==========================================" << endl;
    clistfile << "=========== remove all players ===========" << endl;
// remove a Player
    c.remove();
    c.remove();
    c.remove();
    c.remove();
    c.printlist(clistfile);
    clistfile << "==========================================" << endl;
//  After removing all of the players, you can add Players again.
    clistfile << "=========== add player again =============" << endl;
    c.addItem(p1);
    c.addItem(p2);
    c.addItem(p3);
    c.addItem(p4);
    c.printlist(clistfile);
    clistfile << "==========================================" << endl;
    clistfile << "========= remove item from middle ========" << endl;
// remove a Player
    c.next();
    c.remove();
    c.printlist(clistfile);
    clistfile << "==========================================" << endl;
// nextPlayer() function can progress around the circle and reach the first player again.
    clistfile << "============= testing next ===============" << endl;
    c.printcurrent(clistfile);
    c.next();
    c.printcurrent(clistfile);
    c.next();
    c.printcurrent(clistfile);
    c.next();
    c.printcurrent(clistfile);
    c.next();
    c.printcurrent(clistfile);
    c.next();
    clistfile << "==========================================" << endl;
    clistfile << "--------------------------------" << endl;
    clistfile << "-        TEST COMPLETE         -" << endl;
    clistfile << "--------------------------------" << endl;
    clistfile.close();
}
//-----------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    banner();
    //unitColumn();
    //unitDice();
    //unitPlayer();
    //unitGame();
    unitList();
    bye();
    return 0;
}