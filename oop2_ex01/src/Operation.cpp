#include "Operation.h"

//return the string of the command
const string& Operation::getlabel() const
{
	return m_label;
}
//print the string of the command
void Operation::printLabel() const
{
    auto value = A_ASCII;

    for (size_t i = 0; i < m_label.size(); i++)
    {
        if (m_label[i] <= Z_ASCII && m_label[i] >= A_ASCII && m_label[i] != U_ASCII)
        {
            //circular ascii chars
            if (value > Z_ASCII)
                value = A_ASCII;
            //if next char is U so skip it
            std::cout << (value + 1 == U_ASCII ? value += 2 : value++);
        }
        else//print normal
            std::cout <<m_label[i];
    }
}
//-------------------------------------------------------------------
//return num of wanted set of "this"
const int& Operation::getNumOfGroups() const
{
	return m_numOfSets; 
}
