// X--------------------------X
// |                          |
// |    INCLUDE STATEMENTS    |
// |                          |
// X--------------------------X

#pragma once
#include <iostream>
#include <string>
#include <fstream>

// Node definition
#include "NodeString.cpp" // For a string BST
#include "NodeContext.cpp" // For a context linked list
#include "NodeConcordance.cpp" // For a concordance BST

using namespace std;

class BSTConcordance {

private:

public: // TODO - Relocate to public region after function is guaranteed

// X----------------------X
// |                      |
// |    PRIVATE FIELDS    |
// |                      |
// X----------------------X

string someField;

string TreeData;

NodeConcordance* rootPtr;



// X-----------------------X
// |                       |
// |    PRIVATE METHODS    |
// |                       |
// X-----------------------X

// #insert(string) -
bool insert(LinkedListContext someLinkedList);

// #setDelete() -
bool setDelete(LinkedListContext someLinkedList);

// #traversePreOrder() - Helper method
bool traversePreOrder();
bool traversePreOrder(NodeConcordance* nodePtr);

// #traverseInOrder() - Helper method
bool traverseInOrder();
bool traverseInOrder(NodeConcordance* nodePtr);

// #traversePostOrder() - Helper method
bool traversePostOrder();
bool traversePostOrder(NodeConcordance* nodePtr);

void visit(NodeConcordance* thisNodePtr);



// X---------------------X
// |                     |
// |    PUBLIC FIELDS    |
// |                     |
// X---------------------X

// None



// X----------------------X
// |                      |
// |    PUBLIC METHODS    |
// |                      |
// X----------------------X


// #find(string) - Finds a node with value of string
bool find(string someValue);

// #printout() - Debug method to print out the nodes in pre-, in-, and post-order traversals
void printout();

// #readin(string) - Reads a file in from a file location
void readin(string fileLocation);

// #retrieve() - 
NodeConcordance* retrieve(LinkedListContext someValue);



// X--------------------------------X
// |                                |
// |    CONSTRUCTORS/DESTRUCTORS    |
// |                                |
// X--------------------------------X

// Default constructor
BSTConcordance();

// Constructor from file address
BSTConcordance(string fileAddress);



// X-------------------------X
// |                         |
// |    GETTERS / SETTERS    |
// |                         |
// X-------------------------X

// #getRootValue() - 
LinkedListContext& getRootValue();

// #getValue() - 
string getValue();

// #setValue() - 
void setValue( string someValue );

};
