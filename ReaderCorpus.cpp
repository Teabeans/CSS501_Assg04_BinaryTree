// Tim Lum
// twhlum@gmail.com
// 2017.12.04
// For the University of Washington Bothell CSS 501A
// Autumn 2017, Graduate Certificate in Software Design & Development (GCSDD)
//
// File Description:
// This file is the driver file for the Concordance Assignment. This program shall accept a list of
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

// Necessary for input-output operations
#include <iostream>

// Necessary for string operations
#include <string>

// Necessary for file stream operations
#include <fstream>

// Necessary for string lowercasing operations
#include <algorithm>

// Field and method declarations for the ReaderCorpus class
#include "ReaderCorpus.h"

// Field and method declarations for the LinkedListContext class
#include "LinkedListContext.h"

using namespace std;



//-------|---------|---------|---------|---------|---------|---------|---------|
//
//       PRIVATE FIELDS
//
//-------|---------|---------|---------|---------|---------|---------|---------|

// Do not reinitialize these variables in the .cpp.
// Included here for reference

//-------------------------------------|
// #contextWords[]
//-------------------------------------|
// Description: Array of strings holding up to 11 sequential words from the corpus
// Invariants:  Strings initialized to empty. Updates on every call to advance()
// string contextWords[11];

//-------------------------------------|
// #prevContext
//-------------------------------------|
// Description: String representing the pre-current-word context words
// Invariants:  Updated on every call to advance()
// string prevContext;

//-------------------------------------|
// #currWord
//-------------------------------------|
// Description: String representing the current word being processed
// Invariants:  Updated on every call to advance()
// string currWord;

//-------------------------------------|
// #postContext
//-------------------------------------|
// Description: String representing the post-current-word context words
// Invariants:  Updated on every call to advance()
// string postContext;

//-------------------------------------|
// #fileObj
//-------------------------------------|
// Description: ifstream object which holds the corpus prior to processing
// Invariants:  None
// ifstream fileObj;



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
bool ReaderCorpus::isPrimed() const {
   if (contextWords[5] != "") {
      return (true);
   }
   return (false);
} // Closing isLoaded()

//-------------------------------------|
// #trimPreNoise(string)
//-------------------------------------|
// Description:      Deletes noisy characters off the start of a word
// Parameters:       string arg1 - The string to be rectified
// Preconditions:    None
// Postconditions:   None
// Return value:     A rectified string (if applicable)
// Functions called: string.erase()
string ReaderCorpus::trimPreNoise(string aWord) {
   bool firstLetter = false;
   // Load the first character of the string
   int currIndex = 0;
   char currLetter = aWord[currIndex];
   // Fencepost check. If it's the first actual letter, do nothing
   if ( 'a' <= currLetter && currLetter <= 'z') {
      // cout << "This is the first letter! " << currLetter << endl; // DEBUG
      firstLetter = true;
   }
   // Otherwise, the first character is noisy, so proceed forward...
   else {
      // While we haven't found the first letter of the word...
      while (firstLetter == false) {
         // Increment the index
         currIndex++;
         // And check for a valid letter
         currLetter = aWord[currIndex];
         if ( 'a' <= currLetter && currLetter <= 'z') {
            // If we found it, set the exit flag
            firstLetter = true;
         } // Closing if
      } // Closing while loop. First character found and currIndex points to it
      // Delete the substring from the word start to the first good index
      aWord.erase(0, (currIndex));
   }
   return(aWord);
} // Closing trimPreNoise()

