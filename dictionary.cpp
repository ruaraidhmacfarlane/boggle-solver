#include "dictionary.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

Dictionary::Dictionary()
{
	std::ifstream file ("Wordlist.txt");
    std::string str; 
    while (std::getline(file, str))
    {
        dictionary.push_back(str);
    }
    size = 267751;
    file.close();
}

Dictionary::~Dictionary()
{
	
}

std::string Dictionary::getWord(int i)
{
	return dictionary.at(i);
}

int Dictionary::getSize()
{
	return size;
}

void Dictionary::eraseWord(int i){
	dictionary.erase(dictionary.begin() + i);
}

void Dictionary::print()
{
	for(int i = 0; i < size; i++){
		std::cout<< dictionary.at(i) << std::endl;
	}
}