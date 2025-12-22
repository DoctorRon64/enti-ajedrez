#include "../Board/Board.h"
#include "../Moves/Moves.h"
#include "../Piece/Piece.h"
#include "../Utils/Vector2.h"
#include <iostream>

void init_board(Board* b) {
	for(short i = 0; i < BOARD_SIZE; ++i) {
		for(short j = 0; j < BOARD_SIZE; ++j) {
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

	for(short j = 0; j < BOARD_SIZE; j++) {
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

	for(short j = 0; j < BOARD_SIZE; j++) {
		b->cells[1][j] = PAWN_BLACK;
	}
}

void print_board(const Board* b, short _size) {
	for(short i = 0; i < _size; i++) {
		std::cout << i + 1;
		std::cout << ' ';
	}
	std::cout << std::endl;
	for(short i = 0; i < _size; ++i) {
		for(short j = 0; j < _size; ++j) {
			std::cout << b->cells[i][j] << ' ';
		}
		std::cout << i + 1;
		std::cout << std::endl;
	}
}

bool has_piece(const Board* b, short x, short y) {
	return b->cells[x][y] != EMPTY_CELL;
}

bool in_bounds(short x, short y) {
	return x >= MIN_INDEX && x < BOARD_SIZE && y >= MIN_INDEX && y < BOARD_SIZE;
}

bool is_king_alive(const Board* b) {
	for(short i = 0; i < BOARD_SIZE; i++) {
		for(short j = 0; j < BOARD_SIZE; j++) {
			if(b->cells[i][j] == KING_WHITE || b->cells[i][j] == KING_BLACK) {
				return true;
			}
		}
	}
	return false;
}

bool is_in_check(const Board* b, bool whiteKing) {
	Vector2 kingPos;

	// Find king
	for(short i = 0; i < BOARD_SIZE; i++) {
		for(short j = 0; j < BOARD_SIZE; j++) {
			char c = b->cells[i][j];
			if((whiteKing && c == KING_WHITE) ||
			   (!whiteKing && c == KING_BLACK)) {
				kingPos = { i, j };
			}
		}
	}

	// Can any enemy piece capture the king?
	for(short i = 0; i < BOARD_SIZE; i++) {
		for(short j = 0; j < BOARD_SIZE; j++) {
			char c = b->cells[i][j];
			if(c == EMPTY_CELL) continue;

			if(is_white(c) != whiteKing) {
				Vector2 from = { i, j };
				if(is_valid_move(b, from, kingPos)) {
					return true;
				}
			}
		}
	}

	return false;
}
bool is_checkmate(const Board* b, bool whiteKing) {
	if(!is_in_check(b, whiteKing))
		return false;

	// Try all king moves
	Vector2 kingPos;
	for(short i = 0; i < BOARD_SIZE; i++) {
		for(short j = 0; j < BOARD_SIZE; j++) {
			char c = b->cells[i][j];
			if((whiteKing && c == KING_WHITE) ||
			   (!whiteKing && c == KING_BLACK)) {
				kingPos = { i, j };
			}
		}
	}

	for(short dx = -1; dx <= 1; dx++) {
		for(short dy = -1; dy <= 1; dy++) {
			if(dx == 0 && dy == 0) continue;

			Vector2 to = { kingPos.x + dx, kingPos.y + dy };
			if(!in_bounds(to.x, to.y)) continue;

			Board temp = *b;
			if(is_valid_move(&temp, kingPos, to)) {
				move_piece(&temp, kingPos, to);
				if(!is_in_check(&temp, whiteKing)) {
					return false;
				}
			}
		}
	}

	return true;
}

void move_piece(Board* b, Vector2 from, Vector2 to) {
	char piece = b->cells[from.x][from.y];

	if((piece == PAWN_WHITE || piece == PAWN_BLACK) && b->enPassant.valid) {
		short direction = (piece == PAWN_WHITE) ? -1 : 1;

		//Enpassant capture (Before reset)
		if(to.x == from.x + direction
			&& to.y == b->enPassant.pawnPos.y
			&& from.x == b->enPassant.pawnPos.x
			&& b->enPassant.pawnIsWhite != is_white(piece)) {
			b->cells[b->enPassant.pawnPos.x][b->enPassant.pawnPos.y] = EMPTY_CELL;
		}
	}

	// Reset en passant by default
	b->enPassant.valid = false;

	// Detect pawn double move
	if(piece == PAWN_WHITE && from.x == 6 && to.x == 4) {
		b->enPassant.valid = true;
		b->enPassant.pawnPos = to;
		b->enPassant.pawnIsWhite = true;
	}
	else if(piece == PAWN_BLACK && from.x == 1 && to.x == 3) {
		b->enPassant.valid = true;
		b->enPassant.pawnPos = to;
		b->enPassant.pawnIsWhite = false;
	}

	// Move piece
	b->cells[to.x][to.y] = piece;
	b->cells[from.x][from.y] = EMPTY_CELL;

	// Pawn promotion
	if(piece == PAWN_WHITE && to.x == 0) {
		b->cells[to.x][to.y] = QUEEN_WHITE;
	}
	else if(piece == PAWN_BLACK && to.x == BOARD_SIZE - 1) {
		b->cells[to.x][to.y] = QUEEN_BLACK;
	}
}