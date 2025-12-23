#include "Board/Board.h"
#include "Input/Input.h"
#include "Moves/Moves.h"
#include "Piece/Piece.h"
#include <cstdlib>
#include <iostream>

int main() {
	Board board;
	init_board(&board);

	bool game_over = false;
	bool white_turn = true;

	while(!game_over) {
		system("cls"); //windows only, use "clear" for linux & macOS
		print_board(&board, BOARD_SIZE);

		if(game_over) break; // make sure nothing renders after game ends
		std::cout << (white_turn ? "White" : "Black") << " to move.\n";

		MoveInput move = read_move();
		Vector2 from = move.from;
		if(!in_bounds(from.x, from.y) || !has_piece(&board, from.x, from.y)) {
			std::cout << "Invalid piece.\n";
			continue;
		}

		char piece = board.cells[from.x][from.y];
		if((white_turn && is_black(piece)) || (!white_turn && is_white(piece))) {
			std::cout << "That's not your piece!\n";
			continue;
		}
		Vector2 whiteKing = find_king(&board, true);
		Vector2 blackKing = find_king(&board, false);
		// it checks if the king gets captured and if it does the game ends
		if (whiteKing.x == -1 || blackKing.x == -1) {
			game_over = true;
			print_board(&board, BOARD_SIZE);
			std::cout << (whiteKing.x == -1 ?
				"White king captured. Black wins!\n" :
				"Black king captured. White wins!\n");
			system("pause");
		}	

		Vector2 to = move.to;
		if(!in_bounds(to.x, to.y)) {
			std::cout << "Destination out of bounds!\n";
			continue;
		}

		if(is_valid_move(&board, from, to)) {
			move_piece(&board, from, to);

			if(is_checkmate(&board, !white_turn)) {
				game_over = true;
				print_board(&board, BOARD_SIZE);
				std::cout << "Checkmate! " << (white_turn ? "White" : "Black") << " wins!\n";
				system("pause"); // pause so the player sees the message
				continue; // loop will exit naturally since game_over == true
				
			}
			else if(!can_any_move_rescue(&board, !white_turn) && !is_in_check(&board, !white_turn)) {
				game_over = true;
				print_board(&board, BOARD_SIZE);
				std::cout << "Stalemate! It's a draw.\n";
				system("pause");
				continue;
			}
			else {
				if(is_in_check(&board, !white_turn)) {
					print_board(&board, BOARD_SIZE);
					std::cout << (white_turn ? "Black" : "White") << " is in check!\n";
					system("pause"); // just a warning, game continues
					white_turn = !white_turn; // only switch turns if the game continues
					continue;
				}
				white_turn = !white_turn; 
			}
		}
		else {
			std::cout << "Invalid move.\n";
			system("pause"); // pause so player can read message
		}
	}

	return 0;
}