#include "board.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

Board::Board(){
    //These vector contains the position of each ladder and snake on the board
    vector<int> snakes, ladders;
    int s, l;
    board_size = 30;
    srand(time(NULL));

    //This cycle generates random positions for the snakes and ladders
    //And saves them into their respective vector
    for(int i = 0; i < 3; i++){
        s = (rand()% (board_size-4)) + 3;
        l = (rand()% (board_size-5)) + 1;

        //These four "while" check if the positions for the current ladder 
        //and snake already exists. If so, new positions are generated
        while(find(snakes.begin(), snakes.end(), s) != snakes.end()){
            s = (rand()% (board_size-4)) + 3;
        }
        while(find(ladders.begin(), ladders.end(), s) != ladders.end()){
            s = (rand()% (board_size-4)) + 3;
        }
        while(find(snakes.begin(), snakes.end(), l) != snakes.end()){
            l = (rand()% (board_size-5)) + 1;
        }
        while(find(ladders.begin(), ladders.end(), l) != ladders.end()){
            l = (rand()% (board_size-5)) + 1;
        }
        snakes.push_back(s);
        ladders.push_back(l);
    }
    //This cylce fills in the board vector with the box type
    //S for snake, L for ladder and N for normal
    for(int i = 0; i < board_size; i++){
        if(find(snakes.begin(), snakes.end(), i) != snakes.end()){
            board.push_back('S');
        }
        else if(find(ladders.begin(), ladders.end(), i) != ladders.end()){
            board.push_back('L');
        }
        else{
            board.push_back('N');
        }
    }
}

//Get box type of wanted position
char Board::getBox(int pos){
    return board[pos];
}

int Board::getBoardSize(){
    return board_size;
}