#pragma once
#include "Board.h"

bool is_valid_move(Board* b, Vector2 from, Vector2 to);
bool valid_pawn_move(Board* b, Vector2 from, Vector2 to, bool white);
bool valid_rook_move(Board* b, Vector2 from, Vector2 to);
bool valid_knight_move(Board* b, Vector2 from, Vector2 to);
bool valid_bishop_move(Board* b, Vector2 from, Vector2 to);
bool valid_queen_move(Board* b, Vector2 from, Vector2 to);
bool valid_king_move(Board* b, Vector2 from, Vector2 to);
