/*
 * File:   main.cpp
 * Author: James Heyne
 *
 * Created on October 1, 2021, 4:29 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <unistd.h> 
using namespace std;


/**
 * 
 * @param starter if 0 then AI is starting, if 1 then player is starting
 */
 void setUpBoard(int starter){
     // Setting the array as char to save as much memory as possible
     // Computer pieces : R = Rook, N = knight, B = Bishop, Q = Queen, K = King, P = Pawn
     // Neutral pieces  : S = Space
     // Player pieces   : O = Rook, I = knight, H = Bishop, U = Queen, G = King, A = Pawn
     // a b c d e f g h i j k l m n o p q r s t u v w x y z 
     vector<vector<char>> chessBoard
    {
        {"O", "I", "H", "U", "G", "H", "I", "O"},
        {"A", "A", "A", "A", "A", "A", "A", "A"},
        {"S", "S", "S", "S", "S", "S", "S", "S"},
        {"S", "S", "S", "S", "S", "S", "S", "S"},
        {"S", "S", "S", "S", "S", "S", "S", "S"},
        {"S", "S", "S", "S", "S", "S", "S", "S"},
        {"P", "P", "P", "P", "P", "P", "P", "P"},
        {"R", "N", "B", "Q", "K", "B", "N", "R"},
    };
 }
 
 void decideTurns(){
    bool validAns = false;
    while (!validAns){
        cout << "Would you like to pick who goes first or would you like to flip a coin (Pick/Coin)? :";
        string ans;
        cin >> ans;
        if(ans == "Pick"){
            validAns = true;
            bool validAns2 = false;
            while(!validAns2){
                cout << "Who would you like to go first (Player/Computer):";
                string pick;
                cin >> pick;
                if(pick == "Computer"){
                    setUpBoard(0);
                    validAns2 = true;
                } else if (pick == "Player"){
                    setUpBoard(1);
                    validAns2 = true;
                }
            }
        }
        if(ans == "Coin"){
            cout << "Flipping a coin.";
            
            cout << endl;
            
            sleep(1);
            
            cout << endl;
            srand (time(NULL));
            int v1 = rand() % 100;
            if(v1 <= 50){
                cout << "It's heads! I'll go first";
                setUpBoard(0);
            } else{
                cout << "It's tails! You go first.";
                setUpBoard(1);
            }
            validAns = true;
        }
    }
 }
/**
 * 
 * @param chessBoard
 * @return returns 1 if user wants to play again and 0 if user wants to quit
 */
int takeUserInput(){
    bool validAns = false;
    while (!validAns){
        cout << "Hello, would you like to play a game of chess (Y/N)? : ";
        string ans;
        cin >> ans;
        if(ans == "Y"){
            validAns = true;
            decideTurns();
            return 1;
        } else if( ans == "N"){
            validAns = true;
            return 0;
        }
        // Keep looping until we get a valid answer
    }
    return 0;
}




// int getValueOfBoardState(){

// void findValidMoves(){


int main(int argc, char** argv) {

    takeUserInput();
    
    return 0;
}

