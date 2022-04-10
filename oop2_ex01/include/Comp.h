#pragma once
#include "CompOpertaion.h"

//class of complex comp command
class Comp : public CompOperation {
public:
    //constructor function
	Comp(std::shared_ptr <Operation>& f1, std::shared_ptr <Operation>& f2) :
		CompOperation(f1, f2, COMP_SYMBOL, f1->getNumOfGroups() + f2->getNumOfGroups()-1) {};
	vector<Set> calculate(vector<Set>& sets)override;
};