// X--------------------------X
// |                          |
// |    INCLUDE STATEMENTS    |
// |                          |
// X--------------------------X

#include <iostream>
#include <string>
#include <fstream>

#include "BSTConcordance.h"

// Node definition
#include "NodeString.cpp" // For a string BST
#include "NodeContext.cpp" // For a context linked list
#include "NodeConcordance.cpp" // For a concordance BST

using namespace std;



// X----------------------X
// |                      |
// |    PRIVATE FIELDS    |
// |                      |
// X----------------------X

string contextWords[11];

string BSTtreeData = "";

NodeConcordance* rootPtr = NULL;



// X-----------------------X
// |                       |
// |    PRIVATE METHODS    |
// |                       |
// X-----------------------X

// #insert(string) -
bool BSTConcordance::insert(LinkedListContext someLinkedList) {
//   cout << "Insert() called" << endl; // DEBUG
//   cout << "WordData: " << aWord << endl; // DEBUG
   NodeConcordance* curr = rootPtr;
   NodeConcordance* prev = nullptr;
   // Initial case: If tree is empty, insert this node at the root
   if (rootPtr == NULL) {
      rootPtr = new NodeConcordance(someLinkedList);
      // And halt execution
      return(true);
   }

   // Otherwise, while the current node pointer is not off the end of a leaf...
   while (curr != nullptr) {
      // Test if the node to insert is equal, greater, or lesser
      if (someLinkedList == curr->nodeData) {
         // If equal, check if it's deleted
         if (curr->isDeleted == true) {
            // Undelete it if so
            curr->isDeleted = false;
         }
         else {
            cout << "This word already exists: " << someLinkedList << endl; // DEBUG
            return(false);
         }

      }
      // Otherwise, if the insert data is less than the current node data...
      else if (someLinkedList < curr->nodeData) {
         // Move left
         prev = curr;
         curr = curr->leftPtr;
      }
      // Otherwise, if the insert data is greater than the current node data...
      else if (someLinkedList > curr->nodeData) {
         // Move right
         prev = curr;
         curr = curr->rightPtr;
      }
   } // Ending tree descent. Curr is now nullptr, Prev is the node pointing at Curr

   // If insert data is less than this node data, insert left
   if (someLinkedList < prev->nodeData) {
      prev->leftPtr = new NodeConcordance(someLinkedList);
   }
   // Otherwise, insert right
   else if (someLinkedList > prev->nodeData) {
      prev->rightPtr = new NodeConcordance(someLinkedList);
   }
   return(true);
}

// #setDelete() -
bool BSTConcordance::setDelete(LinkedListContext someLinkedList) {
   NodeConcordance* targetNodePtr = this->retrieve(someLinkedList);
   if (targetNodePtr != nullptr) {
      targetNodePtr->isDeleted = true;
      return(true);
   }
   return(false);
}

