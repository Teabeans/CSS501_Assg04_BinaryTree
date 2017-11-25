#include "NodalBST.h"
using namespace std;

template <class typeT>
typeT objData;

template <class typeT>
typeT variable2;

//template <class typeT>
//BSTNode* headPtr;



// X------------------X
// |                  |
// |    STRUCTURES    |
// |                  |
// X------------------X

template <class typeT>
struct BSTNode {
   typeT nodeData;
   BSTNode<typeT>* leftPtr;
   BSTNode<typeT>* rightPtr;
   bool isDeleted;

   // X---- CONSTRUCTORS ----X


   BSTNode(typeT someData) {
      // NOTE: Never initialize a generic type variable in a constructor
      nodeData = someData;
      isDeleted = true;
   }
}; // End struct

// X---------------------X
// |                     |
// |    PUBLIC FIELDS    |
// |                     |
// X---------------------X
template <class typeT>
BSTNode<typeT>* headPtr;

// X----------------------X
// |                      |
// |    PUBLIC METHODS    |
// |                      |
// X----------------------X

// Getter
template <class typeT>
typeT NodalBST<typeT>::GetValue() {
   return objData;
}

// Setter
template <class typeT>
void NodalBST<typeT>::SetValue( typeT someValue ) {
   objData = someValue; // Set the received value to the generic datatype object m_obj
}

// X--------------------------------X
// |                                |
// |    CONSTRUCTORS/DESTRUCTORS    |
// |                                |
// X--------------------------------X

// Default constructor
template <class typeT> NodalBST<typeT>::NodalBST() {
   cout << "Default constructor for NodalBST activated." << endl;
   headPtr = BSTNode<typeT>(typeT someData); // TODO: Add 'new'?
}
