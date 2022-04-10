#pragma once
#include "CompOpertaion.h"

class CompProd : public CompOperation {
public:
     //constructor function
	CompProd(std::shared_ptr <Operation>& f1, std::shared_ptr <Operation>& f2) :
		CompOperation(f1, f2, PROD_SYMBOL, f1->getNumOfGroups() + f2->getNumOfGroups()) {};
	virtual vector<Set> calculate(vector<Set>& sets);
	void doProd(vector<Set>& sets);
};