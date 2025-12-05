#pragma once
#include "Includes.h"

const int BOARD_SIZE = 8;

struct Board {
	char cells[BOARD_SIZE][BOARD_SIZE];
};

void init_board(Board* b);
void print_board(const Board* b, short _size);