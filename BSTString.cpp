#include <iostream>
#include <string>
#include <fstream>

#include "BSTString.h"

// Node definition
#include "NodeString.cpp"

using namespace std;

string treeData = "";

NodeString* rootPtr = NULL;

// #insert() -
bool BSTString::insert(string aWord) {
//   cout << "Insert() called" << endl; // DEBUG
//   cout << "WordData: " << aWord << endl; // DEBUG
   NodeString* curr = rootPtr;
   NodeString* prev = nullptr;
   // Initial case: If tree is empty, insert this node at the root
   if (rootPtr == NULL) {
      rootPtr = new NodeString(aWord);
      // And halt execution
      return(true);
   }

   // Otherwise, while the current node pointer is not off the end of a leaf...
   while (curr != nullptr) {
      // Test if the node to insert is equal, greater, or lesser
      if (aWord == curr->nodeData) {
         // If equal, check if it's deleted
         if (curr->isDeleted == true) {
            // Undelete it if so
            curr->isDeleted = false;
         }
         else {
            cout << "This word already exists: " << aWord << endl; // DEBUG
            return(false);
         }

      }
      // Otherwise, if the insert data is less than the current node data...
      else if (aWord < curr->nodeData) {
         // Move left
         prev = curr;
         curr = curr->leftPtr;
      }
      // Otherwise, if the insert data is greater than the current node data...
      else if (aWord > curr->nodeData) {
         // Move right
         prev = curr;
         curr = curr->rightPtr;
      }
   } // Ending tree descent. Curr is now nullptr, Prev is the node pointing at Curr

   // If insert data is less than this node data, insert left
   if (aWord < prev->nodeData) {
      prev->leftPtr = new NodeString(aWord);
   }
   // Otherwise, insert right
   else if (aWord > prev->nodeData) {
      prev->rightPtr = new NodeString(aWord);
   }
   return(true);
}

// #setDelete() -
bool BSTString::setDelete(string aWord) {
   NodeString* targetNodePtr = this->retrieve(aWord);
   if (targetNodePtr != nullptr) {
      targetNodePtr->isDeleted = true;
      return(true);
   }
   return(false);
}

// #traversePreOrder() - Helper method
bool BSTString::traversePreOrder() {
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
bool BSTString::traversePreOrder(NodeString* thisNode) {
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


// #traverseInOrder()
bool BSTString::traverseInOrder() {
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
bool BSTString::traverseInOrder(NodeString* thisNode) {
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
bool BSTString::traversePostOrder() {
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


bool BSTString::traversePostOrder(NodeString* thisNode) {
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

// #visit() - Appends the node data to the string
void BSTString::visit(NodeString* thisNodePtr) {
   // Visit the node, but only perform an action if the node is undeleted
   if (thisNodePtr->isDeleted == false) {
      cout << thisNodePtr->nodeData; // DEBUG
   }
}

// Default constructor
BSTString::BSTString() {
   // Make a node<string> holding the word "Mulberry"
   rootPtr = new NodeString("mulberry");
   cout << rootPtr->nodeData; // DEBUG
}

// Constructor from file address
BSTString::BSTString(string fileAddress) {
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
      this->insert(aWord);
   }
   // After reading from the file, close the stream
   fileInputObj.close();
}

// #retrieve()
NodeString* BSTString::retrieve(string someValue) {
   // If the node is confirmed to be in the tree and is not deleted...
   if (this->find(someValue) == true) {
      NodeString* currPtr = rootPtr;
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



// #find()
bool BSTString::find(string someValue) {
   // If the tree is empty, do nothing
   if (rootPtr == nullptr) {
      cout << "No value found. This tree is empty." << endl;
      return(false);
   }
   // Otherwise, start at the rootPtr
   else {
      NodeString* currPtr = rootPtr;
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


// #printout()
void BSTString::printout() {
   cout << "Printout() called." << endl; // DEBUG
   traversePreOrder();
   cout << endl;
   traverseInOrder();
   cout << endl;
   traversePostOrder();
   cout << endl;
}

// Getters
string BSTString::getValue() {
   return treeData;
}

string BSTString::getRootValue() {
   return rootPtr->nodeData;
}

// Setter
void BSTString::setValue( string someValue ) {
   treeData = someValue; // Set the received value to the generic datatype object m_obj
}
