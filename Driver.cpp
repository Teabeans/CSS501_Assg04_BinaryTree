// Tim Lum
// twhlum@gmail.com
// 2017.11.12
// For the University of Washington Bothell CSS 501A
// Autumn 2017, Graduate Certificate in Software Design & Development (GCSDD)
//
// File Description:
// This file is the implementation file for the Puzzle class.
// Note: The Puzzle class will return the first valid solution it arrives at.
// Note: The Puzzle class will not prevent Sudoku rule violations on input.
// Note: The Puzzle class will accept invalid Sudoku problems that have no solution.
//
// Package files:
// Driver.cpp
// File1.h
// File1.cpp
// File2.h
// File2.cpp
//
// Acknowledgements:
// Source material from:
// University of Washington Bothell
// CSS 501A Data Structures And Object-Oriented Programming I
// "Design and Coding Standards"
// Michael Stiber
//
// Template author:
// Tim Lum (twhlum@gmail.com)
//
// License:
// This software is published under the GNU general license which guarantees
// end users the freedom to run, study, share and modify the software.
// https://www.gnu.org/licenses/gpl.html
//
// Code Standards:
// I. Comment at beginning of file (above) stating (at a minimum):
//    A. File Name
//    B. Author Name
//    C. Date
//    D. Description of code purpose 
// II. Indentation:
//    A. 3 whitespaces ("   ")
//    B. May vary depending on language and instructor
// III. Variables:
//    A. Descriptive, legible name
//    B. Comment over any variable declaration describing:
//       0. Its use in the algorithm
//       1. Invariant information such as legal ranges of values
// IV. Class Files:
//    A. Separate *.cpp and *.h files should be used for each class.
//    B. Files names must exactly match class names (case-sensitive)
// V. Includes:
//    A. Calls for content ("#include") from the Standard Template Library (STL) should be formatted as follows:
//       0. DO type:     #include <vector>
//       1. Do NOT type: #include <vector.h>
//    B. You may use the directive "using namespace std;"
//       0. ??? (?CONFIRM?)
// VI. Classes:
//    A. Return values:
//       0. Do NOT return references to internal class structures.
//       1. Do NOT return pointers to internal class structures.
//    B. Do NOT expose any details of the internal implementation.
// VII. Functions + Methods:
//    A. Functions should be used for appropriate operations.
//    B. Reference arguments should be used only when necessary.
//    C. The (return?CONFIRM?) type of each function must be declared
//       0. Use 'void' when necessary
//    D. Declare as 'const' (unalterable) when no modification is made to the object state
//       0. UML 'query' property (?CONFIRM?)
// VIII. Function Comments:
//    A. DO include a comment prior to each function which includes the function's:
//       0. Purpose - Why does the function exist?
//       1. Parameters - What fields does the function contain?
//       2. Preconditions - What conditions must be true prior to the function call?
//       3. Postconditions - What conditions must be true after the function call?
//       4. Return value - What is the nature and range of the value returned by the function?
//       5. Functions called - What other functions are called by this function?
// IX. Loop invariants
//    A. Each loop should be commented with 'invariant' information (?CONFIRM?)
// X. Assertions:
//    A. May be comments or the 'assert()' feature.
//    B. Insert where useful to explain important features or subtle logic.
//    C. What, exactly, is an assertion (?CONFIRM?)
// XI. Prohibited (unless justified):
//    A. Global variables
//    B. "Gotos" (?CONFIRM?)
//
// Special instructions:
// To install G++:
// sudo apt install g++
// 
// To update Linux:
// sudo apt-get update && sudo apt-get install
// sudo apt-get update
//
// To make a new .cpp file in Linux:
// nano <file name>.cpp
//
// To make a new .h file in Linux:
// nano <file name>.h
//
// To make a new .txt file in Linux:
// nano <file name>.txt
//
// To compile in g++:
// g++ -std=c++11 *.cpp
//
// To run with test input:
// ./a.out < TestInput.txt
//
// To run Valgrind:
// Install Valgrind:
// sudo apt install valgrind
//
// Run with:
// valgrind --leak-check=full <file folder path>/<file name, usually a.out>
// OR
// valgrind --leak-check=full --show-leak-kinds=all <file path>/a.out
//
// ie.
// valgrind --leak-check=full /home/Teabean/a.out
// OR
// valgrind --leak-check=full --show-leak-kinds=all /home/Teabean/a.out
// OR
// valgrind --leak-check=full --show-leak-kinds=all /home/Teabean/a.out < /Sudoku.txt
//
// To load a text file as cin input in Visual Studios:
// 1. Go to the top menu bar => Debug => <ProjectName> Properties => Debugging => Command Arguments =>
// 2. "< <Filepath>/<Filename>.txt" ie. "< /Sudoku.txt"
// ie. < /Sudoku.txt
//
// ---- BEGIN STUDENT CODE ----

