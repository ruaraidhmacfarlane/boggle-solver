#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include "node.h"

class Trie{

private:

	Node* root;

public:

	Trie();

    ~Trie();

    void addWord(std::string str);

    bool isPrefix(std::string str);

    bool searchWord(std::string str);

};
#endif
