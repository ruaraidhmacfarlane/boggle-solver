#include "dice.h"
#include <iostream>
#include <time.h>
#include <vector>


Dice::Dice() : die {"AAAFRS", "AEEGMU", "CEIILT", "DHLNOR", "FIPRSY",
					"AAEEEE", "AEGMNN", "CEILPT", "DHLNOR", "GORRVW", 
					"AAFIRS", "AFIRSY", "CEIPST", "EIIITT", "IPRRRY", 
					"ADENNN", "BJKQXZ", "DDHNOT", "EMOTTT", "NOOTUW", 
					"AEEEEM", "CCENST", "DHHLOR", "ENSSSU", "OOOTTU"}
{

}

char Dice::roll() 
{
	
	int randomDice = rand() % die.size();
	std::string dice = die[randomDice];
	int randomChar = rand() % 6;
	char result = dice[randomChar];
	
    die.erase(next(begin(die), randomDice));
	return result;
}

int Dice::getSize() 
{
	return die.size();
}

void Dice::print() 
{
	for(unsigned int i = 0; i < die.size(); i++){

	}
}