#pragma once
using namespace std;

template<class typeT>
class NodalBST {

private:
typeT objData;

public:
// Default constructor
NodalBST();

// Getter
typeT GetValue();

// Setter
void SetValue( typeT someValue );

};
