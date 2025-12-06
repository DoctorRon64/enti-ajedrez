#pragma once
#include "Vector2.h"

constexpr int BOARD_SIZE = 8;
constexpr char EMPTY_CELL = '*';

struct Board {
	char cells[BOARD_SIZE][BOARD_SIZE];
};

void init_board(Board* b);
void print_board(const Board* b, short _size);

bool in_bounds(int x, int y);
bool has_piece(const Board* b, int x, int y);
Vector2 read_position();