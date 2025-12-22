#pragma once
#include "../Utils/Vector2.h"
#include <ctype.h>

constexpr char WHITE_START = 'A';
constexpr char WHITE_END = 'Z';
constexpr char BLACK_START = 'a';
constexpr char BLACK_END = 'z';

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