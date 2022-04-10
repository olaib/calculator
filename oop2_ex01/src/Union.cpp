#include "Union.h"

vector<Set> Union::calculate(vector<Set>& sets)
{
	vector<int> result;
	std::cout << '(' << sets[0] << UNI_SYMBOL << sets[1] << ')';
	std::ranges::set_union(sets[0], sets[1], std::back_inserter(result));
	//delete first cell from the vector
	sets.erase(sets.begin());
	//swap the result from first cell in the vector
	sets[0].swap(result);
	return sets;
}