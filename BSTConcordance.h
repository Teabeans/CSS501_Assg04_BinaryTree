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
#include "NodeGeneric.cpp" // For a generic (BST) node

using namespace std;

template <class typeT>
class BSTGeneric {

private:

public: // TODO - Relocate to public region after function is guaranteed

// X----------------------X
// |                      |
// |    PRIVATE FIELDS    |
// |                      |
// X----------------------X

// #treeData - Tree name, for debug purposes
string BSTGeneric<typeT>::treeData;

NodeGeneric<typeT>* BSTGeneric<typeT>::rootPtr;


// X-----------------------X
// |                       |
// |    PRIVATE METHODS    |
// |                       |
// X-----------------------X

// #deletePostOrder() -
bool deletePostOrder();
bool deletePostOrder(NodeGeneric<typeT>* nodePtr);

// #insert(string) -
bool insert(typeT& someData); // Gets passed a LLC by reference

// #obliviate() - Deletes all nodes within the BST, leaving headPtr pointing at nullptr
void obliviate();

// #setDelete() -
bool setDelete(typeT someData);

// #traversePreOrder() - Helper method
bool traversePreOrder();
bool traversePreOrder(NodeGeneric<typeT>* nodePtr);

// #traverseInOrder() - Helper method
bool traverseInOrder();
bool traverseInOrder(NodeGeneric<typeT>* nodePtr);

// #traversePostOrder() - Helper method
bool traversePostOrder();
bool traversePostOrder(NodeGeneric<typeT>* nodePtr);

void visit(NodeGeneric<typeT>* thisNodePtr);



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

// #retrieve() - 
// NodeGeneric<typeT>* retrieve(typeT someData);



// X--------------------------------X
// |                                |
// |    CONSTRUCTORS/DESTRUCTORS    |
// |                                |
// X--------------------------------X

// Default constructor
BSTGeneric();

// Constructor from file address
BSTGeneric(string fileAddress);

// Constructor from a node data object
// BSTGeneric(typeT someData, int signature);

// Default destructor
~BSTGeneric();



// X-------------------------X
// |                         |
// |    GETTERS / SETTERS    |
// |                         |
// X-------------------------X

// #getRootValue() - 
typeT& getRootValue();

// #getValue() - 
string getValue();

// #setValue() - 
void setValue( string someValue );

};
