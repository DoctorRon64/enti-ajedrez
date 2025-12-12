#pragma once
#include "Vector2.h"

constexpr int BOARD_SIZE = 8;
constexpr char EMPTY_CELL = '*';

struct Board {
	char cells[BOARD_SIZE][BOARD_SIZE];
};

void init_board(Board* b);
void print_board(const Board* b, short size);

bool in_bounds(int x, int y);
bool has_piece(const Board* b, int x, int y);
bool is_king_alive(const Board* b);
void move_piece(Board* b, Vector2 from, Vector2 to);
