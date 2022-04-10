#pragma once
#include "CompOpertaion.h"
#include "Intersection.h"

class CompInter : public CompOperation {
public:
     //constructor function
	CompInter(std::shared_ptr <Operation>& f1, std::shared_ptr <Operation>& f2) :
		CompOperation(f1, f2, INTER_SYMBOL, f1->getNumOfGroups() + f2->getNumOfGroups()) {};
	virtual vector<Set> calculate(vector<Set>& sets);
};