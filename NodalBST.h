#pragma once
using namespace std;

template<class typeT>
class NodalBST {

private:
   typeT objData; // DEBUG - not used
   typeT variable2; // DEBUG - also not used


public:








// X------------------X
// |                  |
// |    STRUCTURES    |
// |                  |
// X------------------X

   // Begin struct
   template<class typeT>
   struct BSTNode {
      typeT nodeData;
      BSTNode<typeT>* leftPtr;
      BSTNode<typeT>* rightPtr;
      bool isDeleted;

      // X---- NODE CONSTRUCTORS ----X
      template<class typeT>
      BSTNode();
   }; // End struct

// X---------------------X
// |                     |
// |    PUBLIC FIELDS    |
// |                     |
// X---------------------X
   BSTNode* headPtr;

// X----------------------X
// |                      |
// |    PUBLIC METHODS    |
// |                      |
// X----------------------X




   // Getter
   typeT GetValue();



   // Setter
   void SetValue( typeT someValue );

// X--------------------------------X
// |                                |
// |    CONSTRUCTORS/DESTRUCTORS    |
// |                                |
// X--------------------------------X

   // Default constructor
   NodalBST();

};

// #include "NodalBST.cpp"
