// X--------------------------X
// |                          |
// |    INCLUDE STATEMENTS    |
// |                          |
// X--------------------------X

#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include "LinkedListContext.h"
#include "NodeContext.cpp"

using namespace std;

//class LinkedListContext {
//private:

// X----------------------X
// |                      |
// |    PRIVATE FIELDS    |
// |                      |
// X----------------------X

string keyword;

NodeContext* headNodePtr;

NodeContext* currPtr;

int longestPrev;

string contextWords[11];



// X-----------------------X
// |                       |
// |    PRIVATE METHODS    |
// |                       |
// X-----------------------X

// #reset() - Sets the current node pointer to the head node
void LinkedListContext::reset() {
   currPtr = headNodePtr; // TODO - Confirm this assignment works
}

// #isLastNode() - Reports whether the currPtr points to the last body node.
bool LinkedListContext::isLastNode() {
   // If the nextPtr is off the end of the linked list...
   if (currPtr->nextPtr == nullptr) {
      // This is the last node
      return(true);
   }
   // Otherwise, it isn't.
   return(false);
}



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

// #advance() - If currPtr is not the last node, moves currPtr forward one body node per call.
void LinkedListContext::advance() {
   if (isLastNode() == false) {
      currPtr = currPtr->nextPtr;
   }
   else {
      cout << "Error: Cannot advance. This is the last node." << endl;
   }
}

// #append(string, string) - Adds a new node to the Linked List using the provided contexts and updates the maximum prev context length
void LinkedListContext::append(string prevContext, string postContext){
   this->reset();
   // Move to the end of the linked list
   while (!this->isLastNode()) {
      this->advance();
   } // currPtr now points at the last node
   // Append a new node with the provided contexts
   currPtr->nextPtr = new NodeContext(prevContext, postContext);
   // Check the length and remember the longer one
   if (prevContext.length() > this->longestPrev) {
      longestPrev = prevContext.length();
   }
} // End append

// #toString() - Outputs the entire linked list as a string
string LinkedListContext::toString(int prevLength) {
   string retString;
   // Starting at the first node...
   this->reset();
   // Append the context, keyword, and context to the return string
   retString = retString + currPtr->prevContext + " " + keyword + " " + currPtr->postContext + "\n";
   // And while we haven't run off the end of the list...
   while (!this->isLastNode()) {
      // Move forward one node
      this->advance();
      // And repeat
      retString = retString + currPtr->prevContext + " " + keyword + " " + currPtr->postContext + "\n";
   }
   return(retString);
}



// X--------------------------------X
// |                                |
// |    CONSTRUCTORS/DESTRUCTORS    |
// |                                |
// X--------------------------------X

// Default constructor - Note, should never be called
LinkedListContext::LinkedListContext() {
   currPtr = nullptr;
}

// #LinkedListContext(string, string, string) - Makes a context linked list with a keyword and head node
LinkedListContext::LinkedListContext(string someKeyword, string prevContext, string postContext) {
   keyword = someKeyword;
   headNodePtr = new NodeContext(prevContext, postContext);
   currPtr = headNodePtr;
   longestPrev = prevContext.length();
}



// X-------------------------X
// |                         |
// |    GETTERS / SETTERS    |
// |                         |
// X-------------------------X

// #getMaxPrevContextLength() - Returns the maximum context length in this linked list
int LinkedListContext::getMaxPrevContextLength() {
   // Iterate over the linked list and return the highest number
   return(longestPrev);
}

// #getPrevContext() - Returns the previous context of the current node
string LinkedListContext::getPrevContext(NodeContext* currNodePtr) {
   return(currNodePtr->prevContext);
}

// #getPostContext() - Returns the post context of the current node
string LinkedListContext::getPostContext(NodeContext* currNodePtr) {
      return(currNodePtr->postContext);
}
