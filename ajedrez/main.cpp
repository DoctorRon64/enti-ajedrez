#include "Board.h"
#include "Input.h"
#include "Moves.h"
#include "Piece.h"
#include <iostream>

int main() {
	Board board;
	init_board(&board);

	bool game_over = false;
	bool white_turn = true;

	while(!game_over) {
		system("cls");
		print_board(&board, BOARD_SIZE);
		std::cout << (white_turn ? "White" : "Black") << " to move.\n";

		Vector2 from = read_position();
		if(!in_bounds(from.x, from.y) || !has_piece(&board, from.x, from.y)) {
			std::cout << "Invalid piece.\n";
			continue;
		}

		char piece = board.cells[from.x][from.y];
		if((white_turn && is_black(piece)) || (!white_turn && is_white(piece))) {
			std::cout << "That's not your piece!\n";
			continue;
		}

		Vector2 to = read_position();
		if(!in_bounds(to.x, to.y)) {
			std::cout << "Destination out of bounds!\n";
			continue;
		}

		if(is_valid_move(&board, from, to)) {
			move_piece(&board, from, to);

			if(!is_king_alive(&board)) {
				game_over = true;
				std::cout << (white_turn ? "White" : "Black") << " wins!\n";
			}
			else {
				white_turn = !white_turn;
			}
		}
	}

	return 0;
}