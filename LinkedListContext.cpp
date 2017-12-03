// X--------------------------X
// |                          |
// |    INCLUDE STATEMENTS    |
// |                          |
// X--------------------------X

#pragma once

#include <iostream>
#include <string>
// #include <fstream>

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

// #formatLength - Variable that informs the output formatting
int LinkedListContext::formatLength;
int LinkedListContext::keywordFormatLength;

// Do not reinitialize in .cpp file

// NodeContext* currPtr;

// NodeContext* headNodePtr;

// string keyword;

// int longestPrev;



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



// X----------------------X
// |                      |
// |    PUBLIC METHODS    |
// |                      |
// X----------------------X

// X------------------X
// |    #advance()    |
// X------------------X
// If currPtr is not the last node, moves currPtr forward one body node per call.
void LinkedListContext::advance() {
   if (isLastNode() == false) {
      currPtr = currPtr->nextPtr;
   }
   else {
      cout << "Error: Cannot advance. This is the last node." << endl;
   }
}

// X-------------------------------X
// |    #append(string, string)    |
// X-------------------------------X
// Adds a new node to the Linked List using the provided contexts and updates the maximum prev context length
void LinkedListContext::append(string prevContext, string postContext){
   this->reset();
   // Move to the end of the linked list
   while (!this->isLastNode()) {
      this->advance();
   } // currPtr now points at the last node
   // Append a new node with the provided contexts
   currPtr->nextPtr = new NodeContext(prevContext, postContext);
   // Set an updated formatLength
   if (prevContext.length() > formatLength) {
      formatLength = prevContext.length();
   }
} // End append

