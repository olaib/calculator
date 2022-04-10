#pragma once
#include "CompOpertaion.h"
#include "Union.h"

class CompUni : public CompOperation {
public:
     //constructor function
	CompUni(std::shared_ptr <Operation>& f1, std::shared_ptr <Operation>& f2) :
		CompOperation(f1, f2, UNI_SYMBOL, f1->getNumOfGroups() + f2->getNumOfGroups()) {};
	virtual vector<Set> calculate(vector<Set>& sets);
};