#define directX 1
#define directY -1

#include "../Moves/Moves.h"
#include "../Piece/Piece.h"
#include <cmath> //used for diagonal calc

bool is_valid_move(Board* b, Vector2 from, Vector2 to) {
	char piece = b->cells[from.x][from.y];
	PieceType type = get_piece_type(piece);

	switch(type) {
		case PAWN: return valid_pawn_move(b, from, to, is_white(piece));
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
	// if the player tries to move in diagonal it returns
	if(from.x != to.x && from.y != to.y)
		return false;
	// values for directions
	short DirectX = 0;
	short DirectY = 0;
	// If the value of to.x is under from it will go +1, ifnot it will go -1 for x and y axis
	if(to.x > from.x)
		DirectX = 1;
	else if(to.x < from.x)
		DirectX = -1;
	if(to.y > from.y)
		DirectY = 1;
	else if(to.y < from.y)
		DirectY = -1;
	// it locks de piece in the new spot after the direction is chosen
	short x = from.x + DirectX;
	short y = from.y + DirectY;
	// The loop keeps going until the piece is in its valid position
	while(x != to.x || y != to.y) {
		// if makes ->cells to check if the piece is going through another piece, if it does it returns
		if(b->cells[x][y] != EMPTY_CELL)
			return false;
		// it goes forward towards the player's position
		x = x + DirectX;
		y = y + DirectY;
	}
	// it targets the piece inside its desired position
	char target = b->cells[to.x][to.y];
	// it checks if there isn't any piece on the position
	if(target == EMPTY_CELL)
		return	true;
	// it checks the piece color and which piece color is moving
	if(is_white(target) != is_white(b->cells[from.x][from.y]))
		return true;
	return false;
}

bool valid_knight_move(Board* b, Vector2 from, Vector2 to) {
	// adding absolut values to dx and dy for knight jumps
	short dx = std::abs(to.x - from.x);
	short dy = std::abs(to.y - from.y);
	// this makes that the movement of the knight is only L shaped, only letting it go 2x,1y or 1x,2y
	if(!((dx == 2 && dy == 1) || (dx == 1 && dy == 2)))
		return false;
	// it targets the piece inside its desired position
	char target = b->cells[to.x][to.y];
	// it checks if there isn't any piece on the position
	if(target == EMPTY_CELL)
		return true;
	// it checks the piece color and which piece color is moving
	if(is_white(target) != is_white(b->cells[from.x][from.y]))
		return true;
	return false;
}

bool valid_bishop_move(Board* b, Vector2 from, Vector2 to) {
	// calcs how many squares does it move
	short dx = to.x - from.x;
	short dy = to.y - from.y;
	// abs value is always the same only counting distance and makes it go in diagonal ifnot it returns, example: (5,3 -> 4,2)
	if(std::abs(dx) != std::abs(dy))
		return false;
	// calcs movement direction
	short DirectX;
	short DirectY;
	// show which direction is the piece moving towards to
	if(dx > 0)
		DirectX = 1;
	else
		DirectX = -1;
	if(dy > 0)
		DirectY = 1;
	else
		DirectY = -1;
	// it locks de piece in the new spot after the direction is chosen
	short x = from.x + DirectX;
	short y = from.y + DirectY;
	// The loop keeps going until the piece is in its valid position
	while(x != to.x || y != to.y) {
		// if makes ->cells to check if the piece is going through another piece, if it does it returns
		if(b->cells[x][y] != EMPTY_CELL)
			return false;
		// it goes forward towards the plaer's position
		x = x + DirectX;
		y = y + DirectY;
	}
	// it targets the piece inside its desired position
	char target = b->cells[to.x][to.y];
	// it checks if there isn't any piece on the position
	if(target == EMPTY_CELL)
		return true;
	// it checks the piece color and which piece color is moving
	if(is_white(target) != is_white(b->cells[from.x][from.y]))
		return true;
	return false;
}

bool valid_queen_move(Board* b, Vector2 from, Vector2 to) {
	// the queen moves as a bishop and a tower at the same time, so this applies that every time the queen is able to move as a bishop or a rook it is available to move
	if(valid_bishop_move(b, from, to))
		return true;
	// rook variable
	if(valid_rook_move(b, from, to))
		return true;
	return false;
}

bool valid_king_move(Board* b, Vector2 from, Vector2 to) {
	// calcs the movement with absolut values for distance making it able to go in diagonal
	short dx = std::abs(to.x - from.x);
	short dy = std::abs(to.y - from.y);
	// this makes the king unable to not move when selected
	if(dx == 0 && dy == 0)
		return false;
	// this makes the king unable to move more than 1 square further in any angle
	if(dx > 1 || dy > 1)
		return false;
	// it targets the piece inside its desired position
	char target = b->cells[to.x][to.y];
	// it checks if there isn't any piece on the position
	if(target == EMPTY_CELL)
		return true;
	// it checks the piece color and which piece color is moving
	if(is_white(target) != is_white(b->cells[from.x][from.y]))
		return true;
	return false;
}