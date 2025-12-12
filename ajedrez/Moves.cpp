#include "Moves.h"
#include <cmath>

bool is_valid_move(Board* b, Vector2 from, Vector2 to) {
	char p = b->cells[from.x][from.y];
	PieceType t = get_piece_type(p);

	switch(t) {
		case PAWN:   return valid_pawn_move(b, from, to, is_white(p));
		case ROOK:   return valid_rook_move(b, from, to);
		case KNIGHT: return valid_knight_move(b, from, to);
		case BISHOP: return valid_bishop_move(b, from, to);
		case QUEEN:  return valid_queen_move(b, from, to);
		case KING:   return valid_king_move(b, from, to);
		default:     return false;
	}
}