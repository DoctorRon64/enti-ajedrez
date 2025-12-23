#pragma once
#include "../Utils/Vector2.h"
#include <string>

struct MoveInput {
	Vector2 from;
	Vector2 to;
};

Vector2 read_position(const std::string& prompt);
MoveInput read_move();