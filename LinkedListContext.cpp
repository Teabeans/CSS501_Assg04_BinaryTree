// Tim Lum
// twhlum@gmail.com
// 2017.12.04
// For the University of Washington Bothell CSS 501A
// Autumn 2017, Graduate Certificate in Software Design & Development (GCSDD)
//
// File Description:
// This file is the implementation file for the LinkedListContext class. This program shall accept a list of
// stopwords (stopwords.txt) as well as a command argument corpus location. From these bodies of data
// it will generate a concordance in KeyWord In Context (KWIC) format.
//
// Package files:
// Driver.cpp
// BSTGeneric.h
// BSTGeneric.cpp
// ReaderCorpus.h
// ReaderCorpus.cpp
// LinkedListContext.h
// LinkedListContext.cpp
// stopwords.txt (recommended)
// Corpus (not named, name must be passed as a command argument)
//
// Acknowledgements:
// Source material from:
// University of Washington Bothell
// CSS 501A Data Structures And Object-Oriented Programming I
// "Design and Coding Standards"
// Michael Stiber
//
// Template author:
// Tim Lum (twhlum@gmail.com)
//
// License:
// This software is published under the GNU general license which guarantees
// end users the freedom to run, study, share and modify the software.
// https://www.gnu.org/licenses/gpl.html
//
// Code Standards:
// I. Comment at beginning of file (above) stating (at a minimum):
//    A. File Name
//    B. Author Name
//    C. Date
//    D. Description of code purpose 
// II. Indentation:
//    A. 3 whitespaces ("   ")
//    B. May vary depending on language and instructor
// III. Variables:
//    A. Descriptive, legible name
//    B. Comment over any variable declaration describing:
//       0. Its use in the algorithm
//       1. Invariant information such as legal ranges of values
// IV. Class Files:
//    A. Separate *.cpp and *.h files should be used for each class.
//    B. Files names must exactly match class names (case-sensitive)
// V. Includes:
//    A. Calls for content ("#include") from the Standard Template Library (STL) should be formatted as follows:
//       0. DO type:     #include <vector>
//       1. Do NOT type: #include <vector.h>
//    B. You may use the directive "using namespace std;"
//       0. ??? (?CONFIRM?)
// VI. Classes:
//    A. Return values:
//       0. Do NOT return references to internal class structures.
//       1. Do NOT return pointers to internal class structures.
//    B. Do NOT expose any details of the internal implementation.
// VII. Functions + Methods:
//    A. Functions should be used for appropriate operations.
//    B. Reference arguments should be used only when necessary.
//    C. The (return?CONFIRM?) type of each function must be declared
//       0. Use 'void' when necessary
//    D. Declare as 'const' (unalterable) when no modification is made to the object state
//       0. UML 'query' property (?CONFIRM?)
// VIII. Function Comments:
//    A. DO include a comment prior to each function which includes the function's:
//       0. Purpose - Why does the function exist?
//       1. Parameters - What fields does the function contain?
//       2. Preconditions - What conditions must be true prior to the function call?
//       3. Postconditions - What conditions must be true after the function call?
//       4. Return value - What is the nature and range of the value returned by the function?
//       5. Functions called - What other functions are called by this function?
// IX. Loop invariants
//    A. Each loop should be commented with 'invariant' information (?CONFIRM?)
// X. Assertions:
//    A. May be comments or the 'assert()' feature.
//    B. Insert where useful to explain important features or subtle logic.
//    C. What, exactly, is an assertion (?CONFIRM?)
// XI. Prohibited (unless justified):
//    A. Global variables
//    B. "Gotos" (?CONFIRM?)
//
// Special instructions:
// To install G++:
// sudo apt install g++
// 
// To update Linux:
// sudo apt-get update && sudo apt-get install
// sudo apt-get update
//
// To make a new .cpp file in Linux:
// nano <file name>.cpp
//
// To make a new .h file in Linux:
// nano <file name>.h
//
// To make a new .txt file in Linux:
// nano <file name>.txt
//
// To compile in g++:
// g++ -std=c++11 *.cpp
//
// To run with test input:
// ./a.out < TestInput.txt
//
// To run Valgrind:
// Install Valgrind:
// sudo apt install valgrind
//
// Run with:
// valgrind --leak-check=full <file folder path>/<file name, usually a.out>
// OR
// valgrind --leak-check=full --show-leak-kinds=all <file path>/a.out
//
// ie.
// valgrind --leak-check=full /home/Teabean/a.out
// OR
// valgrind --leak-check=full --show-leak-kinds=all /home/Teabean/a.out
// OR
// valgrind --leak-check=full --show-leak-kinds=all /home/Teabean/a.out < /Sudoku.txt
//
// To load a text file as cin input in Visual Studios:
// 1. Go to the top menu bar => Debug => <ProjectName> Properties => Debugging => Command Arguments =>
// 2. "< <Filepath>/<Filename>.txt" ie. "< /Sudoku.txt"
// ie. < /Sudoku.txt
//
// To pass a command argument:
// 1. Go to the top menu bar => Debug => <ProjectName> Properties => Debugging => Command Arguments =>
// 2. Enter the file address and name
// ie. corpus.txt
// 3. Alter main() method signature as follows: main( int argc, char* argv[] ) {
// 4. The variable "argv[1]" now refers to the first command argument passed
//
// To run in Linux with Valgrind and a command argument
// valgrind --leak-check=full --show-leak-kinds=all /home/Teabean/a.out Sudoku.txt
//
// ---- BEGIN STUDENT CODE ----



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       INCLUDE STATEMENTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// #pragma once

