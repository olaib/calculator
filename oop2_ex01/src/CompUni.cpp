#include "CompUni.h"

vector<Set> CompUni::calculate(vector<Set>& sets)
{
	std::cout << '(';
	//calculating first command
	auto result = m_f1->calculate(sets)[0];
	sets.erase(sets.begin());
	std::cout << UNI_SYMBOL;
	//calculating second command
	auto rslt2 = m_f2->calculate(sets)[0];
	std::cout << ") = ";
	//insert the result of the 2 commands
	sets.insert(sets.begin(), result);
	//return intersection of the 2 commands result
	return std::make_shared<Union>()->calculate(sets);
}