#include <stdio.h>
#include <stdlib.h>

void solver(int board[9][9], int cells_left, int free_row_nums[9][10], int free_col_nums[9][10], int free_sqr_nums[9][10]);

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

    int cells_left = 81;

    int free_row_nums[9][10];
    int free_col_nums[9][10];
    int free_sqr_nums[9][10];

    for (int i = 0; i < 9; ++i){
        for (int j = 0; j < 10; ++j){
            free_row_nums[i][j] = 0;
            free_col_nums[i][j] = 0;
            free_sqr_nums[i][j] = 0;
        }
    }

    // printing the starting board
    for (int i = 0; i < 9; ++i){
        for (int j = 0; j < 9; ++j){
            printf("%d ", board[i][j]);
            if (board[i][j] != 0){
                cells_left--;
                free_row_nums[i][board[i][j]] = 1;
                free_col_nums[j][board[i][j]] = 1;

                free_sqr_nums[ 3*(i/3) + (j/3) ][board[i][j]] = 1;

            }
        }
        printf("\n");
    }

    for (int i=0; i < 9; ++i){
        printf("Valid numbers in square %d:", i+1);
        for (int j=1; j < 10; ++j){
            printf("%d ", free_sqr_nums[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");


    solver(board, cells_left, free_row_nums, free_col_nums, free_sqr_nums);

    // print the solved board
    for (int i = 0; i < 9; ++i){
        for (int j = 0; j < 9; ++j){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void solver(int board[9][9], int cells_left, int free_row_nums[9][10], int free_col_nums[9][10], int free_sqr_nums[9][10]){

    if (!cells_left){
        puts("board solved");

        return;
    }

    system("clear");
    for (int i = 0; i < 9; ++i){
        for (int j = 0; j < 9; ++j){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    
    for (int r=0; r < 9; ++r){
        for (int c=0; c < 9; ++c){
            // for each row try all available values
            if (board[r][c] == 0){
                for (int i = 1; i < 10; ++i){
                    if ((free_row_nums[r][i] == 0) && (free_col_nums[c][i] == 0) && (free_sqr_nums[ 3*(r/3) + (c/3) ][i] == 0)){
                        board[r][c] = i;
                        free_row_nums[r][i] = 1;
                        free_col_nums[c][i] = 1;
                        //printf("%d is free in both row %d and col %d\n", i, r, c);
                        solver(board, cells_left-1, free_row_nums, free_col_nums, free_sqr_nums);
                        free_row_nums[r][i] = 0;
                        free_col_nums[c][i] = 0;
                        board[r][c] = 0;
                    }
                }
            }
        }
    }

    return;
}

