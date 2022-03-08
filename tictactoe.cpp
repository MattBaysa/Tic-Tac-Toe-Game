//
// Created by Matthew Baysa on 2/14/22.
//

#include "tictactoe.h"
#include <string>

void tictactoe::gameReset() {
    //reset board so that all are empty
    int counter = 0;
    for(int x = 0; x < dim; x++) { //moving from left to right
        nameRow = x;
        for (int y = 0; y < dim; y++) {
            nameCol = y;
            place = to_string(nameRow) + to_string(nameCol);
            while (place.length() < 4) {
                place = place + " ";
            }
            blockCont[counter] = place;
            counter += 1;
        }
    }
    //reset so that game is now complete
    turnCounter = 0;
}

void tictactoe::displayGame() {
    //create space for game
    int counter = 0;
    board = new string *[dim + (dim -1)]; // set up amount of rows

    for (int i = 0; i < dim + (dim -1); i++){ //set up columns
        board[i] = new string[dim + (dim -1)]; //the dimensions will be 2 dimension - 1 to hold the board
    }

    //begin to fill the arrays with the board
    for(int x = 0; x < dim + (dim -1); x++){ //moving from left to right
        for(int y = 0; y < dim + (dim -1); y++){
            if(x%2 == 0){ //if x even or 0
                if(y%2 == 0){ //if y even or 0
                    board[x][y] = blockCont[counter];
                    counter++;
                }
                else{ //odd is where the board "pieces" are held
                    board[x][y] = " || ";
                }
            }
            else{ //x is odd the entire row should be horizontal lines with + to connect vertical lines
                if(x%2 == 1){ //if x odd or 0
                    if(y%2 == 0){ //if y even or 0
                        board[x][y] = "----";
                    }
                    else{ //odd is where the board "pieces" are held
                        board[x][y] = "-++-";
                    }
                }
            }
        }
    }
    for(int x = 0; x < dim + (dim -1); x++) { //moving from left to right
        for (int y = 0; y < dim + (dim - 1); y++) {
            cout << board[x][y];
        }
        cout << endl;
    }
    delete board;
}

bool tictactoe::placement(string plc, string user, bool& done, bool& won){ //player now places piece either "X" or "O"
    while (plc.length() < 4) { //make desired place same format as place in block
        plc = plc + " ";
    }

    while (user.length() < 4){ //make users piece same format as place in block
        user = user + " ";
    }

    bool valid = false;
    for(int i = 0; i < dim*dim; i++){
        if(plc == blockCont[i]){ //find desired placement and add X or O
            blockCont[i] = user;
            valid = true;
        }
    }

    if(!valid){
        cout << "THIS BLOCK IS NOT AVAILABLE. YOU HAVE JUST SACRIFICED YOUR TURN\n";
        turnCounter --;
    }

    //check if there is a winner or game is done
    for(int i =0; i < dim*dim; i++){
        if(blockCont[i] == user){ //first instance of player piece
            if(i%dim == 0 && blockCont[i+1] == user && blockCont[i+2] == user){ //horizontal wins
                won = true;
                done = true;
            }
            else if(i < dim && blockCont[i+3] == user && blockCont[i+6] == user){ //vertical wins
                won = true;
                done = true;
            }
            else if(i == 0 && blockCont[i+4] == user && blockCont[i+8] == user){ //diagonal l to r
                won = true;
                done = true;
            }
            else if(blockCont[2] == user && blockCont[4] == user && blockCont[6] == user){ //diagonal r to l
                won = true;
                done = true;
            }
            else{
                break;
            }
        }

    }

    //record who won
    if(won && done){
        if(user == "X   "){
            XWins ++;
        }
        else{
            OWins ++;
        }
        games ++;
        displayScore();
    }


    turnCounter ++;
    if(turnCounter == dim*dim+1){ //if the board is filled and no one has won
        done = true;
        games ++;
        displayScore();
    }

    return done;
}

void tictactoe::clearTerminal() {
    for(int i = 0; i < 25; i++){
        cout << endl;
    }
}

void tictactoe::displayScore(){
    cout << endl << "Player X wins: " << XWins << endl
    << "Player O wins: " << OWins << endl
    << "Games played: " << games << endl;
}

string tictactoe::whoseTurn() {
    string starter;
    if(games%2 == 0){ //even games
        starter = "X";
    }
    else{
        starter ="O";
    }
    return starter;
}