#include "../Board/Board.h"
#include "../Utils/Vector2.h"
#include <iostream>

void init_board(Board* b) {
	for(int i = 0; i < BOARD_SIZE; ++i) {
		for(int j = 0; j < BOARD_SIZE; ++j) {
			b->cells[i][j] = EMPTY_CELL;
		}
	}

	b->cells[7][0] = ROOK_WHITE;
	b->cells[7][1] = KNIGHT_WHITE;
	b->cells[7][2] = BISHOP_WHITE;
	b->cells[7][3] = QUEEN_WHITE;
	b->cells[7][4] = KING_WHITE;
	b->cells[7][5] = BISHOP_WHITE;
	b->cells[7][6] = KNIGHT_WHITE;
	b->cells[7][7] = ROOK_WHITE;

	for(int j = 0; j < 8; j++) {
		b->cells[6][j] = PAWN_WHITE;
	}

	b->cells[0][0] = ROOK_BLACK;
	b->cells[0][1] = KNIGHT_BLACK;
	b->cells[0][2] = BISHOP_BLACK;
	b->cells[0][3] = QUEEN_BLACK;
	b->cells[0][4] = KING_BLACK;
	b->cells[0][5] = BISHOP_BLACK;
	b->cells[0][6] = KNIGHT_BLACK;
	b->cells[0][7] = ROOK_BLACK;

	for(int j = 0; j < 8; j++) {
		b->cells[1][j] = PAWN_BLACK;
	}
}

void print_board(const Board* b, short _size) {
	for(int i = 0; i < _size; i++) {
		std::cout << i + 1;
		std::cout << ' ';
	}
	std::cout << std::endl;
	for(int i = 0; i < _size; ++i) {
		for(int j = 0; j < _size; ++j) {
			std::cout << b->cells[i][j] << ' ';
		}
		std::cout << i + 1;
		std::cout << std::endl;
	}
}

bool has_piece(const Board* b, int x, int y) {
	return b->cells[x][y] != EMPTY_CELL;
}

bool in_bounds(int x, int y) {
	return x >= MIN_INDEX && x < BOARD_SIZE && y >= MIN_INDEX && y < BOARD_SIZE;
}

bool is_king_alive(const Board* b) {
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			if(b->cells[i][j] == KING_WHITE || b->cells[i][j] == KING_BLACK) {
				return true;
			}
		}
	}
	return false;
}

void move_piece(Board* b, Vector2 from, Vector2 to) {
	b->cells[to.x][to.y] = b->cells[from.x][from.y];
	b->cells[from.x][from.y] = EMPTY_CELL;
}