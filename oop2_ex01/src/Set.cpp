#include "Set.h"

//-------------------------------------------------------------------
//deleting doublicated elements and sort the set
void Set::sort()
{
    std::sort(m_set.begin(), m_set.end());
    auto [newEnd, end] = std::ranges::unique(m_set);
    m_set.erase(newEnd, end);
}

//-------------------------------------------------------------------
std::ostream& operator<<(std::ostream& output, const Set& set)
{
    output << "{ ";
    for (size_t i = 0; i < set.size(); i++)
    {
        //print element
        output << set[i] << (i == set.size() - 1 ? "" : ", ");
    }
    output << " }";
    return output;
}

std::istream& operator>>(std::istream& input, Set& set)
{
    vector<int> temp;
    temp.resize(set.size());
    for (size_t i = 0; i < set.size(); i++)
    {
        input >> temp[i];
    }
    set = temp;
    set.sort();
    return input;
}