#pragma once
#include <string>
using namespace std;

struct NodeString {
   string nodeData;
   bool isDeleted;
   NodeString* leftPtr;
   NodeString* rightPtr;

   NodeString() {
      isDeleted = 1;
      leftPtr = nullptr;
      rightPtr = nullptr;
   }

   NodeString(string someData) {
      nodeData = someData;
      isDeleted = 0;
      leftPtr = nullptr;
      rightPtr = nullptr;
   }
};
