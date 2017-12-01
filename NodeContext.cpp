#pragma once
#include <string>
using namespace std;

struct NodeContext {
   string prevContext;
   string postContext;
   NodeContext* nextPtr;
   int lengthOfPrevContext;

   NodeContext() {
      prevContext = "Default NodeContext()";
      postContext = "For Test Purpose Only";
      nextPtr = nullptr;
      lengthOfPrevContext = 0;
   }

   NodeContext(string wordsBefore, string wordsAfter) {
      prevContext = wordsBefore;
      postContext = wordsAfter;
      lengthOfPrevContext = wordsBefore.length();
      nextPtr = nullptr;
   }
};
