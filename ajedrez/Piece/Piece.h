#pragma once
#include "../Utils/Vector2.h"

enum PieceType {
	PAWN,
	ROOK,
	KNIGHT,
	BISHOP,
	QUEEN,
	KING,
	NONE
};

constexpr char WHITE_START = 'A';
constexpr char WHITE_END = 'Z';
constexpr char BLACK_START = 'a';
constexpr char BLACK_END = 'z';

struct Piece {
	char visual;
	bool isWhite;
	Vector2 pos;
};

// Get the type of a piece character
PieceType get_piece_type(char p);

// Check piece color
bool is_white(char p);
bool is_black(char p);
