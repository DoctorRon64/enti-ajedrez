#include "../Board/Board.h"
#include "Input.h"
#include <iostream>
#include <limits>

Vector2 read_position(const std::string& prompt) {
	Vector2 pos;
	bool valid = false;

	while(!valid) {
		std::cout << prompt << " (row col, 1-" << BOARD_SIZE << " 1-" << BOARD_SIZE << "): ";
		if(!(std::cin >> pos.x >> pos.y)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Numbers only.\n";
			continue;
		}

		if(pos.x < 1 || pos.x > BOARD_SIZE || pos.y < 1 || pos.y > BOARD_SIZE) {
			std::cout << "Position out of range. Try again.\n";
			continue;
		}

		valid = true;
	}

	pos.x--;
	pos.y--;
	return pos;
}

MoveInput read_move() {
	MoveInput move;
	move.from = read_position("Enter FROM position");
	move.to = read_position("Enter TO position");
	return move;
}