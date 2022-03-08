#include <iostream>
using namespace std;

#include "tictactoe.h"
using namespace std;

void welcome();

int main() {
    tictactoe game;
    bool gameOver;
    bool gameWon;
    char YorN = 'y';
    string loc;
    string playerStart;
    string playerSec;

    welcome();

    while(toupper(YorN) == 'Y'){
        playerStart = game.whoseTurn(); //alternates X and O as starting player

        if(playerStart == "X"){
            playerSec = "O";
        }
        else{
            playerSec = "X";
        }

        game.gameReset();
        game.displayGame();

        gameOver = false;
        gameWon = false;

        while(!gameOver){
            cout << "\nPlayer " << playerStart << ", where would you like to place your piece (ex: 21): ";
            cin >> loc;
            gameOver = game.placement(loc, playerStart, gameOver, gameWon);
            game.displayGame();

            if(gameOver){
                break;
            }

            cout << "\nPlayer " << playerSec << ", where would you like to place your piece (ex: 21): ";
            cin >> loc;
            gameOver = game.placement(loc, playerSec, gameOver, gameWon);
            game.displayGame();

            if(gameOver){
                break;
            }
        }
        cout << "\nWould you like to play again? y/n: ";
        cin >> YorN;
    }



    return 0;
}

void welcome(){
    tictactoe starts;
    starts.clearTerminal();
    cout << "Welcome to tick-tack-toe, the game of Xs and Os.\n"
            "The objective of the game is to get three of your pieces in adjacent blocks before your opponent does\n"
            "Its a game of strategy and deception\n"
            "You will be asked to place your piece in an available block by inputting the name of the block denoted by 2 numbers\n"
            "Be careful trying a nonexistent or already used block could make you lose your turn\n"
            "We will keep track of the scores\n"
            "Happy clubbing, and may the best man win\n"
            "Press ENTER to continue\n\n";
    cin.get();

}