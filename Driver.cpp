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
#include "NodalBST.h"
#include "NodalBST.cpp" // Commented out here, but appended to the end of TemplateExample.h
#include "GenericNode.cpp"

// Header for the Puzzle class
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

   // If true, uses an input to check row alignment
   bool stopwordInstantiate = 0;
   // If true, uses an input to check row alignment
   bool commandArgument = 1;
   // If true, attempts to read and parse a stopword list
   bool templateTest = 1;

   bool structTest = 1;

   bool BSTNodeTest = 0;
   // If true, attempts to read and parse a stopword list
   bool stopwordRead = 0;






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

   // Test case 00: stopwordBST object can be instantiated.
   if (stopwordInstantiate == true) {
   }

   // Test case 01: Confirm that command line argument can be received and accessed.
   if (commandArgument == true) {
      cout << "commandArgument == true" << endl;
      string programLocation = argv[0];
      string fileLocation = argv[1];
      cout << "Arg[0] Program Location: " << programLocation << endl;
      cout << "Arg[1] File Location:    " << fileLocation << endl;
      cout << endl;
   }

   // Test case 02: Confirm that templating of a class functions properly.
   if (templateTest == true) {
      NodalBST<int> tempObj;
      tempObj.SetValue( 2 );
      int nValue = tempObj.GetValue();
      cout << "nValue: " << nValue << endl;
   }

   // Test case 03: Confirm that templated node struct can be insantiated
   if (structTest == true) {
      cout << "structTest == true" << endl;
      GenericNode<string> testObj;
      cout << testObj.isDeleted << endl;
      cout << testObj.leftPtr << endl;
      cout << testObj.rightPtr << endl;
      testObj.nodeData = "Set this string";
      cout << testObj.nodeData << endl;
      // Test the constructor using data
      GenericNode<string> testObj2("Does this work?");
      cout << testObj2.nodeData << endl;
      cout << endl;
   }



   // Test case 04: Confirm that templated node struct can be insantiated
   if (BSTNodeTest == true) {
      cout << "BSTNodeTest == true" << endl;
   }



// X-------------------------X
// |                         |
// |    ASSIGNMENT DRIVER    |
// |                         |
// X-------------------------X


   // Instantiate the puzzle object

   

//   stopwordBST stopwordList;
//   cout << stopwordList.toString();

   return(0);
}

// ---- END STUDENT CODE ----
