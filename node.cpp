#include "node.h"
#include <iostream>
#include <vector>

	
Node::Node()
{
	value = ' ';
	marker = false;
}

Node::~Node()
{
	for(unsigned int i = 0; i < this->getChildren().size(); i++){
		delete this->getChildren().at(i);
	}
}

char Node::getValue()
{
	return value;
}

void Node::setValue(char c)
{
	value = c;
}

bool Node::getMarker()
{
	return marker;
}

void Node::setMarker()
{
	marker = true;
}

void Node::falseMarker()
{
	marker = false;
}

Node* Node::findChild(char c)
{
	for(unsigned int i = 0; i < children.size(); i ++){
		Node* temp = children.at(i);
		if(temp->getValue() == c){
			return temp;
		}
	}
	return NULL;
}

void Node::appendChild(Node* child)
{
	children.push_back(child);
}

std::vector<Node*> Node::getChildren()
{
	return children;
}