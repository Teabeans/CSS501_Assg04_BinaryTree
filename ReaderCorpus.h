// Tim Lum
// twhlum@gmail.com
// 2017.12.04
// For the University of Washington Bothell CSS 501A
// Autumn 2017, Graduate Certificate in Software Design & Development (GCSDD)
//
// File Description:
// This file is the header file for the ReaderCorpus class. This program shall accept a list of
// stopwords (stopwords.txt) as well as a command argument corpus location. From these bodies of data
// it will generate a concordance in KeyWord In Context (KWIC) format.
//
// Package files:
// Driver.cpp
// BSTGeneric.h
// BSTGeneric.cpp
// ReaderCorpus.h
// ReaderCorpus.cpp
// LinkedListContext.h
// LinkedListContext.cpp
// stopwords.txt (recommended)
// Corpus (not named, name must be passed as a command argument)
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
// To pass a command argument:
// 1. Go to the top menu bar => Debug => <ProjectName> Properties => Debugging => Command Arguments =>
// 2. Enter the file address and name
// ie. corpus.txt
// 3. Alter main() method signature as follows: main( int argc, char* argv[] ) {
// 4. The variable "argv[1]" now refers to the first command argument passed
//
// To run in Linux with Valgrind and a command argument
// valgrind --leak-check=full --show-leak-kinds=all /home/Teabean/a.out Sudoku.txt
//
// ---- BEGIN STUDENT CODE ----



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       INCLUDE STATEMENTS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

#pragma once

// Necessary for input-output operations
#include <iostream>

// Necessary for string operations
#include <string>

// Necessary for file stream operations
// #include <fstream> // Disincluded from the .h - No file stream operations here

// Field and method declarations for the LinkedListContext class
#include "LinkedListContext.h"

using namespace std;

// X---------------------X
// |    #ReaderCorpus    |
// X---------------------X
// Description: Performs corpus-related operations.
class ReaderCorpus {

private:
//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE FIELDS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-------------------------------------|
// #contextWords[]
//-------------------------------------|
// Description: Array of strings holding up to 11 sequential words from the corpus
// Invariants:  Strings initialized to empty. Updates on every call to advance()
string contextWords[11];

//-------------------------------------|
// #prevContext
//-------------------------------------|
// Description: String representing the pre-current-word context words
// Invariants:  Updated on every call to advance()
string prevContext;

//-------------------------------------|
// #currWord
//-------------------------------------|
// Description: String representing the current word being processed
// Invariants:  Updated on every call to advance()
string currWord;

//-------------------------------------|
// #postContext
//-------------------------------------|
// Description: String representing the post-current-word context words
// Invariants:  Updated on every call to advance()
string postContext;

//-------------------------------------|
// #fileObj
//-------------------------------------|
// Description: ifstream object which holds the corpus prior to processing
// Invariants:  None
ifstream fileObj;



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE METHODS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-------------------------------------|
// #isPrimed()
//-------------------------------------|
// Description:      Determines whether the corpus reader is ready to return data
// Parameters:       None
// Preconditions:    None
// Postconditions:   None
// Return value:     True - This Reader is ready
//                   False - This Reader is not ready
// Functions called: None
bool isPrimed() const;

//-------------------------------------|
// #trimPreNoise(string)
//-------------------------------------|
// Description:      Deletes noisy characters off the start of a word
// Parameters:       string arg1 - The string to be rectified
// Preconditions:    None
// Postconditions:   None
// Return value:     A rectified string (if applicable)
// Functions called: string.erase()
string trimPreNoise(string aWord);

//-------------------------------------|
// #trimPostNoise(string)
//-------------------------------------|
// Description:      Method that deletes noisy characters off the end of a word
// Parameters:       string arg1 - The string to be rectified
// Preconditions:    None
// Postconditions:   None
// Return value:     A rectified string (if applicable)
// Functions called: string.length()
//                   string.erase()
string trimPostNoise(string aWord);


public:
//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC FIELDS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// None for this class



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PUBLIC METHODS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-------------------------------------|
// #advance()
//-------------------------------------|
// Description:      Moves the corpus reader forward one word
//                   Updates the prevContext string
//                   Updates the currWord string
//                   Updates the postContext string
// Parameters:       None
// Preconditions:    A file stream object is loaded in a valid scope
// Postconditions:   One word has been removed from the file stream
// Return value:     True - Advance() succeeded
//                   False - Advance() failed
// Functions called: transform()
//                   trimPreNoise()
//                   trimPostNoise()
bool advance();

//-------------------------------------|
// #isFinished()
//-------------------------------------|
// Description:      Determines whether the reader has exhausted the corpus
// Parameters:       None
// Preconditions:    None
// Postconditions:   None
// Return value:     True - There are no further words to read in the corpus
//                   False - The reader has not exhausted the corpus
// Functions called: None
bool isFinished() const;

//-------------------------------------|
// #loadFile(string)
//-------------------------------------|
// Description:      Causes the fileObj object to attempt file access
// Parameters:       String representing a file address
// Preconditions:    None
// Postconditions:   A file has been opened into the local filestream or not
// Return value:     True - File opened successfully
//                   False - File not accessible
// Functions called: open()

bool loadFile(string fileAddy);

//-------------------------------------|
// #makeLinkedListContext()
//-------------------------------------|
// Description:      Generates a LinkedListContext object
// Parameters:       None
// Preconditions:    None
// Postconditions:   A new LinkedListContext object is allocated
// Return value:     LinkedListContext* - Pointer to a new LinkedListContext
// Functions called: LinkedListContext(string, string, string)
LinkedListContext* makeLinkedListContext();

//-------------------------------------|
// #prime()
//-------------------------------------|
// Description:      Advances the reader to the next valid keyword-context state.
// Parameters:       None
// Preconditions:    A file stream has been opened in a valid scope
// Postconditions:   The next available word is loaded to contextWords[5]
// Return value:     String representing the current word
// Functions called: advance()
//                   isPrimed()
string prime();



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       CONSTRUCTORS / DESTRUCTORS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-------------------------------------|
// #ReaderCorpus()
//-------------------------------------|
// Description:      Default constructor for the ReaderCorpus class
// Parameters:       None
// Preconditions:    None
// Postconditions:   A new ReaderCorpus object is allocated
// Return value:     None
// Functions called: None
ReaderCorpus();




//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       GETTERS / SETTERS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-------------------------------------|
// #getContextWords()
//-------------------------------------|
// Description:      Returns all words loaded to contextWords[]
// Parameters:       None
// Preconditions:    None
// Postconditions:   None
// Return value:     String of (11) words maximum
// Functions called: None
string getContextWords() const;

//-------------------------------------|
// #getPrevContext()
//-------------------------------------|
// Description:      Returns a string representing the previous concordance context
// Parameters:       None
// Preconditions:    None
// Postconditions:   None
// Return value:     String of (5) words maximum
// Functions called: None
string getPrevContext() const;

//-------------------------------------|
// #getCurrWord()
//-------------------------------------|
// Description:      Returns the current word of the ReaderCorpus object
// Parameters:       None
// Preconditions:    A valid string must be loaded to contextWords[5]
// Postconditions:   None
// Return value:     String of (1) word
// Functions called: None
string getCurrWord() const;

//-------------------------------------|
// #getPostContext()
//-------------------------------------|
// Description:      Returns a string representing the post concordance context
// Parameters:       None
// Preconditions:    None
// Postconditions:   None
// Return value:     String of (5) words maximum
// Functions called: None
string getPostContext() const;

};
