#pragma once
#include "Vector2.h"

constexpr short MIN_INDEX = 0;
constexpr short BOARD_SIZE = 8;
constexpr char EMPTY_CELL = '*';

constexpr char ROOK_BLACK = 'r';
constexpr char KNIGHT_BLACK = 'n';
constexpr char BISHOP_BLACK = 'b';
constexpr char QUEEN_BLACK = 'q';
constexpr char KING_BLACK = 'k';
constexpr char PAWN_BLACK = 'p';

constexpr char ROOK_WHITE = 'R';
constexpr char KNIGHT_WHITE = 'N';
constexpr char BISHOP_WHITE = 'B';
constexpr char QUEEN_WHITE = 'Q';
constexpr char KING_WHITE = 'K';
constexpr char PAWN_WHITE = 'P';

struct Board {
	char cells[BOARD_SIZE][BOARD_SIZE];
};

void init_board(Board* b);
void print_board(const Board* b, short size);

bool in_bounds(int x, int y);
bool has_piece(const Board* b, int x, int y);
bool is_king_alive(const Board* b);
void move_piece(Board* b, Vector2 from, Vector2 to);
