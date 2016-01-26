#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>

class Node{

private:

	char value;
    bool marker;
    std::vector<Node*> children;

public:
	
	Node();

	~Node();

	char getValue();

    void setValue(char c);

    bool getMarker();

    void setMarker();

    void falseMarker();

    Node* findChild(char c);

    void appendChild(Node* child);

    std::vector<Node*> getChildren();

};

#endif