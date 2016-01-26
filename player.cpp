#include "player.h"
#include "dictionary.h"
#include "board_dimensions.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

Player::Player()
{
	trie = new Trie();
	dictionarySize = wordlist.getSize();
	//if wanting to initalise the Trie before all the programs or run, run initTrie() here
	//otherwise, run it at the start of efficientBoggle()
	initTrie();
}

Player::~Player()
{
	//frees Trie memory
	delete trie;
	trie = NULL;
}

void Player::initTrie()
{
	//creates the trie from words in dictionary
	for(int i = 0; i < dictionarySize; i++){
		trie->addWord(wordlist.getWord(i));
	}
}

void Player::oneWord(std::string word, std::string encoding)
{
	std::vector<std::vector<char>> board = decode(encoding);
	//holds the previous word, because sometimes there is duplicates
	std::string prev = "";
	//keeps track of visited cells
	bool visited[X_SIZE][Y_SIZE] = {{false}};
	bool found = false;
	//searches the board to find the starting letter of the word being searched for
	for(int i = 0; i < X_SIZE; i++){
		for(int j = 0; j < Y_SIZE; j++){
			if(board[i][j] == word[0]){
				found = checkWord(board, visited, i, j, word, 1);
				if(found){
					std::cout << "YES" << std::endl;
					return;
				}
			}
		}
		if(found){
			break;
		}
	}
	if(!found){
		std::cout << "NO" << std::endl;
	}
}

void Player::listWords(std::string encoding)
{
	std::vector<std::vector<char>> board = decode(encoding);
	std::string prev = "";
	//loops through each word in dictionary
	for(int i = 0; i < dictionarySize; i++){
		//gets the word from the dictionary to search for it
		std::string word = wordlist.getWord(i);
		//keeps track of visited cells
		bool visited[X_SIZE][Y_SIZE] = {{false}};
		bool found = false;
		//searches the board to find the starting letter of the word being searched for
		for(int i = 0; i < X_SIZE; i++){
			for(int j = 0; j < Y_SIZE; j++){
				if(board[i][j] == word[0]){
					found = checkWord(board, visited, i, j, word, 1);
					if(found && word != prev){
						//compares the word to the previous word to check for duplicates,
						//this occurs very rarely
						prev = word;
						std::cout << word << std::endl;
					}
				}
			}
			if(found){
				break;
			}
		}
	}
}

bool Player::checkWord(std::vector<std::vector<char>> board , bool visited[X_SIZE][Y_SIZE], 
						int i, int j, std::string word, unsigned int level)
{
	bool found = false;
	//this cell has been visited in this branch of recursion
	visited[i][j] = true;
	//base case, if word has been found
	if(level == word.length()){
		return true;
	}
	//traverses adjacent cells
	for(int x = i-1; x <= i + 1 && x < X_SIZE; x++){
		for(int y = j-1; y <= j + 1 && y < Y_SIZE; y++){
			if(x >= 0 && y >= 0 && !visited[x][y] && word[level] == board[x][y]){
				found = checkWord(board, visited, x, y, word, level+1);
				if(found){
					break;
				}
			}
		}
		if(found){
			break;
		}
	}
	//if the word cant be made at this adjacent square set it not being visted so if it is needed later in the word
	//it can be used.
	visited[i][j] = false;
	return found;
}

void Player::BSBoggle(std::string encoding)
{
	std::vector<std::vector<char>> board = decode(encoding);
	Dictionary * tempWordlist = new Dictionary();
	bool visited[X_SIZE][Y_SIZE] = {{false}};
	//the sting that is being generated by the board
	std::string str = "";
	//goes through the board and generates a word starting from here
	for(int i = 0; i < X_SIZE; i++){
		for(int j = 0; j < Y_SIZE; j++){
			BSBoggleRecursion(board, visited, i, j, str, tempWordlist);
		}
	}
	//free memory
	delete tempWordlist;
	tempWordlist = NULL;
}

