#pragma once
#include "Operation.h"

class Diff : public Operation {
public:
     //constructor function
	Diff() : Operation("(A-B)", 2) {};
	vector<Set> calculate(vector<Set>& sets);
};