// #traversePreOrder() - Helper method
bool BSTConcordance::traversePreOrder() {
   cout << "Pre-Order : ";
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
bool BSTConcordance::traversePreOrder(NodeConcordance* thisNode) {
   visit(thisNode);
   cout << " , ";
   if (thisNode->leftPtr != nullptr) {
      traversePreOrder(thisNode->leftPtr);
   }
   if (thisNode->rightPtr != nullptr) {
      traversePreOrder(thisNode->rightPtr);
   }
   return(true);
}

// #traverseInOrder() - Helper method
bool BSTConcordance::traverseInOrder() {
   cout << "In-Order  : ";
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
bool BSTConcordance::traverseInOrder(NodeConcordance* thisNode) {
   if (thisNode->leftPtr != nullptr) {
      traverseInOrder(thisNode->leftPtr);
   }
   visit(thisNode);
   cout << " , ";
   if (thisNode->rightPtr != nullptr) {
      traverseInOrder(thisNode->rightPtr);
   }
   return(true);
}

// #traversePostOrder() - Helper method
bool BSTConcordance::traversePostOrder() {
   cout << "Post-Order: ";
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
bool BSTConcordance::traversePostOrder(NodeConcordance* thisNode) {
   if (thisNode->leftPtr != nullptr) {
      traversePostOrder(thisNode->leftPtr);
   }

   if (thisNode->rightPtr != nullptr) {
      traversePostOrder(thisNode->rightPtr);
   }

   visit(thisNode);
   cout << " , ";
   return(true);
}

// #visit(NodeString*) - Appends the node data to the string
void BSTConcordance::visit(NodeConcordance* thisNodePtr) {
   // Visit the node, but only perform an action if the node is undeleted
   if (thisNodePtr->isDeleted == false) {
      cout << thisNodePtr->nodeData; // DEBUG
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

// #find(string) - Finds a node with value of string
bool BSTConcordance::find(string someValue) {
   // If the tree is empty, do nothing
   if (rootPtr == nullptr) {
      cout << "No value found. This tree is empty." << endl;
      return(false);
   }
   // Otherwise, start at the rootPtr
   else {
      NodeConcordance* currPtr = rootPtr;
      // While we haven't run off the end of the tree...
      while (currPtr != nullptr) {
         // Found it! (And it's undeleted)
         if (currPtr->nodeData.keyword == someValue && currPtr->isDeleted == false) {
            return(true);
         }
         // Found it! (But it's deleted)
         else if (currPtr->nodeData.keyword == someValue && currPtr->isDeleted == true) {
            return(false);
         }
         else if (someValue < currPtr->nodeData.keyword) {
            currPtr = currPtr->leftPtr;
         }
         else if (someValue > currPtr->nodeData.keyword) {
            currPtr = currPtr->rightPtr;
         }
      } // Closing while loop. We've either exited (found the value) or run off the tree
      return(false);
   }
}

// #printout() - Debug method to print out the nodes in pre-, in-, and post-order traversals
void BSTConcordance::printout() {
   cout << "Printout() called." << endl; // DEBUG
   traversePreOrder();
   cout << endl;
   traverseInOrder();
   cout << endl;
   traversePostOrder();
   cout << endl;
}

// #readin(string)
void BSTConcordance::readin(string fileLocation) {
   // Load the file from fileLocation
   // For the whole file...
   // parse a "word" off the file
   // Convert it to lowercase (toLower)
   // Attempt to shuffle contextWords[] down
   // Add word to contextWords[11]
   // Stitch contextWords[0-4]
   // Stitch contextWords[6-11]
   // Attempt to insert LinkedListContext
   // If new linked list is already on the tree (the keyword matches) - foundNode.append(prevContext, postContext)
}

// #retrieve() - 
NodeConcordance* BSTConcordance::retrieve(LinkedListContext someValue) {
   // If the node is confirmed to be in the tree and is not deleted...
   if (this->find(someValue.keyword) == true) {
      NodeConcordance* currPtr = rootPtr;
      // Go find it.
      while (currPtr != nullptr) {
         // Found it!
         if (currPtr->nodeData == someValue && currPtr->isDeleted == false) {
            // Send the current node back.
            return(currPtr);
         }
         // Searching for it.
         else if (someValue < currPtr->nodeData) {
            currPtr = currPtr->leftPtr;
         }
         else if (someValue > currPtr->nodeData) {
            currPtr = currPtr->rightPtr;
         }
      } // Closing while
   } // Closing if
   return(nullptr);
} // Closing retrieve()



// X--------------------------------X
// |                                |
// |    CONSTRUCTORS/DESTRUCTORS    |
// |                                |
// X--------------------------------X

// #BSTConcordance() - Default constructor
BSTConcordance::BSTConcordance() {
   // Make a node<string> holding the word "Mulberry"
   rootPtr = new NodeConcordance(LinkedListContext("mulberry","",""));
   cout << rootPtr->nodeData; // DEBUG
}

// #BSTConcordance(string) - Constructor from file address
BSTConcordance::BSTConcordance(string fileAddress) {

      // Load the file from fileLocation
   // For the whole file...
   // parse a "word" off the file
   // Convert it to lowercase (toLower)
   // Attempt to shuffle contextWords[] down
   // Add word to contextWords[11]
   // Stitch contextWords[0-4]
   // Stitch contextWords[6-11]
   // Attempt to insert LinkedListContext
   // If new linked list is already on the tree (the keyword matches) - foundNode.append(prevContext, postContext)

   // String for storing a single word
   string aWord;
   // Generate the Input File Stream (ifstream) object
   ifstream fileInputObj;
   fileInputObj.open(fileAddress);

   // Confirm that file was opened. Report otherwise if not.
   if (!fileInputObj) {
    cout << "Unable to open file Stopword list";
   }

   // Read the file
   while (fileInputObj >> aWord) {
      // Construct a node from the next word of the stopword list
      // cout << "Building a node from: " << aWord << endl; // DEBUG
      // Add this to the tree (rootPtr)
      // cout << "Inserting..." << endl; // DEBUG
      this->insert(LinkedListContext(aWord,"",""));
   }
   // After reading from the file, close the stream
   fileInputObj.close();
}



// X-------------------------X
// |                         |
// |    GETTERS / SETTERS    |
// |                         |
// X-------------------------X

// #getRootValue() - 
LinkedListContext& BSTConcordance::getRootValue() {
   return rootPtr->nodeData;
}

// #getValue() - 
string BSTConcordance::getValue() {
   return BSTtreeData;
}

// #setValue() - 
void BSTConcordance::setValue( string someValue ) {
   BSTtreeData = someValue;

}
