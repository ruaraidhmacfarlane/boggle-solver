#include "dice.h"
#include "board.h"
#include "player.h"
#include "dictionary.h"
#include "board_dimensions.h"
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <ctime>

int main(int argc, char* argv[]) 
{
	// Check the number of parameters
    if (argc != 2) {
        // Tell the user how to run the program
        std::cerr << "Usage: " << argv[0] << " (1,2,3)" << std::endl;
        std::cout << "1) Simple Boggle solver" << std::endl;
		std::cout << "2) Binary Search Boggle solver" << std::endl;
		std::cout << "3) Efficient Boggle solver" << std::endl;
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
	if(strcmp(argv[1], "1") == 0)
	{
		std::cout << "Simple Boggle Solver..." << std::endl;
		std::cout << "Please enter word to search for on board: ";
		std::string word;
		std::cin >> word;
		// getline(std::cin, input);
		// stringstream myStream(input);
		// user.oneWord(wordlist.getWord(i), game.encode);
		user.oneWord(word, game.encode());
		// user.listWords(game.encode());

		std::cout << std::endl;
		return 0;
	}
	// Binary Search Boggle
	else if(strcmp(argv[1], "2") == 0)
	{
		std::cout << "Binary Search Boggle Solver..." << std::endl;
		user.BSBoggle(game.encode());

		std::cout << std::endl;
		return 0;
	}
	// Efficient Boggle
	else if(strcmp(argv[1], "3") == 0)
	{
		std::cout << "Efficient Boggle Solver..." << std::endl;
		user.efficientBoggle(game.encode());

		std::cout << std::endl;
		return 0;
	}
	else
	{
		return 1;
	}
}