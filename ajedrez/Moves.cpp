#define directX 1
#define directY -1
#include "Moves.h"
#include "Piece.h"
#include <cmath> //used for diagonal calc

bool is_valid_move(Board* b, Vector2 from, Vector2 to) {
	char p = b->cells[from.x][from.y];
	PieceType t = get_piece_type(p);

	switch(t) {
		case PAWN: return valid_pawn_move(b, from, to, is_white(p));
		case ROOK:   return valid_rook_move(b, from, to);
		case KNIGHT: return valid_knight_move(b, from, to);
		case BISHOP: return valid_bishop_move(b, from, to);
		case QUEEN:  return valid_queen_move(b, from, to);
		case KING:   return valid_king_move(b, from, to);
		default:     return false;
	}
}

bool valid_pawn_move(Board* b, Vector2 from, Vector2 to, bool white) {
	short direction = white ? -1 : 1;
	short start_row = white ? 6 : 1;

	short dx = to.x - from.x;
	short dy = to.y - from.y;

	char targetCell = b->cells[to.x][to.y];

	if(dx == direction && dy == 0) {
		if(targetCell == EMPTY_CELL) {
			return true;
		}

		return false;
	}

	if(from.x == start_row && dx == 2 * direction && dy == 0) {
		short mid_x = from.x + direction;

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
	if (from.x != to.x && from.y != to.y)
		return false;
	short DirectX = 0;
	short DirectY = 0;
	if (to.x > from.x)
		DirectX = 1;
	else if (to.x < from.x)
		DirectX = -1;
	if (to.y > from.y)
		DirectY = 1;
	else if (to.y < from.y)
		DirectY = -1;
	short x = from.x + DirectX;
	short y = from.y + DirectY;
	while (x != to.x || y != to.y) {
		if (b->cells[x][y] != EMPTY_CELL)
			return false;
		x = x + DirectX;
		y = y + DirectY;
	}
	char target = b->cells[to.x][to.y];
	if (target == EMPTY_CELL)
		return	true;
	if (is_white(target) != is_white(b->cells[from.x][from.y]))
		return true;
	return false;
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