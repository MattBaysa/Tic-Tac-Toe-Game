//
// Created by Matthew Baysa on 2/14/22.
//
#include <iostream>
using namespace std;

#ifndef P2_TICTACTOE_H
#define P2_TICTACTOE_H


class tictactoe {
public:
    void displayGame();
    void gameReset();
    void displayScore();
    bool placement(string plc, string user, bool& done, bool& won);
    void clearTerminal();
    string whoseTurn();

private:
    int turnCounter = 0;
    int games = 0;
    int XWins = 0;
    int OWins = 0;
    int dim=3;
    string **board;
    int nameRow;
    int nameCol;
    string place;
    //need array that holds the locations of each block;
    string blockCont[9];
};


#endif //P2_TICTACTOE_H
