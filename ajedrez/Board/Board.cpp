#include "../Board/Board.h"
#include "../Utils/Vector2.h"
#include <iostream>

void init_board(Board* b) {
	for(int i = 0; i < BOARD_SIZE; ++i) {
		for(int j = 0; j < BOARD_SIZE; ++j) {
			b->cells[i][j] = EMPTY_CELL;
		}
	}

<<<<<<<< HEAD:ajedrez/Board.cpp
	b->cells[7][0] = 'R';
	b->cells[7][1] = 'N';
	b->cells[7][2] = 'B';
	b->cells[7][3] = 'Q';
	b->cells[7][4] = 'K';
	b->cells[7][5] = 'B';
	b->cells[7][6] = 'N';
	b->cells[7][7] = 'R';
========
	b->cells[7][0] = ROOK_WHITE;
	b->cells[7][1] = KNIGHT_WHITE;
	b->cells[7][2] = BISHOP_WHITE;
	b->cells[7][3] = QUEEN_WHITE;
	b->cells[7][4] = KING_WHITE;
	b->cells[7][5] = BISHOP_WHITE;
	b->cells[7][6] = KNIGHT_WHITE;
	b->cells[7][7] = ROOK_WHITE;
>>>>>>>> 0c2541f5b41abc0d8f343343d5bf4257b515979a:ajedrez/Board/Board.cpp

	for(int j = 0; j < 8; j++) {
		b->cells[6][j] = 'P';
	}

	b->cells[0][0] = 'r';
	b->cells[0][1] = 'n';
	b->cells[0][2] = 'b';
	b->cells[0][3] = 'q';
	b->cells[0][4] = 'k';
	b->cells[0][5] = 'b';
	b->cells[0][6] = 'n';
	b->cells[0][7] = 'r';

	for(int j = 0; j < 8; j++) {
		b->cells[1][j] = 'p';
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
	return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

bool is_king_alive(const Board* b) {
<<<<<<<< HEAD:ajedrez/Board.cpp
	for(int i = 0; i < BOARD_SIZE; i++) {
		for(int j = 0; j < BOARD_SIZE; j++) {
			if(b->cells[i][j] == 'K' || b->cells[i][j] == 'k') {
========
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			if(b->cells[i][j] == KING_WHITE || b->cells[i][j] == KING_BLACK) {
>>>>>>>> 0c2541f5b41abc0d8f343343d5bf4257b515979a:ajedrez/Board/Board.cpp
				return true;
			}
		}
	}
	return false;
}