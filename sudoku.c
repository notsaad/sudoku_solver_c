#include <stdio.h>

void solver(int board[9][9]);

int main(){

    // a 0 symbolizes an empty cell, as in sudoku all cells have values 1-9 when solved
    int board[9][9];

    for (int i = 0; i < 9; ++i){
        for (int j = 0; j < 9; ++j){
            board[i][j] = 0;
        }
    }


    // manually filling in some values for now

    board[0][6] = 2;

    board[1][1] = 8;
    board[1][5] = 7;
    board[1][7] = 9;

    board[2][0] = 6;
    board[2][2] = 2;
    board[2][6] = 5;

    board[3][1] = 7;
    board[3][4] = 6;

    board[4][3] = 9;
    board[4][5] = 1;

    board[5][4] = 2;
    board[5][7] = 4;

    board[6][2] = 5;
    board[6][6] = 6;
    board[6][8] = 3;

    board[7][1] = 9;
    board[7][3] = 4;
    board[7][7] = 7;

    board[8][2] = 6;


    // printing the starting board
    for (int i = 0; i < 9; ++i){
        for (int j = 0; j < 9; ++j){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    solver(board);

    // print the solved board
    for (int i = 0; i < 9; ++i){
        for (int j = 0; j < 9; ++j){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void solver(int board[9][9]){

    for (int i = 1; i < 10; ++i){
        printf("%d\n", i);
    }

    return;
}

