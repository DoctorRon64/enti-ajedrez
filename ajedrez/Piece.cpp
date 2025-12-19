#include "Board.h"
#include "Piece.h"

constexpr char WHITE_START = 'A';
constexpr char WHITE_END = 'Z';
constexpr char BLACK_START = 'a';
constexpr char BLACK_END = 'z';

PieceType get_piece_type(char p) {
	switch(tolower(p)) {
		case PAWN_BLACK: return PAWN;
		case ROOK_BLACK: return ROOK;
		case KNIGHT_BLACK: return KNIGHT;
		case BISHOP_BLACK: return BISHOP;
		case QUEEN_BLACK: return QUEEN;
		case KING_BLACK: return KING;
		default: return NONE;
	}
}

bool is_white(char p) {
	return p >= WHITE_START && p <= WHITE_END;
}

bool is_black(char p) {
	return p >= BLACK_START && p <= BLACK_END;
}