#include "Board.h"
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

Vector2 read_position() {
	Vector2 pos;
	std::cout << "Enter row: ";
	std::cin >> pos.x;
	std::cout << "Enter colomn: ";
	std::cin >> pos.y;
	pos.x--;
	pos.y--;

	//TODO Handle characters like [F] or [A] and stuff that dont belong to numbers
	return pos;
}

bool is_valid_move(Board* b, Vector2 from, Vector2 to) {
	char p = b->cells[from.x][from.y];
	PieceType t = get_piece_type(p);

	switch(t) {
		//TODO implement all moves
		//case PAWN:   return valid_pawn_move(b, from, to, is_white(p));
		//case ROOK:   return valid_rook_move(b, from, to);
		//case KNIGHT: return valid_knight_move(b, from, to);
		//case BISHOP: return valid_bishop_move(b, from, to);
		//case QUEEN:  return valid_queen_move(b, from, to);
		//case KING:   return valid_king_move(b, from, to);
		default:     return false;
	}
}

void move_piece(Board* b, Vector2 from, Vector2 to) {
	b->cells[to.x][to.y] = b->cells[from.x][from.y];
	b->cells[from.x][from.y] = EMPTY_CELL;
}

bool is_king_alive(Board* b) {
	bool king_alive = false;
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			if(b->cells[i][j] == 'K' || b->cells[i][j] == 'k') {
				king_alive = true;
				return true;
			}
		}
	}

	if(!king_alive) {
		return false;
	}
}

// Check if that positon its a correct position for the selected piece we previously selected.
// if position is correct move piece & if position contains a piece, if piece moves towards the piece, delete piece from the board and overwrite the piece on top of it