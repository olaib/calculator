#include "Intersection.h"

vector<Set> Intersection::calculate(vector<Set>& sets)
{
	vector<int> result;
    //printing the wanted sets for wanted command
	std::cout << '(' << sets[0] << INTER_SYMBOL << sets[1] << ')';
	std::ranges::set_intersection(sets[0], sets[1], std::back_inserter(result));
	//delete first cell from the vector
	sets.erase(sets.begin());
	//swap the result from first cell in the vector
	sets[0].swap(result);
	return sets;
}