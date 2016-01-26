#include "board.h"
#include "board_dimensions.h"
#include <iostream>
#include <time.h>
#include <vector>
#include <string>

Board::Board() : board {{0}}
{
	
}

void Board::fill()
{
	int random =-1;
	std::vector<std::string> boardOptions = {"00", "01", "02", "03", "04",
											"10", "11","12", "13", "14",
											"20", "21","22", "23", "24",
											"30", "31","32", "33", "34",
											"40", "41","42", "43", "44"};
	
	int times = boardOptions.size();
	for(int i = 0; i < times; i++){
		char letter = dice.roll();
		random = rand() % boardOptions.size();
		std::string pair = boardOptions[random];
		int x = pair[0] - '0';
		int y = pair[1] - '0';
		//place on board
		board[x][y] = letter;
		boardOptions.erase(next(begin(boardOptions), random));
	}
}

std::string Board::encode()
{
	std::string s;
	for(int i = 0; i < X_SIZE; i++){
		for(int j = 0; j < Y_SIZE; j++){
			s += board[i][j];
		}
	}
	return s;
}

void Board::print()
{
	for(int i = 0; i < X_SIZE; i++){
		for(int j = 0; j < Y_SIZE; j++){
			std::cout << board[i][j] << " ";
		}
		std::cout << std::endl;
	}
}