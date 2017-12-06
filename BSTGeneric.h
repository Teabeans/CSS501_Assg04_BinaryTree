// Tim Lum
// twhlum@gmail.com
// 2017.12.04
// For the University of Washington Bothell CSS 501A
// Autumn 2017, Graduate Certificate in Software Design & Development (GCSDD)
//
// File Description:
// This file is the header file for the BSTGeneric class. This program shall accept a list of
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

// Necessary for file stream operations
#include <fstream>

using namespace std;



//-------------------------------------|
// #BSTGeneric {}
//-------------------------------------|
// Description: Organizes comparable data types into a binary search tree
template <class typeT>
class BSTGeneric {



protected:
//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       STRUCTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-------------------------------------|
// #NodeGeneric()
//-------------------------------------|
// Description: Generic node for use by the GenericBST class
// Invariants:  No default constructor should be called under normal operation
   template<class typeC>
   struct NodeGeneric {
      typeC nodeData;
      bool isDeleted;
      NodeGeneric<typeC>* leftPtr;
      NodeGeneric<typeC>* rightPtr;

      NodeGeneric() {
         nodeData = NULL;
         isDeleted = 1;
         leftPtr = nullptr;
         rightPtr = nullptr;
      }

      NodeGeneric(typeC& someData) {
         nodeData = someData;
         isDeleted = 0;
         leftPtr = nullptr;
         rightPtr = nullptr;
      }
   }; // Closing NodeGeneric



private:
//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE FIELDS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-------------------------------------|
// #treeData
//-------------------------------------|
// Description: The target node of this linked list
// Invariants:  String holding the name or identifier of this tree.
string treeData;

//-------------------------------------|
// #rootPtr
//-------------------------------------|
// Description: NodeGeneric pointer to the root node of this tree.
// Invariants:  Points to either nullptr or a NodeGeneric struct
NodeGeneric<typeT>* rootPtr;



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE METHODS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-------------------------------------|
// #deletePostOrder()
//-------------------------------------|
// Description:      Recursive method for post-order deletion method
// Parameters:       NodeGeneric* - The target node to be traversed and deleted
// Preconditions:    None
// Postconditions:   All nodes in this subtree have been deleted
// Return value:     True - Signal of successful deletion traversal
// Functions called: deletePostOrder()
bool deletePostOrder();
bool deletePostOrder(NodeGeneric<typeT>* nodePtr);

//-------------------------------------|
// #obliviate()
//-------------------------------------|
// Description:      Deletes all nodes within the BST
// Parameters:       None
// Preconditions:    None
// Postconditions:   All tree nodes have been deleted.
//                   headNodePtr == nullptr
// Return value:     None
// Functions called: deletePostOrder()
void obliviate();

//-------------------------------------|
// #traversePreOrder(NodeGeneric*)
//-------------------------------------|
// Description:      Recursive pre-order traversal method
// Parameters:       NodeGeneric* arg1 - Pointer to the node to traverse
// Preconditions:    None
// Postconditions:   None
// Return value:     True - Signal of successful recursive traversal
// Functions called: traversePreOrder()
//                   visit()
bool traversePreOrder();
bool traversePreOrder(NodeGeneric<typeT>* nodePtr);

//-------------------------------------|
// #traverseInOrder(NodeGeneric*)
//-------------------------------------|
// Description:      Recursive in-order traversal method
// Parameters:       NodeGeneric* arg1 - Pointer to the node to traverse
// Preconditions:    None
// Postconditions:   None
// Return value:     True - Signal of successful recursive traversal
// Functions called: traverseInOrder()
//                   visit()
bool traverseInOrder();
bool traverseInOrder(NodeGeneric<typeT>* nodePtr);

//-------------------------------------|
// #traversePostOrder(NodeGeneric*)
//-------------------------------------|
// Description:      Recursive post-order traversal method
// Parameters:       NodeGeneric* arg1 - Pointer to the node to traverse
// Preconditions:    None
// Postconditions:   None
// Return value:     True - Signal of successful recursive traversal
// Functions called: traversePostOrder()
//                   visit()
bool traversePostOrder();
bool traversePostOrder(NodeGeneric<typeT>* nodePtr);

//-------------------------------------|
// #visit(NodeGeneric)
//-------------------------------------|
// Description:      Visits the node indicated by sending the nodeData content to cout.
// Parameters:       NodeGeneric* - The target node being visited
// Preconditions:    None
// Postconditions:   None
// Return value:     None
// Functions called: None
void visit(NodeGeneric<typeT>* thisNodePtr) const;



public:
//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC FIELDS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// None



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC METHODS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-------------------------------------|
// #find(string)
//-------------------------------------|
// Finds a node with an equal value of the string argument
// Parameters:       typeT - The data to search for
// Preconditions:    None
// Postconditions:   None
// Return value:     True - An equivalent node was found
//                   False - An equivalent node was not found
// Functions called: None
bool find(typeT someData) const;

//-------------------------------------|
// #insert(typeT)
//-------------------------------------|
// Description:      Attempts to insert data of typeT to the tree
// Parameters:       typeT arg1 - The data to insert
// Preconditions:    None
// Postconditions:   Data has been found or search has run off the tree
//                   Data has been assigned to an appropriate node of the tree
// Return value:     True - Data was not found in the tree. Assigned off a leaf.
//                   False - Data found in the tree, assignment still occured
// Functions called: NodeGeneric()
bool insert(typeT& someData); // Gets passed a LLC by reference

//-------------------------------------|
// #printout()
//-------------------------------------|
// Description:      Prints the tree to console
// Parameters:       None
// Preconditions:    None
// Postconditions:   None
// Return value:     None
// Functions called: traversePreOrder() - Optional
//                   traverseInOrder - Prints tree in an in-order traversal
//                   traversePostOrder() - Optional
void printout() ;

//-------------------------------------|
// #setDelete()
//-------------------------------------|
// Description:      Finds a node with matching data and sets its deletion flag to true
// Parameters:       typeT - The target data to find
// Preconditions:    None
// Postconditions:   Target node has been set to deleted or nothing happens
// Return value:     True - 'Deletion' successful
//                   False - Node not found
// Functions called: retrieve()
bool setDelete(typeT someData);



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS / DESTRUCTORS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-------------------------------------|
// #BSTGeneric()
//-------------------------------------|
// Default constructor for the BSTGeneric class
// Parameters:       None
// Preconditions:    None
// Postconditions:   An empty binary tree has been allocated
// Return value:     None
// Functions called: None
BSTGeneric();

//-------------------------------------|
// #BSTGeneric(string)
//-------------------------------------|
// Constructor of the BSTGeneric class from a file address
// Parameters:       string arg1 - A file address (name)
// Preconditions:    None
// Postconditions:   A binary tree of strings has been generated
// Return value:     None
// Functions called: insert()
//                   ifstream.open()
//                   ifstream.close()
BSTGeneric(string fileAddress);

//-------------------------------------|
// #~BSTGeneric()
//-------------------------------------|
// Default destructor of the BSTGeneric class
// Parameters:       None
// Preconditions:    None
// Postconditions:   All memory allocated for BST Nodes has been deallocated
// Return value:     None
// Functions called: obliviate()
~BSTGeneric();



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       GETTERS / SETTERS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-------------------------------------|
// #getRootValue()
//-------------------------------------|
// Description:      Returns the root node's data field
// Parameters:       None
// Preconditions:    None
// Postconditions:   None
// Return value:     typeT& - A generic data object
// Functions called: None
typeT& getRootValue() const;

//-------------------------------------|
// #getValue()
//-------------------------------------|
// Description:      Returns the tree's data field (its name)
// Parameters:       None
// Preconditions:    None
// Postconditions:   None
// Return value:     string - The name of the tree
// Functions called: None
string getValue() const;

//-------------------------------------|
// #setValue()
//-------------------------------------|
// Description:      Sets the tree's data field (its name)
// Parameters:       string arg1 - The name to enter
// Preconditions:    None
// Postconditions:   treeData == someValue
// Return value:     None
// Functions called: None
void setValue( string someValue );

}; // Closing class 'BSTGeneric'

// ---- END STUDENT CODE ----
