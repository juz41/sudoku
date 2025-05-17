#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"

int main(void)
{
	srand(time(NULL));
	// int board[SIZE][SIZE] = {
	// 	{ 5, 3, 4, 6, 7, 8, 9, 1, 2 }, { 6, 7, 2, 1, 9, 5, 3, 4, 8 },
	// 	{ 1, 9, 8, 3, 4, 2, 5, 6, 7 }, { 8, 5, 9, 7, 6, 1, 4, 2, 3 },
	// 	{ 4, 2, 6, 8, 5, 3, 7, 9, 1 }, { 7, 1, 3, 9, 2, 4, 8, 5, 6 },
	// 	{ 9, 6, 1, 5, 3, 7, 2, 8, 4 }, { 2, 8, 7, 4, 1, 9, 6, 3, 5 },
	// 	{ 3, 4, 5, 2, 8, 6, 1, 7, 9 }
	// };
	int board[SIZE][SIZE] = { 0 };
	solve_board(board, 0, 0);
	// randomize_board(board, 1);
	show_board(board);
	printf("Is correct: %d\n", check_correct_board(board));
	return 0;
}
