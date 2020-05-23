#include "MyGame.h"
#include "player.h"
#include "dice.h"
#include "board.h"

#include <iostream>
using namespace std;

MyGame::MyGame(){
    turn = 1; //The game starts at turn number 1
    maxTurns = 10; //Limit of turns
}

void MyGame::start(){
    Player p1(1); //Player one
    Player p2(2); //Player two
    Board b1; 
    Dice d1; 

    char input; //Input char used to decide whether the game continues or not
    bool check = true; //True if the game continues
    int prevPos; //Previous position of the player, before rolling the dice
    cout << "Press C to continue next turn, or E to end the game:" << endl;

    //While the input char is C and the maximum number of turns hasn't been reached
    //The game will continue 
    while(check && turn < (maxTurns+1)){
        d1.roll();
        if(turn % 2 == 0){
            prevPos = p2.getPosition();
            p2.movePlayer(d1.getLastRoll(), b1);
            gameDetails(prevPos, d1.getLastRoll(), p2, b1);

        }
        else{ //Since player one starts first, this player will have turns with an odd number
            prevPos = p1.getPosition();
            p1.movePlayer(d1.getLastRoll(), b1);
            gameDetails(prevPos, d1.getLastRoll(), p1, b1);
        }
        cin >> input;
        check = continueGame(input);
        turn++;
    }
    cout << "-- GAME OVER --" << endl;
    //If player one reaches the last position, wins
    if(p1.getPosition() == 30 && p2.getPosition() != 30){
        cout << "Player 1 is the winner!!!";
    }
    //If player two reaches the last position, wins
    else if(p1.getPosition() != 30 && p2.getPosition() == 30){
        cout << "Player 2 is the winner!!!";
    }
    //If the input char is E and nobody reached the last position
    //So nobody wins
    else if(input == 'E' && p1.getPosition() != 30 && p2.getPosition() != 30){
        cout << "Thanks for playing!!!";
    }
    else if(turn == (maxTurns+1)){
        cout << "The maximum number of turns has been reached...";
    }
}

void MyGame::gameDetails(int prev, int dice, Player p, Board b){
    cout << turn << " " << p.getNumber() << " " << prev << " "
    << dice << " " << b.getBox(prev + dice) << " " << p.getPosition() << endl;
} //Displays game detalis like this: "1 1 1 5 N 6"

bool MyGame::continueGame(char input){
    bool ans;
    input = toupper(input);
    if(input == 'C'){ //The game will continue
        ans = true;
    }
    else if(input == 'E'){ //The game will end
        ans = false;
    }
    else{ //If and invalid option is written, a new input is asked and the method is called with this new input
        cout << "Invalid option, please press C to continue next turn or E to end the game" << endl;
        cin >> input;
        ans = continueGame(input);
    }
    return ans;
}