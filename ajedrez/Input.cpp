#include "Input.h"
#include <iostream>

Vector2 read_position() {
	Vector2 pos;

	//TODO Check for [non letter] handeling
	std::cout << "Enter row: ";
	std::cin >> pos.x;
	std::cout << "Enter column: ";
	std::cin >> pos.y;

	pos.x--; pos.y--;
	return pos;
}