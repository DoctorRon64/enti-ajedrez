#include "Board.h"
#include <iostream>

int main() {
	Board* board = new Board();
	init_board(board);

	bool game_over = false;
	bool white_turn = true;

	while(!game_over) {
		print_board(board, 8);
		std::cout << (white_turn ? "White" : "Black") << " to move." << std::endl;

		Vector2 from = read_position();

		if(!in_bounds(from.x, from.y) || !has_piece(board, from.x, from.y)) {
			std::cout << "Invalid piece.\n";
			break;
		}
	}

	return 0;
}

//TODO
//piece
//pos
//moveDir (possible move positions in vectors)
//extra variables for other conditions

//TODO
// Prompt player to SELECT A piece (which pos)
// Check if what player typed is a position that contains a piece in the board
// Prompt player  for a position to move the piece in
// Check if that positon its a correct position for the selected piece we previously selected.
// if position is correct move piece & if position contains a piece, if piece moves towards the piece, delete piece from the board and overwrite the piece on top of it