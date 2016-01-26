#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <vector>

class Dictionary {

private:
	// std::string dictionary [267751];
	std::vector<std::string> dictionary;
	int size;

public:

	Dictionary();

	~Dictionary();

	std::string getWord(int i);

	int getSize();

	void eraseWord(int i);

	void print();
};

#endif