// Necessary for input-output operations
#include <iostream>

// Necessary for string operations
#include <string>

// Field and method declarations for the LinkedListContext class
#include "LinkedListContext.h"

using namespace std;



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       STRUCTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// Do not reinitialize these structs in the .cpp.
// Included here for reference

//-------------------------------------|
// #NodeContext()
//-------------------------------------|
// Description: Linked List node holding previous and post context
// Invariants:  No default constructor should be called under normal operation
// struct NodeContext {}


//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE FIELDS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-------------------------------------|
// #keywordFormatLength
//-------------------------------------|
// Description: Static int representing the longest observed prevContext string
// Invariants:  Value from 1 to the longest possible word sequence
//              Output format degrades at high values (~30+)
int LinkedListContext::formatLength;

//-------------------------------------|
// #keywordFormatLength
//-------------------------------------|
// Description: Static int representing the longest observed keyword
// Invariants:  Value from 1 to the longest possible word
//              Output format degrades at high values (~20+)
int LinkedListContext::keywordFormatLength;

// Do not reinitialize these variables in the .cpp.
// Included here for reference

//-------------------------------------|
// #currPtr
//-------------------------------------|
// Description: The target node of this linked list
// Invariants:  Range from HeadNode to nullptr
// NodeContext* currPtr;

//-------------------------------------|
// #headNodePtr
//-------------------------------------|
// Description: Pointer to the head node of this linked list
// Invariants:  Shall always point to a node under normal operation
// NodeContext* headNodePtr;

//-------------------------------------|
// #keyword
//-------------------------------------|
// Description: Keyword of this LinkedListContext object
// Invariants:  String will begin and end with characters 'a' to 'z', inclusive
// string keyword;




//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE METHODS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-------------------------------------|
// #advance()
//-------------------------------------|
// Description:      Attempts to move currPtr forward one body node.
// Parameters:       None
// Preconditions:    None
// Postconditions:   currPtr is one node further in the linked list
// Return value:     cout - Error message declaring failure to advance
// Functions called: isLastNode()
void LinkedListContext::advance() {
   if (isLastNode() == false) {
      currPtr = currPtr->nextPtr;
   }
   else {
      // TODOE: Add error message
   }
}

//-------------------------------------|
// #append(string, string)
//-------------------------------------|
// Description:      Adds a new node to the Linked List
//                   Updates the maximum observed prev context length.
// Parameters:       string arg1 - The previous context to append
//                   string arg2 - The post context to append
// Preconditions:    None
// Postconditions:   A new context node has been added to the end of the linked list
// Return value:     None
// Functions called: NodeContext()
//                   advance()
//                   isLastNode()
//                   reset()
//                   string.length()
void LinkedListContext::append(string prevContext, string postContext){
   // Go back to the head node
   this->reset();
   // Attempt to append context at the head
   if (this->headNodePtr == nullptr) {
      this->headNodePtr = new NodeContext(prevContext, postContext);
      this->currPtr = this->headNodePtr;
      return;
   }
   // But if the head is occupied, move to the end of the linked list
   while (!this->isLastNode()) {
      this->advance();
   } // currPtr now points at the last node
   // Append a new node with the provided contexts
   this->currPtr->nextPtr = new NodeContext(prevContext, postContext);
   // And set an updated formatLength
   if ((signed)prevContext.length() > formatLength) {
      formatLength = prevContext.length();
   }
} // End append

//-------------------------------------|
// #isLastNode()
//-------------------------------------|
// Description:      Reports whether the currPtr points to the last body node.
// Parameters:       None
// Preconditions:    None
// Postconditions:   None
// Return value:     True - There are no further nodes in the list
//                   False - There is a valid next node
// Functions called: None
bool LinkedListContext::isLastNode() {
   // If the nextPtr is off the end of the linked list...
   if (currPtr->nextPtr == nullptr) {
      // This is the last node
      return(true);
   }
   // Otherwise, it isn't.
   return(false);
}

