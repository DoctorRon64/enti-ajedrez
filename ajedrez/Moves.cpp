#include "Moves.h"
#include "Piece.h"
#include <cmath> //used for diagonal calc

bool is_valid_move(Board* b, Vector2 from, Vector2 to) {
	char target = b->cells[to.x][to.y];
	PieceType type = get_piece_type(target);

	switch(type) {
		case PAWN: return valid_pawn_move(b, from, to, is_white(target));
		case ROOK:   return valid_rook_move(b, from, to);
		case KNIGHT: return valid_knight_move(b, from, to);
		case BISHOP: return valid_bishop_move(b, from, to);
		case QUEEN:  return valid_queen_move(b, from, to);
		case KING:   return valid_king_move(b, from, to);
		default:     return false;
	}
}

//bool is_valid_move(Board* b, Vector2 from, Vector2 to) {
//	char p = b->cells[from.x][from.y];
//	PieceType t = get_piece_type(p);
//
//	switch(t) {
//		case PAWN: return valid_pawn_move(b, from, to, is_white(p));
//		default:   return false;
//	}
//}

bool valid_pawn_move(Board* b, Vector2 from, Vector2 to, bool white) {
	int direction = white ? -1 : 1;
	int start_row = white ? 6 : 1;

	int dx = to.x - from.x;
	int dy = to.y - from.y;

	char targetCell = b->cells[to.x][to.y];

	if(dx == direction && dy == 0) {
		if(targetCell == EMPTY_CELL) {
			return true;
		}

		return false;
	}

	if(from.x == start_row && dx == 2 * direction && dy == 0) {
		int mid_x = from.x + direction;

		if(b->cells[mid_x][from.y] == EMPTY_CELL && targetCell == EMPTY_CELL) {
			return true;
		}

		return false;
	}

	if(dx == direction && std::abs(dy) == 1) {
		if(targetCell != EMPTY_CELL && is_white(targetCell) != white)
			return true;

		return false;
	}

	return false;
}

bool valid_rook_move(Board* b, Vector2 from, Vector2 to) {
	int dx = to.x - from.x;
	int dy = to.y - from.y;

	// 1. Solo recto
	if (dx != 0 && dy != 0)
		return false;

	// 2. Dirección
	int directX = (dx > 0) ? 1 : (dx < 0) ? -1 : 0;
	int directY = (dy > 0) ? 1 : (dy < 0) ? -1 : 0;

	// 3. Revisar camino
	int x = from.x + directX;
	int y = from.y + directY;

	while (x != to.x || y != to.y) {
		if (b->cells[x][y] != EMPTY_CELL)
			return false;
		x += directX;
		y += directY;
	}

	// 4. Destino
	char src = b->cells[from.x][from.y];
	char dst = b->cells[to.x][to.y];

	return dst == EMPTY_CELL || is_white(dst) != is_white(src);
}

bool valid_knight_move(Board* b, Vector2 from, Vector2 to) {
	//TODO
	return false;
}

bool valid_bishop_move(Board* b, Vector2 from, Vector2 to) {
	//TODO
	return false;
}

bool valid_queen_move(Board* b, Vector2 from, Vector2 to) {
	//TODO
	return false;
}

bool valid_king_move(Board* b, Vector2 from, Vector2 to) {
	//TODO
	return false;
}