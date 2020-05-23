#ifndef MYGAME_H
#define MYGAME_H

#include "board.h"
#include "player.h"

#include <iostream>
using namespace std;

class MyGame{
    private:
        int turn;
        int maxTurns;

    public:
        MyGame();

        void start();//Starts the game
        bool continueGame(char);
        void gameDetails(int, int, Player, Board);
};
#endif