#pragma once
#include <string>
#include "Set.h"
#include <iterator>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Consts.hpp"
using std::string;
using std::vector;


class Operation {
public:
    //constructor function
	Operation(const string& label, const int& numOfSets) :m_label(label), m_numOfSets(numOfSets) {};
	const string& getlabel()const;
	void printLabel()const;
	const int& getNumOfGroups()const;
	virtual vector<Set> calculate(vector<Set>& sets) = 0;
	virtual ~Operation() = default;
private:  
    //holding the command text
	string m_label;
	//holding the wanted number of sets
	int m_numOfSets;       
};
