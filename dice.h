#ifndef DICE_H
#define DICE_H

class Dice{
    private:
        int lastRoll;
    public:
        Dice();
        int roll();
        int getLastRoll();
};
#endif