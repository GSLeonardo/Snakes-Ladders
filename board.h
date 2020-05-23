#ifndef BOARD_H
#define BOARD_H

#include<vector>
#include<iostream>
using namespace std;

class Board{
    private:
        vector<char> board;
        int board_size; 
    public:
        Board();
        void showBoard(); //Prints board
        char getBox(int); //Returns type of box (N, L or S)
        int getBoardSize(); //Returns board size
};
#endif