#include "player.h"
#include "board.h"

#include <iostream>
using namespace std;

//Creates a new player and places it at the begining of the board
Player::Player(int number_){
    number = number_;
    position = 1;
}

//Moves the player on the board
void Player::movePlayer(int dice_num, Board game){
    position += dice_num; //Adds dice number to position

    //If box is a snake, the player moves backwards 3 spaces
    if(game.getBox(position) == 'S'){ 
        position -= 3;
    }
    //If box is a ladder, the player moves foward 3 spaces
    else if(game.getBox(position) == 'L'){
        position += 3;
    }

    //In case the position exceeds the last position
    //The limit position is 30
    if(position > 30){
        position = 30;
    }
}

int Player::getPosition(){ //Gets player position
    return position;
}
int Player::getNumber(){ //Gets player number
    return number;
}