//-------------------------------------|
// #trimPostNoise(string)
//-------------------------------------|
// Description:      Deletes noisy characters off the end of a word
// Parameters:       string arg1 - The string to be rectified
// Preconditions:    None
// Postconditions:   None
// Return value:     A rectified string (if applicable)
// Functions called: string.length()
//                   string.erase()
string ReaderCorpus::trimPostNoise(string aWord) {
   bool lastLetter = false;
   // Load the last character of the string
   int currIndex = aWord.length();
   char currLetter = aWord[currIndex];
   // Fencepost check. If it's the last actual letter, do nothing
   if ( 'a' <= currLetter && currLetter <= 'z') {
      lastLetter = true;
   }
   // Otherwise, the last character is noisy, so proceed backward...
   else {
      // While we haven't found the last letter of the word...
      while (lastLetter == false) {
         // Decrement the index
         currIndex--;
         // And check for a valid letter
         currLetter = aWord[currIndex];
         if ( 'a' <= currLetter && currLetter <= 'z') {
            // If we found it, set the exit flag
            lastLetter = true;
         } // Closing if
      } // Closing while loop. Last character found and currIndex points to it
   // Delete the substring from the currIndex to the end
   aWord.erase((currIndex+1), (aWord.length()));
   }
   return(aWord);
} // Closing trimPostNoise()


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
bool ReaderCorpus::advance() {
   // Test to see if advance() can even be called
   if (this->isFinished()) {
      cout << "ACHTUNG! This Corpus Reader is finished." << endl; // DEBUG
      return(false);
   }
   // Shuffle context words down one index
   for (int i = 0 ; i < 11 ; i++) {
      contextWords[i] = contextWords[i+1];
   }
   string nextWord = "foobarbaz";
   bool validWord = false;
   // While we haven't confirmed possession of a valid word...
   while (validWord == false) {
      // Attempt to assign the next whitespace delimited chars to nextWord
      fileObj >> nextWord;
      // Lowercase the word pulled
      // From https://notfaq.wordpress.com/2007/08/04/cc-convert-string-to-upperlower-case/
      transform(nextWord.begin(), nextWord.end(), nextWord.begin(), ::tolower);
      // Check to see if valid chars are in the word
      bool validChars = false;
      for (unsigned int i = 0 ; i < nextWord.length() ; i++) {
         if (nextWord[i] >= 'a' && nextWord[i] <= 'z') {
            validChars = true;
         }
      } // Word scanned.
      // If there were valid chars, then it's a valid word
      validWord = validChars;
   } // Closing while loop, a valid word has been identified OR we've run off the end of the document.
   // Omit pre-noisy characters
   nextWord = this->trimPreNoise(nextWord);
   // Omit post-noisy characters
   nextWord = this->trimPostNoise(nextWord);
   // If no change was made by the fileObj extraction operator...
   if (nextWord == "foobarbaz") {
      // Default to a whitespace (this is for end-of-document conditions)
      nextWord = " ";
   }
   // Load the next word to the end of the context array
   contextWords[10] = nextWord;
   // And update the context strings
   string update = "";
   // For context[0]-[4]
   for (int i = 0 ; i < 5 ; i++) {
      update = update + contextWords[i] + " ";
   }
   // Update the previous context string
   prevContext = update;
   // Reset the updater
   update = "";
   // For context[6]-[10]
   for (int i = 6 ; i < 11 ; i++) {
      update = update + " " + contextWords[i];
   }
   // Update the previous context string
   postContext = update;
   // Update the current keyword
   currWord = contextWords[5];
   // Report success
   return(true);
} // Closing advance()

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
bool ReaderCorpus::isFinished() const{
   // If the fileObj is empty and the current word is empty...
   if (currWord == " ") {
      // Then this Corpus Reader cannot return any further valid concordance values
      return(true);
   }
   else {
      return(false);
   }
} // Closing isFinished()

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
bool ReaderCorpus::loadFile(string fileAddy) {
   fileObj.open(fileAddy);
   // Confirm that file was opened. Report otherwise if not.
   if (!fileObj) {
      cout << "Unable to open Corpus. Closing program...";
      return(false);
   }
   return(true);
} // Closing loadFile()

//-------------------------------------|
// #makeLinkedListContext()
//-------------------------------------|
// Description:      Generates a LinkedListContext object
// Parameters:       None
// Preconditions:    None
// Postconditions:   A new LinkedListContext object is allocated
// Return value:     LinkedListContext* - Pointer to a new LinkedListContext
// Functions called: LinkedListContext(string, string, string)
LinkedListContext* ReaderCorpus::makeLinkedListContext() {
   LinkedListContext* retList = new LinkedListContext(prevContext, contextWords[5], postContext);
   return(retList);
} // Closing makeLinkedListContext()

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
string ReaderCorpus::prime() {
   while (!isPrimed()) {
      this->advance();
   }
   return(contextWords[5]);
} // Closing prime()



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
ReaderCorpus::ReaderCorpus() {
   // cout << "ReaderCorpus() default constructor called" << endl; // DEBUG
   prevContext = "Nothing to see here!";
   currWord = "De nada";
   postContext = "Nor here!";
   for (int i = 0 ; i < 11 ; i++) {
      contextWords[i] = "";
   }
}



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
string ReaderCorpus::getContextWords() const {
   string retString;
   for (int i = 0 ; i < 11 ; i++) {
      retString = retString +  " " + contextWords[i];
   }
   return(retString);
}

//-------------------------------------|
// #getPrevContext()
//-------------------------------------|
// Description:      Returns a string representing the previous concordance context
// Parameters:       None
// Preconditions:    None
// Postconditions:   None
// Return value:     String of (5) words maximum
// Functions called: None
string ReaderCorpus::getPrevContext() const {
   return(prevContext);
}

//-------------------------------------|
// #getCurrWord()
//-------------------------------------|
// Description:      Returns the current word of the ReaderCorpus object
// Parameters:       None
// Preconditions:    A valid string must be loaded to contextWords[5]
// Postconditions:   None
// Return value:     String of (1) word
// Functions called: None
string ReaderCorpus::getCurrWord() const {
   return(currWord);
}

//-------------------------------------|
// #getPostContext()
//-------------------------------------|
// Description:      Returns a string representing the post concordance context
// Parameters:       None
// Preconditions:    None
// Postconditions:   None
// Return value:     String of (5) words maximum
// Functions called: None
string ReaderCorpus::getPostContext() const {
   return(postContext);
}
