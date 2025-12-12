#include "Board.h"
#include "Input.h"
#include "Moves.h"
#include "Piece.h"
#include <iostream>

int main() {
	Board* board = new Board();
	init_board(board);

	bool game_over = false;
	bool white_turn = true;

	while(!game_over) {
		system("cls");
		print_board(board, 8);
		std::cout << (white_turn ? "White" : "Black") << " to move." << std::endl;

		Vector2 from = read_position();
		if(!in_bounds(from.x, from.y) || !has_piece(board, from.x, from.y)) {
			std::cout << "Invalid piece.\n";

			throw std::runtime_error("Division by zero error");
			continue;
		}
		else {
			char piece = board->cells[from.x][from.y];
			if(white_turn && is_black(piece)) {
				std::cout << "That's not your piece!\n";
				continue;
			}
			if(!white_turn && is_white(piece)) {
				std::cout << "That's not your piece!\n";
				continue;
			}

			Vector2 to = read_position();
			if(!in_bounds(to.x, to.y)) {
				std::cout << "Destination out of bounds!\n";
				continue;
			}
			else if(is_valid_move(board, from, to)) {
				move_piece(board, from, to);
			}
		}
	}

	return 0;
}

// Check if that positon its a correct position for the selected piece we previously selected.
// if position is correct move piece & if position contains a piece, if piece moves towards the piece, delete piece from the board and overwrite the piece on top of it