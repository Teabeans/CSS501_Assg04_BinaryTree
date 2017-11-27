#pragma once
#include <string>
#include "LinkedListContext.h"
using namespace std;

struct NodeConcordance {
   LinkedListContext nodeData;
   bool isDeleted;
   NodeConcordance* leftPtr;
   NodeConcordance* rightPtr;

   NodeConcordance() {
      isDeleted = 1;
      leftPtr = nullptr;
      rightPtr = nullptr;
   }

   // TODO: 
   NodeConcordance(LinkedListContext someData) {
      nodeData = someData;
      isDeleted = 0;
      leftPtr = nullptr;
      rightPtr = nullptr;
   }
};
