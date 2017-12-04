// Tim Lum
// twhlum@gmail.com
// 2017.12.04
// For the University of Washington Bothell CSS 501A
// Autumn 2017, Graduate Certificate in Software Design & Development (GCSDD)
//
// File Description:
// This file is the driver file for the Concordance Assignment. This program shall accept a list of
// stopwords (stopwords.txt) as well as a command argument corpus location. From these bodies of data
// it will generate a concordance in KeyWord In Context (KWIC) format.
//
// Package files:
// Driver.cpp
// BSTGeneric.h
// BSTGeneric.cpp
// NodeGeneric.cpp
// ReaderCorpus.h
// ReaderCorpus.cpp
// LinkedListContext.h
// LinkedListContext.cpp
// NodeContext.cpp
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



// X--------------------------X
// |                          |
// |    INCLUDE STATEMENTS    |
// |                          |
// X--------------------------X

#include <iostream>
#include <string>
#include <fstream>

#include "BSTGeneric.h"

// Node definition
#include "NodeGeneric.cpp" // For a generic node (holding data, left, and right)

using namespace std;



// X----------------------X
// |                      |
// |    PRIVATE FIELDS    |
// |                      |
// X----------------------X

// Do not reinitialize these variables in the .cpp

// template <class typeT>
// string contextWords[11];

// template <class typeT>
// string treeData = "";

// template <class typeT>
// NodeGeneric<typeT>* rootPtr;



// X-----------------------X
// |                       |
// |    PRIVATE METHODS    |
// |                       |
// X-----------------------X


// #deletePostOrder() - Helper method
template <class typeT>
bool BSTGeneric<typeT>::deletePostOrder() {
   // cout << "deletePostOrder() called." << endl; // DEBUG
   // Check for empty tree
   if (rootPtr == nullptr) {
      // cout << "No traversal possible. This tree is empty." << endl;
      return (false);
   }
   // Otherwise, return the results of the recursive traversal
   else {
      return (deletePostOrder(rootPtr));
   }
}

// #deletePostOrder(nodePtr) - Recursive method
template <class typeT>
bool BSTGeneric<typeT>::deletePostOrder(NodeGeneric<typeT>* thisNode) {
   // Left traverse
   if (thisNode->leftPtr != nullptr) {
      deletePostOrder(thisNode->leftPtr);
   }
   // Right traverse
   if (thisNode->rightPtr != nullptr) {
      deletePostOrder(thisNode->rightPtr);
   }
   // Visit (delete)
   delete thisNode;
   cout << " Poof! "; // DEBUG
   return(true);
}

// X------------------------X
// |    #insert(<typeT>)    |
// X------------------------X
// 
template <class typeT>
bool BSTGeneric<typeT>::insert(typeT& someData) { // Receiving by reference
   // cout << "Insert() called" << endl; // DEBUG
   // cout << "NodeData: " << someData << endl; // DEBUG
   NodeGeneric<typeT>* currNodePtr = rootPtr;
   NodeGeneric<typeT>* prevNodePtr = nullptr;
   // Initial case: If tree is empty, insert a new node at the root
   if (rootPtr == nullptr) {
      // cout << "BSTGen.Inserting at root!" << endl; // DEBUG

      // X----------------X
      // |    BREAKING    | - LLC keyword being set to "." by LLC.LLC()
      // X----------------X

      rootPtr = new NodeGeneric<typeT>(someData); // BUG - Should not be calling the generic node constructor...
      // cout << endl << endl << "New node created with data and assigned to BST rootPtr. \nBSTGeneric.insert() completed successfully." << endl;
      // cout << "RootPtr: " << rootPtr->nodeData << endl << endl; // DEBUG
      // And halt execution
      return(true);
   }
   // Otherwise, while the current node pointer is not off the end of a leaf...
   while (currNodePtr != nullptr) {
      // Test if the node to insert is equal, greater, or lesser
      if (currNodePtr->nodeData == someData) {
         // If equal, check if it's deleted
         if (currNodePtr->isDeleted == true) {
            // Undelete it if so
            currNodePtr->isDeleted = false;
         }
         else {
            // cout << "This node already exists: " << someData << endl; // DEBUG
            return(false);
         }
      }
      // Otherwise, if the insert data is less than the current node data...
      else if (someData < currNodePtr->nodeData) {
         // Move left
         prevNodePtr = currNodePtr;
         currNodePtr = currNodePtr->leftPtr;
      }
      // Otherwise, if the insert data is greater than the current node data...
      else if (someData > currNodePtr->nodeData) {
         // Move right
         prevNodePtr = currNodePtr;
         currNodePtr = currNodePtr->rightPtr;
      }
   } // Ending tree descent. Curr is now nullptr, Prev is the node pointing at Curr

   // If insert data is less than this node data, insert left
   if (someData < prevNodePtr->nodeData) {
      prevNodePtr->leftPtr = new NodeGeneric<typeT>(someData);
   }
   // Otherwise, insert right
   else if (someData > prevNodePtr->nodeData) {
      prevNodePtr->rightPtr = new NodeGeneric<typeT>(someData);
   }
   return(true);
}

