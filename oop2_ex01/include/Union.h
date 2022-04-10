#pragma once
#include "Operation.h"

class Union : public Operation {
public:
     //constructor function
	Union() : Operation("(AUB)", 2) {};
	vector<Set> calculate(vector<Set>& sets);
};