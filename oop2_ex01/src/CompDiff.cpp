#include "CompDiff.h"

vector<Set> CompDiff::calculate(vector<Set>& sets)
{
	std::cout << '(';
	//calculating first command
	auto result = m_f1->calculate(sets)[0];
	//delete the result of first part of command from sets's vector
	sets.erase(sets.begin());
	std::cout << DIFF_SYMBOL;
	//calculating second command
	auto rslt2 = m_f2->calculate(sets)[0];
	std::cout << ") = ";//<< ')';
	//insert result of first command again to the vector
	sets.insert(sets.begin(), result);
	return std::make_shared<Diff>()->calculate(sets);
}