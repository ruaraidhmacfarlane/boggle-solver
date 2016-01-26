#ifndef BOARD_H
#define BOARD_H

#include <iostream>

#include "dice.h"
#include "board_dimensions.h"

class Board {
 
private:
	char board [X_SIZE][Y_SIZE];
	Dice dice;

public:

	Board();

	void fill();

	std::string encode();

	void print();

};
#endif
