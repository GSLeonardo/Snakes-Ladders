#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"

#include <iostream>
using namespace std;

class Player{
    private:
        int number; //Number of player
        int position; //Current position
    public:
        Player(int);

        void movePlayer(int, Board); //Changes the positon of the player
        int getPosition(); 
        int getNumber();
};
#endif