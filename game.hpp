/*  ----------------------------------------------------------------------------
//  Game Header file                          Game.hpp
//  Created by Chris Dowd and Eyad Esmail 
//  Created on 4/17/2021
*/
#ifndef CANTSTOP_GAME_HPP
#define CANTSTOP_GAME_HPP
#include "dice.hpp"
#include "enums.hpp"
#include "column.hpp"
#include "player.hpp"
#include "board.hpp"
using namespace std;
class Game {
private:
    Dice* diceSet = new Dice(4);
    Player* p = getNewPlayer();
    Board*  b = new Board();

public:
    Game();
    ~Game(){delete diceSet;};
    Player* getNewPlayer();
    Player* getPlayer(){return p;};
    void oneTurn(Player* pp);
    void menu(Player* pp);
    void roll();
    void stop(Player* pp);
    void resign(Player* pp);
    int choosepair();
};

#endif //CANTSTOP_GAME_HPP
