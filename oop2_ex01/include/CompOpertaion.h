#pragma once
#include <memory>
#include "Operation.h"
using std::shared_ptr;


class CompOperation :public Operation {
public:
     //constructor function
	CompOperation(std::shared_ptr <Operation>& f1, std::shared_ptr <Operation>& f2, const string& operSymbol, const int& inpNumGroups)
		:m_f1(f1), m_f2(f2), Operation("(" + f1->getlabel() + operSymbol + f2->getlabel() + ")", inpNumGroups)  {};
protected:
    //holding the 2 command that hold the complix command
	std::shared_ptr<Operation> m_f1, m_f2;
};