void Player::BSBoggleRecursion(std::vector<std::vector<char>> board, bool visited[X_SIZE][Y_SIZE], int i, int j,
							std::string &str, Dictionary * tempWordlist)
{
	visited[i][j] = true;
	//adds the current char to the string being generated
	str += board[i][j];
	//base case
	//checks for prefix, if it isnt a prefix, no point search future possibilites in this branch so returns out
	if(!foundPrefix(str)){
		str.erase(str.length()-1);
		visited[i][j] = false;
		return;
	}
	//base case, if word is found then print it, continue searching though, there maybe words that have this prefix
	if(foundWord(str, tempWordlist)){
		std::cout << str << std::endl;
	}
	//traverses adjacent cells
	for(int x = i-1; x <= i + 1 && x < X_SIZE; x++){
		for(int y = j-1; y <= j + 1 && y < Y_SIZE; y++){
			if(x >= 0 && y >= 0 && !visited[x][y]){
				BSBoggleRecursion(board, visited, x, y, str, tempWordlist);
			}
		}
	}
	//if word isnt found remove the latest character added on the string so recursion can search other possibilites
	str.erase(str.length()-1);
	//later on in the recursion this square can be visited again
	visited[i][j] = false;
}

bool Player::foundWord(std::string &str, Dictionary *tempWordlist)
{
	int lo = 0,
   		hi = wordlist.getSize() - 1,
    	mid;
    bool found = false;
 
    while (!found && lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (tempWordlist->getWord(mid) == str)
        {
            found = true;
           	tempWordlist->eraseWord(mid);
        }
        else if (tempWordlist->getWord(mid) > str)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return found;	
}

bool Player::foundPrefix(std::string &str)
{
	long lo = 0,
   		hi = wordlist.getSize() - 1,
    	mid;

    bool found = false;
 	unsigned int len = str.length();
    while (!found && lo <= hi)
    {
        mid = (lo + hi) / 2;
        //because im comparing prefixes I cant compare a prefix if the dictionary word is smaller than the prefix,
        //this will segfault so I have to change the mid pointer to a word that is the right size for the prefix.
		while(wordlist.getWord(mid).length() <= len){
	       	if(wordlist.getWord(mid) == str){
	       		return true;
	       	}
			
			if(mid ==  hi){
				return false;
			}
			else if(wordlist.getWord(mid) > str){
				hi = mid--;
			}
			else{
				lo = mid++;
			}
		}
		//otherwise just binary search as normal
        if (wordlist.getWord(mid).substr(0,len) == str.substr(0,len)){
            found = true;
        }
        else if (wordlist.getWord(mid).substr(0,len) > str.substr(0,len)){
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    return found;
}

void Player::efficientBoggle(std::string encoding)
{
	//initalise Trie here if wanting to only put it memory when running this function, not the whole program.
	// initTrie();
	std::vector<std::vector<char>> board = decode(encoding);
	bool visited[X_SIZE][Y_SIZE] = {{false}};
	std::string str = "";
	for(int i = 0; i < X_SIZE; i++){
		for(int j = 0; j < Y_SIZE; j++){
			efficientBoggleRecursion(board, visited, i, j, str);
		}
	}
}

void Player::efficientBoggleRecursion(std::vector<std::vector<char>> board, bool visited[X_SIZE][Y_SIZE], int i, int j,
							std::string &str)
{
	visited[i][j] = true;
	str += board[i][j];
	//base case if not prefix, so it can return out of the branch of recursion
	if(!trie->isPrefix(str)){
		str.erase(str.length()-1);
		visited[i][j] = false;
		return;
	}
	//base case if word is found
	if(trie->searchWord(str)){
		std::cout << str << std::endl;
	}
	//traverses adjacent cells
	for(int x = i-1; x <= i + 1 && x < X_SIZE; x++){
		for(int y = j-1; y <= j + 1 && y < Y_SIZE; y++){
			if(x >= 0 && y >= 0 && !visited[x][y]){
				efficientBoggleRecursion(board, visited, x, y, str);
			}
		}
	}
	
	str.erase(str.length()-1);
	visited[i][j] = false;
}
//used to print
std::vector<std::vector<char>> Player::decode(std::string encoding)
{
	std::vector<std::vector<char>> array2D (X_SIZE, std::vector<char>(Y_SIZE));
	int k = 0;
	for (int i = 0; i < X_SIZE; i++){
        for (int j = 0; j < Y_SIZE; j++)
        {
			array2D.at(i).at(j) = encoding[k];
			k++;
		}
	}
	return array2D;
}