#include "Board.h"

void init_board(Board* b) {
	for(int i = 0; i < BOARD_SIZE; ++i) {
		for(int j = 0; j < BOARD_SIZE; ++j) {
			b->cells[i][j] = 'X';
		}
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
		std::cout << '\n';
	}
}