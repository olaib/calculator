#include "Comp.h"

vector<Set> Comp::calculate(vector<Set>& sets)
{
	std::cout << '(';
	//calculate first part of command
	auto rslt1 = m_f1->calculate(sets)[0];
	std::cout << COMP_SYMBOL;
	//calculate second part of command
	auto rslt2 = m_f2->calculate(sets)[0];
	std::cout << ')';
	return sets;
}