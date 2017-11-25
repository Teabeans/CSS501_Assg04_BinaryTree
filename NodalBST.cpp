#include "NodalBST.h"
using namespace std;

template <class typeT>
typeT objData;

// Default constructor
template <class typeT>
NodalBST<typeT>::NodalBST() {
}

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
