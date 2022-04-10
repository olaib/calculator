#include "CompProd.h"

vector<Set> CompProd::calculate(vector<Set>& sets)
{
	std::cout << '(';
	//calculating first command
	auto result = m_f1->calculate(sets)[0];
	sets.erase(sets.begin());
	std::cout << PROD_SYMBOL;
	//calculating second command
	auto rslt2 = m_f2->calculate(sets)[0];
	std::cout << ")";	//insert the result of the 2 commands
	sets.insert(sets.begin(), result);
	doProd(sets);
	return sets;
}
//-------------------------------------------------------------------
//this function do prod between 2 elemnts of 2 sets
void CompProd::doProd(vector<Set>& sets)
{
    //the result vector
	vector<int> mult;
	for (auto a : sets[0])
		for (auto b : sets[1])
			mult.push_back(a * b);
    //erase the first cell from the set's vector
	sets.erase(sets.begin());
	//swap the result of the prod
	sets[0].swap(mult);
}