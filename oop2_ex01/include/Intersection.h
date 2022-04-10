#pragma once
#include "Operation.h"

class Intersection : public Operation {
public:
     //constructor function
	Intersection() : Operation("(A^B)", 2) {};
	vector<Set> calculate(vector<Set>& sets);
};