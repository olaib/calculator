#pragma once 
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include "Operation.hpp"


using std::cout;
using std::string;

class Controller {
public:
     //constructor function
	Controller();
	void run();
private:
    //hold the help text
	string m_help;
	//vector of shared_ptr : hold the object's commands
	vector <std::shared_ptr<Operation>> m_operations;
	void isExistFunc();
	void read_inp(vector<Set>& group, const int& funNum);
	bool isExistFunc(const int& fun_num);//is func num exist
	void do_del(const int& func_num);
	bool do_command();
	void openAndReadFile(string& text, const string fileName);
	void print_list();
	void doComp();
	void doDifference();
	void doIntersection();
	void doProd();
	void doUnion();
	void doEval();
};