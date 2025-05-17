#ifndef BOARD_H
#define BOARD_H
#define SIZE 9
#define BLOCK_SIZE 3 // has to be square root of SIZE
#endif //BOARD_H

void show_board(int board[SIZE][SIZE]);
void randomize_board(int board[SIZE][SIZE], int nonempty_chance);
bool check_correct_board(int board[SIZE][SIZE]);
bool check_correct_row(int board[SIZE][SIZE], int i);
bool check_correct_column(int board[SIZE][SIZE], int j);
bool check_correct_block(int board[SIZE][SIZE], int i, int j);
bool solve_board(int board[SIZE][SIZE], int last_i, int last_j);
void fill_used_row(int board[SIZE][SIZE], int i, bool used[SIZE]);
void fill_used_column(int board[SIZE][SIZE], int j, bool used[SIZE]);
void fill_used_block(int board[SIZE][SIZE], int i, int j, bool used[SIZE]);