// #obliviate() - Deletes all nodes within the BST, leaving headPtr pointing at nullptr
template <class typeT>
void BSTGeneric<typeT>::obliviate() {
   cout << "Obliviate!" << endl; // DEBUG
   deletePostOrder();
}

// #setDelete() -
template <class typeT>
bool BSTGeneric<typeT>::setDelete(typeT someData) {
   NodeGeneric<typeT>* targetNodePtr = this->retrieve(someData);
   if (targetNodePtr != nullptr) {
      targetNodePtr->isDeleted = true;
      return(true);
   }
   return(false);
}

// #traversePreOrder() - Helper method
template <class typeT>
bool BSTGeneric<typeT>::traversePreOrder() {
   cout << "Pre-Order : " << endl;
   // Check for empty tree
   if (rootPtr == nullptr) {
      cout << "No traversal possible. This tree is empty." << endl;
      return (false);
   }
   // Otherwise, return the results of the recursive traversal
   else {
      return (traversePreOrder(rootPtr));
   }
}

// #traversePreOrder(nodePtr) - Recursive method
template <class typeT>
bool BSTGeneric<typeT>::traversePreOrder(NodeGeneric<typeT>* thisNode) {
   visit(thisNode);
   // cout << " , "; // DEBUG
   if (thisNode->leftPtr != nullptr) {
      traversePreOrder(thisNode->leftPtr);
   }
   if (thisNode->rightPtr != nullptr) {
      traversePreOrder(thisNode->rightPtr);
   }
   return(true);
}

// #traverseInOrder() - Helper method
template <class typeT>
bool BSTGeneric<typeT>::traverseInOrder() {
   cout << "In-Order  : " << endl;
   // Check for empty tree
   if (rootPtr == nullptr) {
      cout << "No traversal possible. This tree is empty." << endl;
      return (false);
   }
   // Otherwise, return the results of the recursive traversal
   else {
      return (traverseInOrder(rootPtr));
   }
}

// #traverseInOrder(nodePtr) - Recursive method
template <class typeT>
bool BSTGeneric<typeT>::traverseInOrder(NodeGeneric<typeT>* thisNode) {
   if (thisNode->leftPtr != nullptr) {
      traverseInOrder(thisNode->leftPtr);
   }
   visit(thisNode);
   // cout << " , "; // DEBUG
   if (thisNode->rightPtr != nullptr) {
      traverseInOrder(thisNode->rightPtr);
   }
   return(true);
}

// #traversePostOrder() - Helper method
template <class typeT>
bool BSTGeneric<typeT>::traversePostOrder() {
   cout << "Post-Order: " << endl;
   // Check for empty tree
   if (rootPtr == nullptr) {
      cout << "No traversal possible. This tree is empty." << endl;
      return (false);
   }
   // Otherwise, return the results of the recursive traversal
   else {
      return (traversePostOrder(rootPtr));
   }
}

// #traversePostOrder(nodePtr) - Recursive method
template <class typeT>
bool BSTGeneric<typeT>::traversePostOrder(NodeGeneric<typeT>* thisNode) {
   if (thisNode->leftPtr != nullptr) {
      traversePostOrder(thisNode->leftPtr);
   }

   if (thisNode->rightPtr != nullptr) {
      traversePostOrder(thisNode->rightPtr);
   }

   visit(thisNode);
   // cout << " , "; // DEBUG
   return(true);
}

