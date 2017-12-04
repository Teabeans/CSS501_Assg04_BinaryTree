// X--------------------------X
// |                          |
// |    INCLUDE STATEMENTS    |
// |                          |
// X--------------------------X

#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include "LinkedListContext.h"

using namespace std;

// Creates Generic Nodes with LinkedListContext data fields to pass to the BSTGeneric Concordance object. This is the packer.

class ReaderCorpus {

private:
// X----------------------X
// |                      |
// |    PRIVATE FIELDS    |
// |                      |
// X----------------------X

string contextWords[11];

string prevContext;

string currWord;

string postContext;

ifstream fileObj;



// X-----------------------X
// |                       |
// |    PRIVATE METHODS    |
// |                       |
// X-----------------------X


string trimPreNoise(string aWord);

string trimPostNoise(string aWord);


public:
// X---------------------X
// |                     |
// |    PUBLIC FIELDS    |
// |                     |
// X---------------------X



// X----------------------X
// |                      |
// |    PUBLIC METHODS    |
// |                      |
// X----------------------X

bool advance();

bool isFinished();

bool isPrimed();

bool loadFile(string fileAddy);

LinkedListContext* makeLinkedListContext();

string prime();

// X--------------------------------X
// |                                |
// |    CONSTRUCTORS/DESTRUCTORS    |
// |                                |
// X--------------------------------X

// #ReaderCorpus() - Default constructor
ReaderCorpus();




// X-------------------------X
// |                         |
// |    GETTERS / SETTERS    |
// |                         |
// X-------------------------X
string getContextWords();
string getPrevContext();
string getCurrWord();
string getPostContext();

};