// X---------X
// |  INDEX  |
// X---------X
// Include Statements
// Control Variables
// Program Body



// X--------------------------X
// |                          |
// |    INCLUDE STATEMENTS    |
// |                          |
// X--------------------------X

// Necessary for input-output operations
#include <iostream>

// Necessary for string operations
#include <string>

// Necessary for stream operations
//#include <sstream>

// Header for the Square class
//#include "genericBST.h"

// Header for the TemplateExample class
#include "BSTString.h"
#include "NodeString.cpp"
#include "LinkedListContext.h"
#include "NodeContext.cpp"
#include "NodeConcordance.cpp"
#include "BSTConcordance.h"
#include "NodeGeneric.cpp"
#include "BSTGeneric.cpp"
#include "ReaderCorpus.h"

// Header for the StopwordBST
// #include "stopwordBST.h"

// Header for the Puzzle class
// #include "concordanceBST.h"

// Methods not found in the current namespace are directed to check the 'std' namespace
using namespace std;



// X------------------------X
// |                        |
// |    GLOBAL VARIABLES    |
// |                        |
// X------------------------X

// None (prohibited for this course)



int main( int argc, char* argv[] ) {  // Array of command-line arguments strings  

// X-------------------------X
// |                         |
// |    CONTROL VARIABLES    |
// |                         |
// X-------------------------X

   // Assignment controller
   bool assignmentSwitch = 1;

   // BSTString test
   bool unitTest00 = 0;

   // Command line argument reception test
   bool unitTest01 = 1;

   // File load test and tree build
   bool unitTest02 = 0;

   // toString() test
   bool unitTest03 = 0;

   // find() test
   bool unitTest04 = 0;

   // setDelete() test
   bool unitTest05 = 0;

   // Context node test
   bool unitTest06 = 1;

   // Linked List of contexts test (data field of a ConcordanceBST)
   bool unitTest07 = 1;

   // BST Concordances instantiation test
   bool unitTest08 = 1;

   // Generic node instantiation and pointer assignment test
   bool unitTest09 = 1;

   // Generic tree instantiation
   bool unitTest10 = 1;

   // Corpus reader tests
   bool unitTest11 = 1;

   bool unitTest12 = 0;

   bool unitTest13 = 0;

   bool unitTest14 = 0;

   bool unitTest15 = 0;

// X--------------------X
// |                    |
// |    PROGRAM BODY    |
// |                    |
// X--------------------X



// X------------------X
// |                  |
// |    UNIT TESTS    |
// |                  |
// X------------------X

   // Test case 00: BSTString test
   if (unitTest00 == true) {
      cout << "UnitTest00: BSTString Instantiation test" << endl;
      BSTString testObj;
      cout << "Root node data: " << testObj.getRootValue() << endl;
      cout << endl;
   }

   // Test case 01: Command line argument reception test
   if (unitTest01 == true) {
      cout << "UnitTest01: Command Line Argument test" << endl;
      string programLocation = argv[0];
      string fileLocation = argv[1];
      cout << "Arg[0] Program Location: " << programLocation << endl;
      cout << "Arg[1] File Location:    " << fileLocation << endl;
      cout << endl;
   }

   // Test case 02: File load test and tree build test
   if (unitTest02 == true) {
      cout << "UnitTest02: File load test (stopwords)" << endl;
      string fileLocation = "stopwords.txt";
      BSTString fileReader(fileLocation);
      cout << endl;
   }

   // Test case 03: printout() test
   if (unitTest03 == true) {
      cout << "UnitTest03: Stopword tree build test" << endl;
      BSTString fileReader("stopwords.txt");
      fileReader.printout();
      cout << endl;
   }

   // Test case 04: find() test
   if (unitTest04 == true) {
      cout << "UnitTest04: Find() test" << endl;
      BSTString findTester("stopwords.txt");
      cout << "hooligan  : " << findTester.find("hooligan") << endl;
      cout << "nibleheim : " << findTester.find("nibleheim") << endl;
      cout << endl;
   }

   // Test case 05: setDelete() test
   if (unitTest05 == true) {
      cout << "UnitTest05: setDelete() test" << endl;
      BSTString deleteTester("stopwords.txt");
      deleteTester.printout();
      cout << "setDelete(Hooligan)  : " << deleteTester.setDelete("hooligan") << endl;
      cout << "setDelete(nibleheim) : " << deleteTester.setDelete("nibleheim") << endl;
      deleteTester.printout();
      cout << endl;
   }

   // Test case 06: Node context test
   if (unitTest06 == true) {
      cout << "UnitTest06: Context node tests" << endl;
      NodeContext testNode("beforetest", "aftertest");
      cout << "prevContext : " << testNode.prevContext << endl;
      cout << "postContext : " << testNode.postContext << endl;
      cout << "nextPtr     : " << testNode.nextPtr << endl;
      cout << "Making second node..." << endl;
      NodeContext pointTest("pretest", "posttest");
      cout << "prevContext : " << pointTest.prevContext << endl;
      cout << "postContext : " << pointTest.postContext << endl;
      cout << "nextPtr     : " << pointTest.nextPtr << endl;
      // Link two nodes
      cout << "Linking..." << endl;
      testNode.nextPtr = &pointTest;
      cout << "nextPtr      : " << testNode.nextPtr << endl;
      cout << "nextPtr.data : " << testNode.nextPtr->prevContext << testNode.nextPtr->postContext << endl;
      cout << endl;
   }

   // Test case 07: Linked List of Contexts test (data field of a Concordance BST)
   if (unitTest07 == true) {
      cout << "UnitTest07: Linked list instantiation test" << endl;
      LinkedListContext testList();
      // Headnode constructor test
      LinkedListContext testList2("keyword!", "prevContext", "postContext");
      cout << "TestList keyword  : " << testList2.keyword << endl;
      cout << "Headnode context  : " << testList2.headNodePtr->prevContext << endl;
      cout << "Headnode context  : " << testList2.headNodePtr->postContext << endl;
      cout << "Headnode nextPtr  : " << testList2.headNodePtr->nextPtr << endl;
      // Append() tests
      cout << "Appending..." << endl;
      testList2.append("nextString", "nextnextString");
      cout << "Headnode nextPtr  : " << testList2.headNodePtr->nextPtr << endl;
      cout << "Bodynode context  : " << testList2.headNodePtr->nextPtr->prevContext << endl;
      cout << "Bodynode context  : " << testList2.headNodePtr->nextPtr->postContext << endl;
      cout << "Bodynode nextPtr  : " << testList2.headNodePtr->nextPtr->nextPtr << endl;
      // toString() tests
      testList2.append("to be or not to", "that is the question quack");
      cout << "Printing toString()..." << endl;
      cout << testList2.toString(11) << endl;
      // getMaxPrevContextLength() test
      cout << "Maximum prev context length: " << testList2.getMaxPrevContextLength() << endl;
      cout << endl;
   }

   // Test case 08: BST Concordances instantiation test
   if (unitTest08 == true) {
      cout << "UnitTest08: ConcordanceBST instantiation test" << endl;
      BSTConcordance testConcordance;
      cout << testConcordance.rootPtr;
      cout << endl << endl;
   }

   // Test case 09: Generic node instantiation and pointer assignment test
   if (unitTest09 == true) {
      cout << "UnitTest09: NodeGeneric instantiation test" << endl;

      // Generic node of type int
      NodeGeneric<int> TempNodeInt;
      NodeGeneric<int>* TempNodeIntPtr;
      TempNodeIntPtr = &TempNodeInt;
      TempNodeIntPtr->nodeData = 12345;
      int outputInt = TempNodeIntPtr->nodeData;
      cout << "NodeGeneric<int> value ('12345' expected): " << outputInt << endl;

      // Generic node of type string
      NodeGeneric<string> TempNodeString;
      NodeGeneric<string>* TempNodeStringPtr;
      TempNodeStringPtr = &TempNodeString;
      TempNodeStringPtr->nodeData = "ABCDE";
      string outputString = TempNodeStringPtr->nodeData;
      cout << "NodeGeneric<string> value ('ABCDE' expected): " << outputString << endl;

      // Generic node of type LinkedListContext
      NodeGeneric<LinkedListContext> TempNodeLLC;
      NodeGeneric<LinkedListContext>* TempNodeLLCPtr;
      TempNodeLLCPtr = &TempNodeLLC;
      TempNodeLLCPtr->nodeData = LinkedListContext("this", "is", "sparta");
      // TempNodeLLC.nodeData.append("this", "the beginning"); // Test the append() function of the LinkedListContext
      LinkedListContext outputLLC = TempNodeLLCPtr->nodeData;
      cout << "NodeGeneric<string> value ('this is sparta' expected): " << outputLLC << endl;

      cout << endl;
   }

   // Test case 10: Generic tree instantiation
   if (unitTest10 == true) {
      cout << "UnitTest10: GenericTree instantiation test" << endl;
      BSTGeneric<int> TempTreeInt;
      cout << endl;
   }

   // Test case 11: Corpus reader tests
   if (unitTest11 == true) {
      cout << "UnitTest11: Corpus Reader instantiation test" << endl;

      // Instantiation test
      ReaderCorpus testReader;
      cout << "Context Words: " << testReader.getContextWords() << endl;
      cout << "PrevContext: " << testReader.getPrevContext() << endl;
      cout << "PostContext: " << testReader.getPostContext() << endl;

      // File load from argv[1] test
      testReader.loadFile(argv[1]);

      // Advance() test
      testReader.advance();
      testReader.advance();
      testReader.advance();
      testReader.advance();
      testReader.advance();
      testReader.advance();
      testReader.advance();
      testReader.advance();
      testReader.advance();
      testReader.advance();
      testReader.advance();
      cout << "Context Words: " << testReader.getContextWords() << endl;
      cout << "PrevContext: " << testReader.getPrevContext() << endl;
      cout << "CurrWord: " << testReader.getCurrWord() << endl;
      cout << "PostContext: " << testReader.getPostContext() << endl;

      // Linked list creation test
      cout << "LinkedList creation test" << endl;
      LinkedListContext testList = testReader.makeLinkedListContext();
      cout << testList.toString(10) << endl;

      // End-of-file test
      cout << "End-Of-File test" << endl;
      for (int i = 0 ; i < 40 ; i++ ) {
         testReader.advance();
         cout << "Context Words: " << testReader.getContextWords() << endl;
      }
      cout << endl;
   }


// X-------------------------X
// |                         |
// |    ASSIGNMENT DRIVER    |
// |                         |
// X-------------------------X
   if (assignmentSwitch == true) {
      cout << "Running the assignment..." << endl;

   // Make a stoplistBST
      BSTGeneric<string> stopListBST("stopwords.txt");

      stopListBST.printout(); // DEBUG

   // Make a concordanceBST
      LinkedListContext constructoPresto;
      BSTGeneric<LinkedListContext> concordanceBST(constructoPresto, 0);

      concordanceBST.printout();

   // Make a corpus reader

   // Loop the reader, sending keywords to the concordanceBST




   
   
   }


//   stopwordBST stopwordList;
//   cout << stopwordList.toString();

   return(0);
}

// ---- END STUDENT CODE ----
