#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_board(int board[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++) {
		if (i % BLOCK_SIZE == 0) {
			for (int j = 0; j < SIZE * 2 + BLOCK_SIZE * 2 + 1;
			     j++) {
				printf("-");
			}
			printf("\n");
		}
		for (int j = 0; j < SIZE; j++) {
			if (j % BLOCK_SIZE == 0) {
				printf("| ");
			}
			printf("%d ", board[i][j]);
		}
		printf("|\n");
	}
	for (int i = 0; i < SIZE * 2 + BLOCK_SIZE * 2 + 1; i++) {
		printf("-");
	}
	printf("\n");
}

void randomize_board(int board[SIZE][SIZE], int nonempty_chance)
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (rand() % nonempty_chance == 0)
				board[i][j] = rand() % SIZE + 1;
		}
	}
}

bool check_correct_board(int board[SIZE][SIZE])
{
	for (int n = 0; n < SIZE; n++) {
		if (false == check_correct_row(board, n))
			return false;
		if (false == check_correct_column(board, n))
			return false;
	}
	for (int i = 0; i < BLOCK_SIZE; i++) {
		for (int j = 0; j < BLOCK_SIZE; j++) {
			if (false == check_correct_block(board, i, j))
				return false;
		}
	}
	return true;
}

bool check_correct_row(int board[SIZE][SIZE], const int i)
{
	bool numbers_row[SIZE] = { 0 };
	for (int j = 0; j < SIZE; j++) {
		if (0 == board[i][j])
			continue;
		if (true == numbers_row[board[i][j] - 1])
			return false;
		numbers_row[board[i][j] - 1] = true;
	}
	return true;
}
bool check_correct_column(int board[SIZE][SIZE], const int j)
{
	bool numbers_column[SIZE] = { 0 };
	for (int i = 0; i < SIZE; i++) {
		if (0 == board[i][j])
			continue;
		if (true == numbers_column[board[i][j] - 1])
			return false;
		numbers_column[board[i][j] - 1] = true;
	}
	return true;
}

bool check_correct_block(int board[SIZE][SIZE], const int i, const int j)
{
	bool numbers_block[SIZE] = { 0 };
	for (int k = i * BLOCK_SIZE; k < (i + 1) * BLOCK_SIZE; k++) {
		for (int l = j * BLOCK_SIZE; l < (j + 1) * BLOCK_SIZE; l++) {
			if (0 == board[k][l])
				continue;
			if (true == numbers_block[board[k][l] - 1])
				return false;
			numbers_block[board[k][l] - 1] = true;
		}
	}
	return true;
}

bool solve_board(int board[SIZE][SIZE], int last_i, int last_j)
{
	for (int i = last_i; i < SIZE; i++) {
		for (int j = last_j; j < SIZE; j++) {
			if (0 != board[i][j])
				continue;
			bool used[SIZE] = { 0 };
			fill_used_row(board, i, used);
			fill_used_column(board, j, used);
			fill_used_block(board, i/BLOCK_SIZE, j/BLOCK_SIZE, used);
			for (int k = 0; k < SIZE; k++) {
				if (false == used[k]) {
					board[i][j] = k+1;
					if (true == solve_board(board, i, j))
						return true;
				}
			}
			board[i][j] = 0;
			return false;
		}
		last_j = 0;
	}
	return true;
}

void fill_used_row(int board[SIZE][SIZE], const int i, bool used[SIZE])
{
	for (int j = 0; j < SIZE; j++) {
		if (0 == board[i][j])
			continue;
		used[board[i][j] - 1] = true;
	}
}

void fill_used_column(int board[SIZE][SIZE], const int j, bool used[SIZE])
{
	for (int i = 0; i < SIZE; i++) {
		if (0 == board[i][j])
			continue;
		used[board[i][j] - 1] = true;
	}
}

void fill_used_block(int board[SIZE][SIZE], const int i, const int j, bool used[SIZE])
{
	for (int k = i * BLOCK_SIZE; k < (i + 1) * BLOCK_SIZE; k++) {
		for (int l = j * BLOCK_SIZE; l < (j + 1) * BLOCK_SIZE; l++) {
			if (0 == board[k][l])
				continue;
			used[board[k][l] - 1] = true;
		}
	}
}
