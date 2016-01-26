#include "dice.h"
#include "board.h"
#include "player.h"
#include "dictionary.h"
#include "board_dimensions.h"
#include <iostream>
#include <string>
#include <cstring>
#include <ctime>

int main(int argc, char* argv[]) 
{
	// Check the number of parameters
    if (argc > 2) {
        // Tell the user how to run the program
        std::cerr << "Usage: " << argv[0] << " NAME" << std::endl;
        /* "Usage messages" are a conventional way of telling the user
         * how to run a program if they enter the command incorrectly.
         */
        return 1;
    }
	//for random to work
	srand(time(NULL));
	std::cout << std::endl;

	Board game;
	//randomly generates board
	game.fill();
	//prints the randomly generated board
	game.print();

	Player user;

	// Simple Boggle
	if(strcmp(argv[0], "1") == 0)
	{
		// user.oneWord(wordlist.getWord(i), game.encode);
		user.listWords(game.encode());

		std::cout << std::endl;
		return 0;
	}
	// Binary Search Boggle
	else if(strcmp(argv[0], "2") == 0)
	{
		user.BSBoggle(game.encode());

		std::cout << std::endl;
		return 0;
	}
	// Efficient Boggle
	else if(strcmp(argv[0], "3") == 0)
	{
		user.efficientBoggle(game.encode());

		std::cout << std::endl;
		return 0;
	}
	else
	{
		return 1;
	}
}