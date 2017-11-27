#pragma once
#include <iostream>
#include <string>
#include <fstream>

// Node definition
#include "NodeString.cpp"

using namespace std;

class BSTString {

private:

string treeData;

NodeString* rootPtr;
bool insert(string aWord);



bool traversePreOrder();
bool traversePreOrder(NodeString* nodePtr);

bool traverseInOrder();
bool traverseInOrder(NodeString* nodePtr);

bool traversePostOrder();
bool traversePostOrder(NodeString* nodePtr);

void visit(NodeString* thisNodePtr);

public:
// Default constructor
BSTString();

// Constructor from file address
BSTString(string fileAddress);

bool setDelete(string aWord); // Todo: Move to private after confirming this works

NodeString* retrieve(string someValue);
bool find(string someValue);

void printout();

// Getter
string getValue();

string getRootValue();

// Setter
void setValue( string someValue );

};
