#include "../Moves/Moves.h"
#include "../Piece/Piece.h"
#include <cmath> // for std::abs for diagonal moves

bool is_valid_move(const Board* b, Vector2 from, Vector2 to) {
	char piece = b->cells[from.x][from.y];
	PieceType type = get_piece_type(piece);

	switch(type) {
		case PAWN:   return valid_pawn_move(b, from, to, is_white(piece));
		case ROOK:   return valid_rook_move(b, from, to);
		case KNIGHT: return valid_knight_move(b, from, to);
		case BISHOP: return valid_bishop_move(b, from, to);
		case QUEEN:  return valid_queen_move(b, from, to);
		case KING:   return valid_king_move(b, from, to);
		default:     return false;
	}
}

bool valid_pawn_move(const Board* b, Vector2 from, Vector2 to, bool white) {
	short direction = white ? -1 : 1;
	short start_row = white ? 6 : 1;

	short dx = to.x - from.x;
	short dy = to.y - from.y;
	char targetCell = b->cells[to.x][to.y];

	// Normal forward move
	if(dx == direction && dy == 0 && targetCell == EMPTY_CELL)
		return true;

	// Double move from starting row
	if(from.x == start_row && dx == 2 * direction && dy == 0) {
		short mid_x = from.x + direction;
		if(b->cells[mid_x][from.y] == EMPTY_CELL && targetCell == EMPTY_CELL)
			return true;
	}

	// Normal diagonal capture
	if(dx == direction && std::abs(dy) == 1 && targetCell != EMPTY_CELL &&
	   is_white(targetCell) != white)
		return true;

	// En passant
	if(b->enPassant.valid && dx == direction && std::abs(dy) == 1 &&
	   targetCell == EMPTY_CELL) {
		Vector2 ep = b->enPassant.pawnPos;
		if(ep.x == from.x && ep.y == to.y && b->enPassant.pawnIsWhite != white)
			return true;
	}

	return false;
}

bool valid_rook_move(const Board* b, Vector2 from, Vector2 to) {
	if(from.x != to.x && from.y != to.y)
		return false;

	short dx = (to.x - from.x) == 0 ? 0 : (to.x - from.x) / std::abs(to.x - from.x);
	short dy = (to.y - from.y) == 0 ? 0 : (to.y - from.y) / std::abs(to.y - from.y);

	short x = from.x + dx;
	short y = from.y + dy;

	while(x != to.x || y != to.y) {
		if(b->cells[x][y] != EMPTY_CELL)
			return false;
		x += dx;
		y += dy;
	}

	char target = b->cells[to.x][to.y];
	if(target == EMPTY_CELL || is_white(target) != is_white(b->cells[from.x][from.y]))
		return true;

	return false;
}

bool valid_knight_move(const Board* b, Vector2 from, Vector2 to) {
	short dx = std::abs(to.x - from.x);
	short dy = std::abs(to.y - from.y);

	if(!((dx == 2 && dy == 1) || (dx == 1 && dy == 2)))
		return false;

	char target = b->cells[to.x][to.y];
	if(target == EMPTY_CELL || is_white(target) != is_white(b->cells[from.x][from.y]))
		return true;

	return false;
}

bool valid_bishop_move(const Board* b, Vector2 from, Vector2 to) {
	short dx = to.x - from.x;
	short dy = to.y - from.y;

	if(std::abs(dx) != std::abs(dy))
		return false;

	short stepX = (dx > 0) ? 1 : -1;
	short stepY = (dy > 0) ? 1 : -1;

	short x = from.x + stepX;
	short y = from.y + stepY;

	while(x != to.x && y != to.y) {
		if(b->cells[x][y] != EMPTY_CELL)
			return false;
		x += stepX;
		y += stepY;
	}

	char target = b->cells[to.x][to.y];
	if(target == EMPTY_CELL || is_white(target) != is_white(b->cells[from.x][from.y]))
		return true;

	return false;
}

bool valid_queen_move(const Board* b, Vector2 from, Vector2 to) {
	return valid_rook_move(b, from, to) || valid_bishop_move(b, from, to);
}

bool valid_king_move(const Board* b, Vector2 from, Vector2 to) {
	short dx = std::abs(to.x - from.x);
	short dy = std::abs(to.y - from.y);

	if(dx > 1 || dy > 1 || (dx == 0 && dy == 0))
		return false;

	char target = b->cells[to.x][to.y];
	if(target == EMPTY_CELL || is_white(target) != is_white(b->cells[from.x][from.y]))
		return true;

	return false;
}