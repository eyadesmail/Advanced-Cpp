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
class Game {
private:
    Dice* diceSet = new Dice(4);
    Player* p1 = getNewPlayer();
    Player* p2 = getNewPlayer();
    Column* c1 = new Column(2);
    Column* c2 = new Column(7);
public:
    Game();
    ~Game(){delete diceSet;};
    Player* getNewPlayer();
};

#endif //CANTSTOP_GAME_HPP
