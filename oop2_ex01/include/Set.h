#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;

class Set {
public:
	Set() {};
	Set(const size_t& size) { resize(size); }
	Set(const vector<int>& vec) { m_set = vec;}
	auto begin() const { return m_set.begin(); }
	auto end() const { return m_set.end(); }
	void resize(const size_t& size) { m_set.resize(size); }
	vector<int> getset() const { return m_set; }
	void sort();
	const size_t& size()const { return m_set.size(); }
	void push_back(const int& num) { m_set.push_back(num); }
	const int& operator[](const size_t& indx)const { return m_set[indx]; }
	void swap(vector<int>& other) { m_set.swap(other); }
private:
	vector<int> m_set;
};

//global cout operator for givven set
std::ostream& operator<<(std::ostream& output, const Set& set);
//global cin operator for givven set
std::istream& operator>>(std::istream& input, Set& set);