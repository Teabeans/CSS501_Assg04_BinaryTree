// X--------------------------X
// |                          |
// |    INCLUDE STATEMENTS    |
// |                          |
// X--------------------------X

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>  // For lowercasing

#include "ReaderCorpus.h"
#include "LinkedListContext.h"

using namespace std;

// X----------------------X
// |                      |
// |    PRIVATE FIELDS    |
// |                      |
// X----------------------X

// None declared in the .cpp


// X-----------------------X
// |                       |
// |    PRIVATE METHODS    |
// |                       |
// X-----------------------X

// #isFinished() - 
bool ReaderCorpus::isFinished() {
   // If the fileObj is empty and the current word is empty...
   if (currWord == " ") {
      // Then this Corpus Reader cannot return any further valid concordance values
      return(true);
   }
   else {
      return(false);
   }
}

// #trimPreNoise(string) - 
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
   // Delete the substring from the start to the first index
   aWord.erase(0, (currIndex));
   }
   return(aWord);
}

// #trimPostNoise(string) - 
string ReaderCorpus::trimPostNoise(string aWord) {
   bool lastLetter = false;
   // Load the last character of the string
   int currIndex = aWord.length();
   char currLetter = aWord[currIndex];
   // Fencepost check. If it's the last actual letter, do nothing
   if ( 'a' <= currLetter && currLetter <= 'z') {
      // cout << "This is the last letter! " << currLetter << endl; // DEBUG
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
}


// X---------------------X
// |                     |
// |    PUBLIC FIELDS    |
// |                     |
// X---------------------X

// None declared in the .cpp



// X----------------------X
// |                      |
// |    PUBLIC METHODS    |
// |                      |
// X----------------------X

// #advance() - 
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
      // cout << "The word just pulled was: " << nextWord << endl; // DEBUG
      // Lowercase the word pulled
      // From https://notfaq.wordpress.com/2007/08/04/cc-convert-string-to-upperlower-case/
      transform(nextWord.begin(), nextWord.end(), nextWord.begin(), ::tolower);
      // Check to see if valid chars are in the word
      bool validChars = false;
      for (unsigned int i = 0 ; i < nextWord.length() ; i++) {
         if (nextWord[i] > 'a' && nextWord[i] < 'z') {
            validChars = true;
         }
      } // Word scanned. Is it valid?
      validWord = validChars;
   } // Closing while loop, a valid word has been identified OR we've run off the end of the document.
   // Omit pre-noisy characters
   nextWord = this->trimPreNoise(nextWord);
   // Omit post-noisy characters
   nextWord = this->trimPostNoise(nextWord);
   // If no change was made by the fileObj extraction operator...
   if (nextWord == "foobarbaz") {
      // Default to a whitespace
      nextWord = " ";
   }
   // Load the next word to the end of the context array
   contextWords[10] = nextWord;
   // cout << "The current word is: " << contextWords[5] << endl; // DEBUG
   // Update the context strings
   string update = "";
   for (int i = 0 ; i < 5 ; i++) {
      update = update + contextWords[i] + " ";
   }
   // Update the previous context string
   prevContext = update;
   update = "";
   for (int i = 6 ; i < 11 ; i++) {
      update = update + " " + contextWords[i];
   }
   // Update the previous context string
   postContext = update;
   // Update the current keyword
   currWord = contextWords[5];
   return(true);
}

bool ReaderCorpus::isPrimed() {
   if (contextWords[5] != "") {
      return (true);
   }
   return (false);
} // Closing isLoaded()

bool ReaderCorpus::loadFile(string fileAddy) {
   fileObj.open(fileAddy);
   // Confirm that file was opened. Report otherwise if not.
   if (!fileObj) {
      cout << "Unable to open Corpus. Closing program...";
      return(false);
   }
   cout << "File loaded successfully to ReaderCorpus object!" << endl;
   return(true);
}

LinkedListContext* ReaderCorpus::makeLinkedListContext() {
   LinkedListContext* retList = new LinkedListContext(prevContext, contextWords[5], postContext);
   return(retList);
}

// #prime() - Advances the reader to the first valid keyword-context state.
string ReaderCorpus::prime() {
   while (!isPrimed()) {
      this->advance();
   }
   return(contextWords[5]);
}



// X--------------------------------X
// |                                |
// |    CONSTRUCTORS/DESTRUCTORS    |
// |                                |
// X--------------------------------X

// #ReaderCorpus() - Default constructor
ReaderCorpus::ReaderCorpus() {
   // cout << "ReaderCorpus() default constructor called" << endl; // DEBUG
   prevContext = "Nothing to see here!";
   currWord = "De nada";
   postContext = "Nor here!";
   for (int i = 0 ; i < 11 ; i++) {
      contextWords[i] = "";
   }
}




// X-------------------------X
// |                         |
// |    GETTERS / SETTERS    |
// |                         |
// X-------------------------X

string ReaderCorpus::getContextWords() {
   string retString;
   for (int i = 0 ; i < 11 ; i++) {
      retString = retString +  " " + contextWords[i];
   }
   return(retString);
}

string ReaderCorpus::getPrevContext() {
   return(prevContext);
}

string ReaderCorpus::getCurrWord() {
   return(currWord);
}

string ReaderCorpus::getPostContext() {
   return(postContext);
}
