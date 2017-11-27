#pragma once
#include <string>
using namespace std;

struct NodeConcordance {
   string nodeData;
   bool isDeleted;
   NodeConcordance* leftPtr;
   NodeConcordance* rightPtr;

   NodeConcordance() {
      isDeleted = 1;
      leftPtr = nullptr;
      rightPtr = nullptr;
   }

   NodeConcordance(string someData) {
      nodeData = someData;
      isDeleted = 0;
      leftPtr = nullptr;
      rightPtr = nullptr;
   }
};