// X-----------------------X
// |    #visit(nodePtr)    |
// X-----------------------X
// Visits the node indicated by sending the nodeData content to cout.
template <class typeT>
void BSTGeneric<typeT>::visit(NodeGeneric<typeT>* thisNodePtr) {
   // Visit the node, but only perform an action if the node is undeleted
   if (thisNodePtr->isDeleted == false) {
      // Send the nodeData to the output stream
      // In the case of a LinkedListContext, that's an iteration down the linked list
      cout << thisNodePtr->nodeData;
   }
   // Otherwise the node is deleted, so do nothing.
   else {
      // cout << "This node is deleted." << endl; // DEBUG
   }
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

// X---------------------X
// |    #find(string)    |
// X---------------------X
// Finds a node with value of string
template <class typeT>
bool BSTGeneric<typeT>::find(string someValue) {
   // If the tree is empty, do nothing
   if (rootPtr == nullptr) {
      cout << "No value found. This tree is empty." << endl;
      return(false);
   }
   // Otherwise, start at the rootPtr
   else {
      NodeGeneric<typeT>* currPtr = rootPtr;
      // While we haven't run off the end of the tree...
      while (currPtr != nullptr) {
         // Found it! (And it's undeleted)
         if (currPtr->nodeData == someValue && currPtr->isDeleted == false) {
            return(true);
         }
         // Found it! (But it's deleted)
         else if (currPtr->nodeData == someValue && currPtr->isDeleted == true) {
            return(false);
         }
         else if (someValue < currPtr->nodeData) {
            currPtr = currPtr->leftPtr;
         }
         else if (someValue > currPtr->nodeData) {
            currPtr = currPtr->rightPtr;
         }
      } // Closing while loop. We've either exited (found the value) or run off the tree
      return(false);
   }
}

// #printout() - Debug method to print out the nodes in pre-, in-, and post-order traversals
template <class typeT>
void BSTGeneric<typeT>::printout() {
   // cout << "Printout() called." << endl; // DEBUG
   traversePreOrder();
   cout << endl;
   traverseInOrder();
   cout << endl;
   traversePostOrder();
   cout << endl;
}
/*
// #retrieve() - 
template <class typeT>
NodeGeneric<typeT>* BSTGeneric<typeT>::retrieve(typeT someData) {
   // If the node is confirmed to be in the tree and is not deleted...
   if (this->find(someValue.keyword) == true) {
      NodeGeneric<typeT>* currPtr = rootPtr;
      // Go find it.
      while (currPtr != nullptr) {
         // Found it!
         if (currPtr->nodeData == someData && currPtr->isDeleted == false) {
            // Send the current node back.
            return(currPtr);
         }
         // Searching for it.
         else if (someData < currPtr->nodeData) {
            currPtr = currPtr->leftPtr;
         }
         else if (someData > currPtr->nodeData) {
            currPtr = currPtr->rightPtr;
         }
      } // Closing while
   } // Closing if
   return(nullptr);
} // Closing retrieve()
*/


// X--------------------------------X
// |                                |
// |    CONSTRUCTORS/DESTRUCTORS    |
// |                                |
// X--------------------------------X

// #BSTGeneric() - Default constructor
template <class typeT>
BSTGeneric<typeT>::BSTGeneric() {
   // Make a default node of typeT
   LinkedListContext defaultList(); // TODO: Remove this
   this->rootPtr = nullptr;
   // cout << "Default genericBST constructor called. RootPtr set to nullptr" << endl; // DEBUG
}

// #BSTGeneric(string) - Constructor from file address
template <class typeT>
BSTGeneric<typeT>::BSTGeneric(string fileAddress) {

   // String for storing a single word
   string aWord;
   // Generate the Input File Stream (ifstream) object
   ifstream fileInputObj;
   fileInputObj.open(fileAddress);
   // Confirm that file was opened. Report otherwise if not.
   if (!fileInputObj) {
    cout << "Unable to open file";
   }
   // Read the file
   while (fileInputObj >> aWord) {
      // Construct a node from the next word of the stopword list
      // cout << "Building a node from: " << aWord << endl; // DEBUG
      // Add this to the tree (rootPtr)
      // cout << "Inserting..." << endl; // DEBUG
      this->insert(aWord);
   }
   // After reading from the file, close the stream
   fileInputObj.close();
}

/*
// #BSTGeneric(typeT) - Constructor by datatype
template <class typeT>
BSTGeneric<typeT>::BSTGeneric(typeT someData, int signature) {
   // Make a node of typeT
   cout << "Constructor(typeT) called: "; // DEBUG
   rootPtr = new NodeGeneric<typeT>(someData);
}
*/

// #~BSTGeneric() - Destructor
template <class typeT>
BSTGeneric<typeT>::~BSTGeneric() {
   // cout << "BSTGeneric Destructor called." << endl; // DEBUG
   this->obliviate();
}


// X-------------------------X
// |                         |
// |    GETTERS / SETTERS    |
// |                         |
// X-------------------------X

// #getRootValue() - 
template <class typeT>
typeT& BSTGeneric<typeT>::getRootValue() {
   return rootPtr->nodeData;
}

// #getValue() - 
template <class typeT>
string BSTGeneric<typeT>::getValue() {
   return BSTtreeData;
}

// #setValue() - 
template <class typeT>
void BSTGeneric<typeT>::setValue( string someValue ) {
   BSTtreeData = someValue;
}
