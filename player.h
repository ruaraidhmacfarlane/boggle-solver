#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <fstream>

#include "board.h"
#include "dictionary.h"
#include "board_dimensions.h"
#include "trie.h"

class Player{
private:

	Dictionary wordlist;
	Trie* trie;
	int dictionarySize;

public:

	Player();

	~Player();

	void initTrie();

	void oneWord(std::string word, std::string encoding);

	void listWords(std::string encoding);

	bool checkWord(std::vector<std::vector<char>> board, bool visited[X_SIZE][Y_SIZE], int i, int j,
					 std::string word, unsigned int level);

	void BSBoggle(std::string encoding);

	void BSBoggleRecursion(std::vector<std::vector<char>> board, bool visited[Y_SIZE][Y_SIZE], int i, int j,
							std::string &str, Dictionary * tempWordlist);

	bool foundWord(std::string &str, Dictionary * tempWordlist);

	bool foundPrefix(std::string &str);

	void efficientBoggle(std::string encoding);

	void efficientBoggleRecursion(std::vector<std::vector<char>> board, bool visited[X_SIZE][Y_SIZE], int i, int j,
							std::string &str);

	std::vector<std::vector<char>> decode(std::string encoding);

};
#endif
