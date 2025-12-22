#include "Board.h"
#include "Input.h"
#include <iostream>
#include <limits>

Vector2 read_position() {
	Vector2 pos;
	bool valid = false;

	while(!valid) {
		std::cout << "Enter row (1-" << BOARD_SIZE << "): ";
		if(!(std::cin >> pos.x)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Numbers only.\n";
			continue;
		}

		std::cout << "Enter column (1-" << BOARD_SIZE << "): ";
		if(!(std::cin >> pos.y)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Numbers only.\n";
			continue;
		}

		if(pos.x < 1 || pos.x > BOARD_SIZE ||
			pos.y < 1 || pos.y > BOARD_SIZE) {
			std::cout << "Position out of range.\n";
			continue;
		}

		valid = true;
	}

	pos.x--;
	pos.y--;
	return pos;
}