// X-------------------X
// |    #toString()    |
// X-------------------X
// Outputs the entire linked list as a string
string LinkedListContext::toString() {
   // cout << "LLC toString() called! formatLength: " << formatLength << endl; // DEBUG
   // #reString - The return string
   string retString = "";
   // #gap - Gap between previous context, keyword, and post context
   string gap = "  ";
   // #pad - Number of spaces needed to pad out the previous context
   string pad = "";
   // #keypad - Number of spaces needed to pad out the previous context
   string keypad = "";

   // Starting at the first node...
   this->reset();
   // Determine the pad width
   for (int i = 0 ; i < (formatLength - currPtr->lengthOfPrevContext) ; i++) {
      pad = pad + " ";
   }
   // determine the keypad width (only needs to be done once per LinkedListContext, since all keywords should be the same
   for (int i = 0 ; i < (keywordFormatLength - this->keyword.length()) ; i++) {
      keypad = keypad + " ";
   }

   // Append the pad, context, gap, keyword, keyword gap, gap, context, and a line break to the return string
   retString = retString+ pad + currPtr->prevContext + gap + keyword + keypad + gap + currPtr->postContext + "\n";

   // And while we haven't run off the end of the list...
   while (!this->isLastNode()) {
      // Move forward one node
      this->advance();
      // And repeat
      // Reset the pads
      pad = "";
      // Redetermine the pad width
      for (int i = 0 ; i < (LinkedListContext::formatLength - currPtr->lengthOfPrevContext) ; i++) {
         pad = pad + " ";
      }
      // Append the pad, context, gap, keyword, keywordgap, gap, context, and a line break to the return string
      retString = retString + pad + currPtr->prevContext + gap + keyword + keypad + gap + currPtr->postContext + "\n";
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
   keyword = "Linked List Context, Default Constructor, null value.";
   currPtr = nullptr;
   headNodePtr = new NodeContext();
}

// #LinkedListContext(string, string, string) - Makes a context linked list with a keyword and head node
LinkedListContext::LinkedListContext(string prevContext, string someKeyword, string postContext) {
   keyword = someKeyword;
   // Update the maximum observed keyword length
   if (keyword.length() > keywordFormatLength) {
      keywordFormatLength = keyword.length();
   }
   headNodePtr = new NodeContext(prevContext, postContext);
   currPtr = headNodePtr;
   if (headNodePtr->lengthOfPrevContext > LinkedListContext::formatLength) {
      LinkedListContext::formatLength = headNodePtr->lengthOfPrevContext;
   } // Ensures that the formatLength will be equal to the longest observed prevContext length
}

// #~LinkedListContext() - Destructor
LinkedListContext::~LinkedListContext() {
   cout << "Destructo Presto!" << endl; // DEBUG
   NodeContext* prevNodePtr = this->headNodePtr;
   // While a body node still exists...
   this->currPtr = this->headNodePtr;
   while (this->headNodePtr->nextPtr != nullptr) {
      // Advance to the end
      while (this->currPtr->nextPtr != nullptr) {

         prevNodePtr = this->currPtr;
         this->advance();
         //cout << "Crossing over " << this->currPtr->prevContext << ":" << this->currPtr->postContext << endl; // DEBUG
      } // Closing while loop, curr points to last node, prev points to second to last
      cout << "Deallocating " << this->currPtr->prevContext << ":" << this->currPtr->postContext << endl; // DEBUG
      // And delete it
      delete this->currPtr;
      // And remove the previous pointer
      prevNodePtr->nextPtr = nullptr;
      this->currPtr = this->headNodePtr;
      prevNodePtr = this->headNodePtr;
   } // Body nodes are all deleted
   cout << "Deleting Head Node: " << endl; // DEBUG
   cout << "Deallocating " << this->headNodePtr->prevContext << ":" << this->headNodePtr->postContext << endl;
   delete this->headNodePtr;
}



// X-------------------------X
// |                         |
// |    GETTERS / SETTERS    |
// |                         |
// X-------------------------X

// #getPrevContext() - Returns the previous context of the current node
string LinkedListContext::getPrevContext(const NodeContext* currNodePtr) const {
   return(currNodePtr->prevContext);
}

// #getPostContext() - Returns the post context of the current node
string LinkedListContext::getPostContext(const NodeContext* currNodePtr) const {
      return(currNodePtr->postContext);
}



// X--------------------------X
// |                          |
// |    OPERATOR OVERLOADS    |
// |                          |
// X--------------------------X

// #operator< - Custom behavior for the less-than operator for this (RHarg) and another LinkedListContext (LHarg)
bool LinkedListContext::operator<(const LinkedListContext& someLinkedList) const {
   if (this->keyword < someLinkedList.keyword) {
      return(true);
   }
   else {
      return(false);
   }
}

// #operator> - Custom behavior for the less-than operator for this (RHarg) and another LinkedListContext (LHarg)
bool LinkedListContext::operator>(const LinkedListContext& someLinkedList) const {
   if (this->keyword > someLinkedList.keyword) {
      return(true);
   }
   else {
      return(false);
   }
}

// #operator= - Custom behavior for the assignment operator. Appends the RH context list to the receiving context list
LinkedListContext& LinkedListContext::operator=(LinkedListContext& RHarg) {
   // Check to see if "this" and "RHarg" are the same thing
   if (this != &RHarg) {
      // If they aren't... target the first Linked List Node of the RH argument
      NodeContext* targetNodePtr = RHarg.headNodePtr;
      // And while the target isn't nullptr...
      while(targetNodePtr != nullptr) {
         // Append RHarg context to LHS (this)
         this->append(RHarg.getPrevContext(targetNodePtr), RHarg.getPostContext(targetNodePtr));
         // Advance the target
         targetNodePtr = targetNodePtr->nextPtr;
      } // Closing while loop - All RHarg contexts have been appended to the LHarg

   }
   return *this;
}
/*
BCD& BCD::operator=(const BCD& rightHandSide) {
   //cout << "Starting operator=" << endl;
   //cout << "RHS: " << rightHandSide.toString() << endl;
   if (this != &rightHandSide) {
      this->obliterate();
      this->deepcopy(rightHandSide);
      // Copy relevant field states
      this->length = rightHandSide.length;
      this->isPositive = rightHandSide.isPositive;
   }
   //cout << "Operator= complete... returning *this: " << this->toString() << endl;
   return *this;
}
*/

// #operator== - Custom behavior for the equality operator for this (RHarg) and another LinkedListContext (LHarg)
bool LinkedListContext::operator==(const LinkedListContext& someLinkedList) const {
   if (this->keyword == someLinkedList.keyword) {
      // TODO: Append the context before returning true
      // TODO: Confirm which hand argument should receive the appended context (assuming RHarg catches it for now)
//      this->append(someLinkedList.getPrevContext(someLinkedList.headNodePtr) , someLinkedList.getPostContext(someLinkedList.headNodePtr) );
      return(true);
   }
   else {
      return(false);
   }
}

// #operator<< - Custom behavior for the stream insertion operator for this (RHarg) and another LinkedListContext (LHarg)
ostream& operator<<(ostream& coutStream, LinkedListContext& someLinkedList) {
   string thisLinkedList = "";
   // <Implement all string appending here>
   thisLinkedList += someLinkedList.toString();
   coutStream << thisLinkedList;
   return coutStream;
}
