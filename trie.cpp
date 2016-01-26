#include "trie.h"
#include "node.h"
#include <iostream>
#include <vector>
#include <string>

Trie::Trie()
{
	root = new Node();
}

Trie::~Trie()
{
	delete root;
}

void Trie::addWord(std::string str)
{
	Node* curr = root;

	if(str.length() == 0){
		curr->setMarker();
		return;
	}

	for(unsigned int i = 0; i < str.length(); i++){
		Node* child = curr->findChild(str[i]);
		if(child != NULL){
			curr = child;
		}
		else{
			Node* temp = new Node();
			temp->setValue(str[i]);
			curr->appendChild(temp);
			curr = temp;
		}
		if(i == str.length() - 1){
			curr->setMarker();
		}
	}
}

bool Trie::isPrefix(std::string str)
{
	Node* curr = root;
	while(curr != NULL){
		for(unsigned int i = 0; i < str.length(); i++){
			Node* temp = curr->findChild(str[i]);
			if(temp == NULL){
				return false;
			}
			curr = temp;
		}
		return true;
	}
	return false;

}

bool Trie::searchWord(std::string str)
{
	Node* curr = root;

	while(curr != NULL){
		for(unsigned int i = 0; i < str.length(); i++){
			Node* temp = curr->findChild(str[i]);
			if(temp == NULL){
				return false;
			}
			curr = temp;
		}
		if (curr->getMarker()){
			curr->falseMarker();
			return true;
		}
		else{
			return false;
		}
	}
	return false;
}