//-------------------------------------|
// #reset()
//-------------------------------------|
// Description:      Sets the currPtr node pointer to the head node
// Parameters:       None
// Preconditions:    None
// Postconditions:   currPtr is equal to headNodePtr
// Return value:     None
// Functions called: None
void LinkedListContext::reset() {
   if (headNodePtr != nullptr) {
      currPtr = headNodePtr;
   }
}



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC FIELDS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// None for this class



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC METHODS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-------------------------------------|
// #toString()
//-------------------------------------|
// Description:      String output generator for a LinkedListContext object
// Parameters:       None
// Preconditions:    None
// Postconditions:   None
// Return value:     String - A representation of this LinkedListContext object
// Functions called: advance()
//                   isLastNode()
//                   reset()
//                   string.length()
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
   // Determine the keypad width (only needs to be done once per LinkedListContext, since all keywords should be the same)
   for (int i = 0 ; i < (keywordFormatLength - (signed)this->keyword.length()) ; i++) {
      keypad = keypad + " ";
   }
   // Append the pad, context, gap, keyword, keyword gap, gap, context, and a line break to the return string
   retString = retString+ pad + currPtr->prevContext + gap + keyword + keypad + gap + currPtr->postContext + "\n";
   // And while we haven't run off the end of the list...
   while (!this->isLastNode()) {
      // Move forward one node
      this->advance();
      // And repeat:
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
} // Closing toString()



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS / DESTRUCTORS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-------------------------------------|
// #LinkedListContext()
//-------------------------------------|
// Description:      Default constructor for the LinkedListContext class
// Parameters:       None
// Preconditions:    None
// Postconditions:   A new LinkedListContext object has been allocated
// Return value:     None
// Functions called: None
LinkedListContext::LinkedListContext() {
   currPtr = nullptr;
   headNodePtr = nullptr;
   // TODOE: Initialize formatLength, keywordFOrmatLength, and keyword here
}

//-------------------------------------|
// #LinkedListContext(string, string, string)
//-------------------------------------|
// Description:      Constructs a LinkedListContext object from three strings
// Parameters:       string arg1 - The previous context of a keyword
//                   string arg2 - The keyword string
//                   string arg3 - The post context of a keyword
// Preconditions:    None
// Postconditions:   A new LinkedListContext object has been allocated
// Return value:     None
// Functions called: string.length()
LinkedListContext::LinkedListContext(string prevContext, string someKeyword, string postContext) {
   keyword = someKeyword;
   // Update the maximum observed keyword length
   if ((signed)keyword.length() > keywordFormatLength) {
      keywordFormatLength = keyword.length();
   }
   headNodePtr = new NodeContext(prevContext, postContext);
   currPtr = headNodePtr;
   // Check the length of the previous context string against the highest observed prev context length
   if (headNodePtr->lengthOfPrevContext > LinkedListContext::formatLength) {
      // Set the length to the longer of the two
      LinkedListContext::formatLength = headNodePtr->lengthOfPrevContext;
   } // The formatLength field is equal to the longest observed prev context length
} // Closing LinkedListCOntext(string, string, string)

//-------------------------------------|
// #~LinkedListContext()
//-------------------------------------|
// Description:      Destructor for the LinkedListContext class
// Parameters:       None
// Preconditions:    None
// Postconditions:   All context nodes have been deallocated
// Return value:     None
// Functions called: advance()
LinkedListContext::~LinkedListContext() {
   // In case the LinkedListContext object is empty
   if (this->headNodePtr == nullptr) {
      // Do nothing
      return;
   }
   // Otherwise...
   NodeContext* prevNodePtr = this->headNodePtr;
   // Target the head node
   this->currPtr = this->headNodePtr;
   // While a body node still exists...
   while (this->headNodePtr->nextPtr != nullptr) {
      // Advance to the end
      while (this->currPtr->nextPtr != nullptr) {
         prevNodePtr = this->currPtr;
         this->advance();
      } // Closing while loop, curr points to last node, prev points to second to last
      // And delete it
      delete this->currPtr;
      // And remove the previous pointer
      prevNodePtr->nextPtr = nullptr;
      this->currPtr = this->headNodePtr;
      prevNodePtr = this->headNodePtr;
   } // Closing while loop - All body nodes have been deleted
   // Finally, delete the head node
   delete this->headNodePtr;
} // Closing ~LinkedListContext()



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       GETTERS / SETTERS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-------------------------------------|
// #getPrevContext(NodeContext*)
//-------------------------------------|
// Description:      Returns the prevContext field of a target NodeContext
// Parameters:       NodeContext* arg1 - A pointer to a target NodeContext
// Preconditions:    None
// Postconditions:   None
// Return value:     string - The prevContext string of the targeted NodeContext
// Functions called: None
string LinkedListContext::getPrevContext(const NodeContext* currNodePtr) const {
   return(currNodePtr->prevContext);
}

