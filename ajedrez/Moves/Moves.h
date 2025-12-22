#pragma once
#include "../Board/Board.h"

bool is_valid_move(const Board* b, Vector2 from, Vector2 to);
bool valid_pawn_move(const Board* b, Vector2 from, Vector2 to, bool white);
bool valid_rook_move(const Board* b, Vector2 from, Vector2 to);
bool valid_knight_move(const Board* b, Vector2 from, Vector2 to);
bool valid_bishop_move(const Board* b, Vector2 from, Vector2 to);
bool valid_queen_move(const Board* b, Vector2 from, Vector2 to);
bool valid_king_move(const Board* b, Vector2 from, Vector2 to);