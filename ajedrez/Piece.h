#pragma once
#include "Vector2.h"
#include <ctype.h>

enum PieceType {
	PAWN,
	ROOK,
	KNIGHT,
	BISHOP,
	QUEEN,
	KING,
	NONE
};

struct Piece {
	char visual;
	bool isWhite;
	Vector2 pos;
};

PieceType get_piece_type(char p);
bool is_white(char p);
bool is_black(char p);