//-------------------------------------|
// #getKeyword()
//-------------------------------------|
// Description:      Returns the keyword field of this LinkedListContext
// Parameters:       None
// Preconditions:    None
// Postconditions:   None
// Return value:     string - The keyword string of this object
// Functions called: None
string LinkedListContext::getKeyword() const {
   return (keyword);
}

//-------------------------------------|
// #getPostContext(NodeContext*)
//-------------------------------------|
// Description:      Returns the postContext field of a target NodeContext
// Parameters:       NodeContext* arg1 - A pointer to a target NodeContext
// Preconditions:    None
// Postconditions:   None
// Return value:     string - The postContext string of the targeted NodeContext
// Functions called: None
string LinkedListContext::getPostContext(const NodeContext* currNodePtr) const {
      return(currNodePtr->postContext);
}



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       OPERATOR OVERLOADS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-------------------------------------|
// #operator<(LinkedListContext)
//-------------------------------------|
// Description:      Custom behavior for the less-than operator
// Parameters:       LinkedListContext& arg1 - Object being compared against 'this'
// Preconditions:    None
// Postconditions:   None
// Return value:     True  - Arg1 keyword is greater than 'this' keyword
//                   False - Arg1 keyword is less    than 'this' keyword
// Functions called: None
bool LinkedListContext::operator<(const LinkedListContext& someLinkedList) const {
   if (this->keyword < someLinkedList.keyword) {
      return(true);
   }
   else {
      return(false);
   }
}

// #operator> - Custom behavior for the less-than operator for this (RHarg) and another LinkedListContext (LHarg)
//-------------------------------------|
// #operator>(LinkedListContext)
//-------------------------------------|
// Description:      Custom behavior for the greater-than operator
// Parameters:       LinkedListContext& arg1 - Object being compared against 'this'
// Preconditions:    None
// Postconditions:   None
// Return value:     True  - Arg1 keyword is less    than 'this' keyword
//                   False - Arg1 keyword is greater than 'this' keyword
// Functions called: None
bool LinkedListContext::operator>(const LinkedListContext& someLinkedList) const {
   // Compare the keyword strings against each other
   if (this->keyword > someLinkedList.keyword) {
      // If LH term is greater, return true
      return(true);
   }
   // Otherwise return false
   else {
      return(false);
   }
}

//-------------------------------------|
// #operator=(LinkedListContext)
//-------------------------------------|
// Description:      Custom behavior for the equality operator
// Parameters:       LinkedListContext& arg1 - Object being compared against 'this'
// Preconditions:    None
// Postconditions:   None
// Return value:     True - The keywords are equivalent
//                   False - The keywords are inequal
// Functions called: None
bool LinkedListContext::operator==(const LinkedListContext& RHarg) const {
   // Compare the keyword strings against each other
   if (this->keyword == RHarg.keyword) {
      // If equal, return true
      return(true);
   }
   // Otherwise return false
   else {
      return(false);
   }
}

//-------------------------------------|
// #operator=(LinkedListContext)
//-------------------------------------|
// Description:      Custom behavior for the assignment operator.
// Parameters:       LinkedListContext arg1 - The data being assigned
// Preconditions:    None
// Postconditions:   None
// Return value:     LinkedListContext& - A keyword with additional context
// Functions called: append()
LinkedListContext& LinkedListContext::operator=(LinkedListContext& RHarg) {
   // Check to see if "this" and "RHarg" are the same thing (by address)
   if (this == &RHarg) {
      // If the same, bail.
      return *this;
   }
   // Else, the two linked lists are different...
   if (this != &RHarg) {
      this->keyword = RHarg.keyword;
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
   // Send the appended LinkedListContext back
   return *this;
}

//-------------------------------------|
// #operator<<(ostream, LinkedListContext)
//-------------------------------------|
// Description:      Custom behavior for the stream insertion operator
// Parameters:       ostream& arg1 - The receiving stream
//                   LinkedListContext& arg2 - The object being inserted
// Preconditions:    None
// Postconditions:   None
// Return value:     ostream& - The appended ostream object
// Functions called: toString()
ostream& operator<<(ostream& coutStream, LinkedListContext& someLinkedList) {
   // cout << "LLC.op<<() called"; // DEBUG
   string thisLinkedList = "";
   // <Implement all string appending here>
   thisLinkedList = thisLinkedList + someLinkedList.toString();
   coutStream << thisLinkedList;
   // cout << "LLC.op<<() successful"; // DEBUG
   return coutStream;
}

// ---- END STUDENT CODE ----
