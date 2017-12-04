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

// X----------------X
// |    #reset()    |
// X----------------X
// #reset() - Sets the current node pointer to the head node
void LinkedListContext::reset() {
   if (headNodePtr != nullptr) {
      currPtr = headNodePtr; // TODO - Confirm this assignment works
   }
}

// #isLastNode() - Reports whether the currPtr points to the last body node.
bool LinkedListContext::isLastNode() {
   // Test to avoid read access error, currPtr might be null, in which case nextPtr cannot be read
   if (currPtr == nullptr) {
      return(true);
   }
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
   cout << "LLC.append() called." << endl;
   this->reset();
   if (this->headNodePtr == nullptr) {
      cout << "No head node" << endl;
      this->headNodePtr = new NodeContext(prevContext, postContext);
      this->currPtr = this->headNodePtr;
      cout << "Append completed on a blank LLC." << endl;
      return;
   }
   // Move to the end of the linked list
   while (!this->isLastNode()) {
      this->advance();
   } // currPtr now points at the last node
   // Append a new node with the provided contexts
   this->currPtr->nextPtr = new NodeContext(prevContext, postContext);
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
   // cout << "LLC.toString() reset complete. currPtr: " << currPtr << endl; // DEBUG
   // Determine the pad width
   for (int i = 0 ; i < (formatLength - currPtr->lengthOfPrevContext) ; i++) {
      // cout << "Padding."; // DEBUG
      pad = pad + " ";
   }
   // determine the keypad width (only needs to be done once per LinkedListContext, since all keywords should be the same
   for (int i = 0 ; i < (keywordFormatLength - this->keyword.length()) ; i++) { // keywordFormatLength @ 
      // cout << "Keypadding."; // DEBUG
      keypad = keypad + " ";
   }

   // Append the pad, context, gap, keyword, keyword gap, gap, context, and a line break to the return string
   // cout << "LLC.toString() - Appending..." << endl; // DEBUG
   retString = retString+ pad + currPtr->prevContext + gap + keyword + keypad + gap + currPtr->postContext + "\n";
   // cout << "LLC.toString() - First append completed." << endl; // DEBUG

   // And while we haven't run off the end of the list...
   while (!this->isLastNode()) {
      // cout << "LLC.toString() while-loop activated." << endl; // DEBUG
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
   // cout << "LLC.toString() successful!" << endl; // DEBUG
   return(retString);
}



// X--------------------------------X
// |                                |
// |    CONSTRUCTORS/DESTRUCTORS    |
// |                                |
// X--------------------------------X

// X---------------------------X
// |    LinkedListContext()    |
// X---------------------------X
// Default constructor - Called by 
LinkedListContext::LinkedListContext() {
   cout << "LLC.LLC() - Default constructor called." << endl; // DEBUG
//   keyword = ".";
   // cout << "LLC.LLC() Keyword: " << keyword << endl; // DEBUG
   currPtr = nullptr;
   headNodePtr = nullptr;
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
   // cout << "Destructo Presto!" << endl; // DEBUG
   if (this->headNodePtr == nullptr) {
      // cout << "Nothing to see here. Exiting!" << endl;
      return;
   }
   NodeContext* prevNodePtr = this->headNodePtr;
   // While a body node still exists...
   this->currPtr = this->headNodePtr;
   if (this->currPtr == nullptr) {
      // cout << "Nothing to see here either" << endl;
   }
   // cout << "Attempting to advance to end: " << headNodePtr << ":" << currPtr << endl;

   while (this->headNodePtr->nextPtr != nullptr) {
      // cout << "headNode.nextPtr != nullptr" << endl;
      // Advance to the end
      // TODO: Need a test here: What if currPtr is nullptr because the head node was also nullptr when it was assigned on 194? There's no nextPtr to dereference.
      while (this->currPtr->nextPtr != nullptr) { // Read Access Violation
         prevNodePtr = this->currPtr;
         this->advance();
         //cout << "Crossing over " << this->currPtr->prevContext << ":" << this->currPtr->postContext << endl; // DEBUG
      } // Closing while loop, curr points to last node, prev points to second to last
      // cout << "Deallocating " << this->currPtr->prevContext << ":" << this->currPtr->postContext << endl; // DEBUG
      // And delete it
      delete this->currPtr;
      // And remove the previous pointer
      prevNodePtr->nextPtr = nullptr;
      this->currPtr = this->headNodePtr;
      prevNodePtr = this->headNodePtr;
   } // Body nodes are all deleted

   // cout << "Deleting Head Node: " << endl; // DEBUG
   // cout << "Deallocating " << this->headNodePtr->prevContext << ":" << this->headNodePtr->postContext << endl; // DEBUG
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
   if (this == &RHarg) { // Compares reference addresses
      cout << "LLC assignment attempted on self. Returning." << endl; // DEBUG
      return *this; // If the same, bail.
   }
   // The two linked lists are different...
   if (this != &RHarg) {
      cout << "This LLC keyword: " << this->keyword << endl;
      cout << "That LLC keyword: " << RHarg.keyword << endl;
      this->keyword = RHarg.keyword;
      // If they aren't... target the first Linked List Node of the RH argument
      NodeContext* targetNodePtr = RHarg.headNodePtr;
      // And while the target isn't nullptr...
      while(targetNodePtr != nullptr) {
         cout << "LLC.operator= appending..." << endl;
         // cout << "AppendingPrev: " << this->getPrevContext(this->headNodePtr) << endl; // BUG - Attempting to access a nullptr
         // cout << "AppendingPost: " << this->getPostContext(this->headNodePtr) << endl; // BUG - Attempting to access a nullptr
         cout << "AppendingPrev: " << RHarg.getPrevContext(targetNodePtr) << endl;
         cout << "AppendingPost: " << RHarg.getPostContext(targetNodePtr) << endl;
         // Append RHarg context to LHS (this)
         this->append(RHarg.getPrevContext(targetNodePtr), RHarg.getPostContext(targetNodePtr));
         cout << "LLC.operator= Append() complete! Advancing target..." << endl;
         // Advance the target
         targetNodePtr = targetNodePtr->nextPtr;
      } // Closing while loop - All RHarg contexts have been appended to the LHarg
   }
   cout << "Closing LLC.operator=()" << endl << endl;
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
   // cout << "LLC.op<<() called"; // DEBUG
   string thisLinkedList = "";
   // <Implement all string appending here>
   thisLinkedList += someLinkedList.toString();
   coutStream << thisLinkedList;
   // cout << "LLC.op<<() successful"; // DEBUG
   return coutStream;
}
