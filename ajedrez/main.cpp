#include "Board.h"
#include "Includes.h"

struct vector2 {
	short x, y;
};

int main() {
	Board* board = new Board();
	init_board(board);
	print_board(board, 8);

	return 0;
}