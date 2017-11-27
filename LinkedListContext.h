#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include "NodeContext.cpp"

using namespace std;

// This is the data field of a BSTConcordance node
class LinkedListContext {
private:
public: // TODO: Divide private and public fields/methods appropriately after testing

string keyword; // Inherited from the BSTConcordance node
NodeContext* headNodePtr;
NodeContext* currPtr;
int longestPrev;
string contextWords[11];






// #advance() - If currPtr is not the last node, moves currPtr forward one body node per call
void advance();

// #append(string, string) - Adds a new node to the Linked List using the provided contexts
void append(string prevContext, string postContext);

// #isLastNode() - Reports whether the currPtr points to the last body node.
bool isLastNode();


// #reset() - Sets the currPtr back to the head node
void reset();

// #toString() - Outputs the entire linked list as a string
string toString(int prevLength);

// Default constructor
LinkedListContext();

// Constructor for a head node's keyword and context
LinkedListContext(string someKeyword, string prevContext, string postContext);


// Getters
int getMaxPrevContextLength();

string getPrevContext(NodeContext* currNodePtr);

string getPostContext(NodeContext* currNodePtr);

}; // Closing class LinkedListContext
