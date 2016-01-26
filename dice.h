#ifndef DICE_H
#define DICE_H

#include <iostream>
#include <vector>
#include <string>
class Dice {

private:
	std::vector<std::string> die;

public:
	Dice();

	char roll();
	
	//for testing
	int getSize();

	void print();
};

#endif
