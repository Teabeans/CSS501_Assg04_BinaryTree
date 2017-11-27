#pragma once
#include <string>
using namespace std;

struct NodeContext {
   string prevContext;
   string postContext;
   NodeContext* nextPtr;
   int lengthOfPrevContext;

   NodeContext() {
      prevContext = "Foo Bar Baz";
      postContext = "Zab Rab Oof";
      nextPtr = nullptr;
   }

   NodeContext(string wordsBefore, string wordsAfter) {
      prevContext = wordsBefore;
      postContext = wordsAfter;
      lengthOfPrevContext = wordsBefore.length();
      nextPtr = nullptr;
   }
};
