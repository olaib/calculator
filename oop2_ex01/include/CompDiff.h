#pragma once
#include "CompOpertaion.h"
#include "Diff.h"

class CompDiff : public CompOperation {
public:
    //constructor function
	CompDiff(std::shared_ptr <Operation>& f1, std::shared_ptr <Operation>& f2) :
		CompOperation(f1, f2, DIFF_SYMBOL, f1->getNumOfGroups() + f2->getNumOfGroups()) {};
	virtual vector<Set> calculate(vector<Set>& sets);
};