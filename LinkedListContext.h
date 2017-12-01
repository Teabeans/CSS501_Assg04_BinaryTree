// TODO: To get BSTConcordance.cpp working:
// 1) Add == comparison
// 2) Add < comparison
// 3) Add String conversion

// X--------------------------X
// |                          |
// |    INCLUDE STATEMENTS    |
// |                          |
// X--------------------------X

#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include "NodeContext.cpp"

using namespace std;

// This is the data field of a BSTConcordance node
class LinkedListContext {
private:

// X----------------------X
// |                      |
// |    PRIVATE FIELDS    |
// |                      |
// X----------------------X

// TODO: Populate with fields after this is confirmed to work.

// X-----------------------X
// |                       |
// |    PRIVATE METHODS    |
// |                       |
// X-----------------------X

public: // TODO: Divide private and public fields/methods appropriately after testing

// X---------------------X
// |                     |
// |    PUBLIC FIELDS    |
// |                     |
// X---------------------X


NodeContext* currPtr;

NodeContext* headNodePtr;

string keyword; // Inherited from the BSTConcordance node

unsigned int longestPrev;



// X----------------------X
// |                      |
// |    PUBLIC METHODS    |
// |                      |
// X----------------------X

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



// X--------------------------------X
// |                                |
// |    CONSTRUCTORS/DESTRUCTORS    |
// |                                |
// X--------------------------------X

// Default constructor
LinkedListContext();

// Constructor for a head node's keyword and context
LinkedListContext(string someKeyword, string prevContext, string postContext);



// X-------------------------X
// |                         |
// |    GETTERS / SETTERS    |
// |                         |
// X-------------------------X

int getMaxPrevContextLength();

string getPrevContext(NodeContext* currNodePtr) const;

string getPostContext(NodeContext* currNodePtr) const;



// X--------------------------X
// |                          |
// |    OPERATOR OVERLOADS    |
// |                          |
// X--------------------------X




bool LinkedListContext::operator<<(const LinkedListContext& someLinkedList) const;

// #operator< - Custom behavior for the less-than operator
bool LinkedListContext::operator<(const LinkedListContext& someLinkedList) const;

// #operator> - Custom behavior for the less-than operator
bool LinkedListContext::operator>(const LinkedListContext& someLinkedList) const;

// #operator== - Custom behavior for the equality operator
bool LinkedListContext::operator==(const LinkedListContext& someLinkedList) const;

// #operator<< - 
friend ostream& operator<<(ostream& coutStream, LinkedListContext& someLinkedList);
}; // Closing class LinkedListContext

   
