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

// Include statements

// Classes, Private
// Fields, Private (A-Z)
// Methods, Private (A-Z)

// Structs, Public
// Fields, Public (A-Z)
// Methods, Public (A-Z)
// Methods, DEBUG (A-Z)

// Constructors/Destructors

// Getters/Setters (A-Z)
// Operator Overloads

// X--------------------------X
// |                          |
// |    INCLUDE STATEMENTS    |
// |                          |
// X--------------------------X

//Necessary to interact with 'cin' and 'cout' streams
#include <iostream>
// Necessary for string operations
#include <string>
// Methods not found in the current namespace are directed to check the 'std' namespace
using namespace std;

// Header for the Associated classes
// #include "SomeClass.h"



// X---------------------- PRIVATE REGION ----------------------X

// X---------------X
// |               |
// |    CLASSES    |
// |               |
// X---------------X

// TODO: Struct description
// #methodName(arg1, arg2) - 
// Parameters:       .
// Preconditions:    .
// Postconditions:   .
// Return value:     .
// Functions called: .
// <returnType> <Namespace>::<MethodName>(<T1> arg1, <T2> arg2) const { ... }



// X----------------------X
// |                      |
// |    PRIVATE FIELDS    |
// |                      |
// X----------------------X

// Do not redeclare in the .cpp file.



// X-----------------------X
// |                       |
// |    PRIVATE METHODS    |
// |                       |
// X-----------------------X

// TODO: Method description
// #methodName(arg1, arg2) - 
// Parameters:       .
// Preconditions:    .
// Postconditions:   .
// Return value:     .
// Functions called: .
// <returnType> <Namespace>::<MethodName>(<T1> arg1, <T2> arg2) const { ... }



// X---------------------- PUBLIC REGION ----------------------X

// X------------------X
// |                  |
// |    STRUCTURES    |
// |                  |
// X------------------X

// TODO: Struct description
// #methodName(arg1, arg2) - 
// Parameters:       .
// Preconditions:    .
// Postconditions:   .
// Return value:     .
// Functions called: .
// <returnType> <Namespace>::<MethodName>(<T1> arg1, <T2> arg2) const { ... }



// X---------------------X
// |                     |
// |    PUBLIC FIELDS    |
// |                     |
// X---------------------X

// Do not redeclare in the .cpp file.



// X----------------------X
// |                      |
// |    PUBLIC METHODS    |
// |                      |
// X----------------------X

// TODO: Method description
// #methodName(arg1, arg2) - 
// Parameters:       .
// Preconditions:    .
// Postconditions:   .
// Return value:     .
// Functions called: .
// <returnType> <Namespace>::<MethodName>(<T1> arg1, <T2> arg2) const { ... }



// X--------------------------------X
// |                                |
// |    CONSTRUCTORS/DESTRUCTORS    |
// |                                |
// X--------------------------------X

// #ClassName() - Default Class constructor
// Parameters:       .
// Preconditions:    .
// Postconditions:   .
// Return value:     .
// Functions called: .
// <Namespace>::Class() { ... } // Closing Class()

// #~ClassName() - Default Class destructor
// Parameters:       .
// Preconditions:    .
// Postconditions:   .
// Return value:     .
// Functions called: .
// ~<Namespace>::Class() { ... } // Closing Class()



// X---------------------X
// |                     |
// |    DEBUG METHODS    |
// |                     |
// X---------------------X

// TODO: Method description
// #methodName(arg1, arg2) - 
// Parameters:       .
// Preconditions:    .
// Postconditions:   .
// Return value:     .
// Functions called: .
// <returnType> <Namespace>::<MethodName>(<T1> arg1, <T2> arg2) const { ... }



// X-------------------------X
// |                         |
// |    GETTERS / SETTERS    |
// |                         |
// X-------------------------X

// TODO: Getter description
// #getter(arg1, arg2) - Getter description
// Parameters:       .
// Preconditions:    .
// Postconditions:   .
// Return value:     .
// Functions called: .
// <returnType> <Namespace>::<MethodName>( ) const { ... }

// TODO: Setter description
// #setter(arg1, arg2) - Setter description
// Parameters:       .
// Preconditions:    .
// Postconditions:   .
// Return value:     .
// Functions called: .
// <returnType> <Namespace>::<MethodName>( ) const { ... }



// X--------------------------X
// |                          |
// |    OPERATOR OVERLOADS    |
// |                          |
// X--------------------------X

// TODO: Overload description
// #operator>>(arg1, arg2) - Overload description
// Parameters:       .
// Preconditions:    .
// Postconditions:   .
// Return value:     .
// Functions called: .
// istream& operator>> (istream& cinData, <ThisClass>& someObject) { ... }


// ---- END STUDENT CODE ----
