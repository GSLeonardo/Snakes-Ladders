#include "dice.h"
#include <iostream>
#include <ctime>
using namespace std;

//Constructor initializes random seed
Dice::Dice(){
    srand(time(NULL));
}

//Roll method that returns a random number beetween 1 and 6
int Dice::roll(){
    int num  = rand() % 6 + 1;
    lastRoll = num;
    return num;
}

//Returns number from last roll
int Dice::getLastRoll(){
    return lastRoll;
}