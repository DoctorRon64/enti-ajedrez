#include "Piece.h"

PieceType get_piece_type(char p) {
	switch(tolower(p)) {
		case 'p': return PAWN;
		case 'r': return ROOK;
		case 'n': return KNIGHT;
		case 'b': return BISHOP;
		case 'q': return QUEEN;
		case 'k': return KING;
		default: return NONE;
	}
}

bool is_white(char p) {
	return p >= 'A' && p <= 'Z';
}

bool is_black(char p) {
	return p >= 'a' && p <= 'z';
}