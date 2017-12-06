// Tim Lum
// twhlum@gmail.com
// 2017.12.04
// For the University of Washington Bothell CSS 501A
// Autumn 2017, Graduate Certificate in Software Design & Development (GCSDD)
//
// File Description:
// This file is the header file for the LinkedListContext class. This program shall accept a list of
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

#pragma once

// Necessary for input-output operations
#include <iostream>

// Necessary for string operations
#include <string>

using namespace std;

// X--------------------------X
// |    #LinkedListContext    |
// X--------------------------X
// Description: Performs corpus-related operations.
class LinkedListContext {



protected:
//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       STRUCTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-------------------------------------|
// #NodeContext()
//-------------------------------------|
// Description: Linked List node holding previous and post context
// Invariants:  No default constructor should be called under normal operation
struct NodeContext {
   string prevContext;
   string postContext;
   NodeContext* nextPtr;
   int lengthOfPrevContext;

   NodeContext() {
      prevContext = "Default NodeContext()";
      postContext = "For Test Purpose Only";
      nextPtr = nullptr;
      lengthOfPrevContext = 0;
   }

   NodeContext(string wordsBefore, string wordsAfter) {
      prevContext = wordsBefore;
      postContext = wordsAfter;
      lengthOfPrevContext = wordsBefore.length();
      nextPtr = nullptr;
   }
}; // Closing NodeContext{}



private:
//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE FIELDS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-------------------------------------|
// #currPtr
//-------------------------------------|
// Description: The target node of this linked list
// Invariants:  Range from HeadNode to nullptr
NodeContext* currPtr;

//-------------------------------------|
// #headNodePtr
//-------------------------------------|
// Description: Pointer to the head node of this linked list
// Invariants:  Shall always point to a node under normal operation
NodeContext* headNodePtr;

//-------------------------------------|
// #keywordFormatLength
//-------------------------------------|
// Description: Static int representing the longest observed prevContext string
// Invariants:  Value from 1 to the longest possible word sequence
//              Output format degrades at high values (~30+)
static int formatLength;

//-------------------------------------|
// #keywordFormatLength
//-------------------------------------|
// Description: Static int representing the longest observed keyword
// Invariants:  Value from 1 to the longest possible word
//              Output format degrades at high values (~20+)
static int keywordFormatLength;

//-------------------------------------|
// #keyword
//-------------------------------------|
// Description: Keyword of this LinkedListContext object
// Invariants:  String will begin and end with characters 'a' to 'z', inclusive
string keyword; // Inherited from the BSTConcordance node



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
void advance();

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
void append(string prevContext, string postContext);

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
bool isLastNode();

//-------------------------------------|
// #reset()
//-------------------------------------|
// Description:      Sets the currPtr node pointer to the head node
// Parameters:       None
// Preconditions:    None
// Postconditions:   currPtr is equal to headNodePtr
// Return value:     None
// Functions called: None
void reset();



public:
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
string toString();



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
LinkedListContext();

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
LinkedListContext(string someKeyword, string prevContext, string postContext);

//-------------------------------------|
// #~LinkedListContext()
//-------------------------------------|
// Description:      Destructor for the LinkedListContext class
// Parameters:       None
// Preconditions:    None
// Postconditions:   All context nodes have been deallocated
// Return value:     None
// Functions called: advance()
~LinkedListContext();



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
string getPrevContext(const NodeContext* currNodePtr) const;

//-------------------------------------|
// #getKeyword()
//-------------------------------------|
// Description:      Returns the keyword field of this LinkedListContext
// Parameters:       None
// Preconditions:    None
// Postconditions:   None
// Return value:     string - The keyword string of this object
// Functions called: None
string getKeyword() const;

//-------------------------------------|
// #getPostContext(NodeContext*)
//-------------------------------------|
// Description:      Returns the postContext field of a target NodeContext
// Parameters:       NodeContext* arg1 - A pointer to a target NodeContext
// Preconditions:    None
// Postconditions:   None
// Return value:     string - The postContext string of the targeted NodeContext
// Functions called: None
string getPostContext(const NodeContext* currNodePtr) const;



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
bool operator<(const LinkedListContext& someLinkedList) const;

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
bool operator>(const LinkedListContext& someLinkedList) const;

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
bool operator==(const LinkedListContext& someLinkedList) const;

//-------------------------------------|
// #operator=(LinkedListContext)
//-------------------------------------|
// Description:      Custom behavior for the assignment operator.
// Parameters:       LinkedListContext arg1 - The data being assigned
// Preconditions:    None
// Postconditions:   None
// Return value:     LinkedListContext& - A keyword with additional context
// Functions called: append()
LinkedListContext& operator=(LinkedListContext& someLinkedList);

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
friend ostream& operator<<(ostream& coutStream, LinkedListContext& someLinkedList);

}; // Closing class LinkedListContext


// ---- END STUDENT CODE ----
