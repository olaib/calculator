#include "Controller.h"
#include <sstream>
#include <windows.h>
                                                                                      

//  ______                                                                ______             __                      __              __                         
// /      \                                                              /      \           /  |                    /  |            /  |                        
///$$$$$$  |  ______    ______   __    __   ______                      /$$$$$$  |  ______  $$ |  _______  __    __ $$ |  ______   _$$ |_     ______    ______  
//$$ | _$$/  /      \  /      \ /  |  /  | /      \        ______       $$ |  $$/  /      \ $$ | /       |/  |  /  |$$ | /      \ / $$   |   /      \  /      \ 
//$$ |/    |/$$$$$$  |/$$$$$$  |$$ |  $$ |/$$$$$$  |      /      |      $$ |       $$$$$$  |$$ |/$$$$$$$/ $$ |  $$ |$$ | $$$$$$  |$$$$$$/   /$$$$$$  |/$$$$$$  |
//$$ |$$$$ |$$ |  $$/ $$ |  $$ |$$ |  $$ |$$ |  $$ |      $$$$$$/       $$ |   __  /    $$ |$$ |$$ |      $$ |  $$ |$$ | /    $$ |  $$ | __ $$ |  $$ |$$ |  $$/ 
//$$ \__$$ |$$ |      $$ \__$$ |$$ \__$$ |$$ |__$$ |                    $$ \__/  |/$$$$$$$ |$$ |$$ \_____ $$ \__$$ |$$ |/$$$$$$$ |  $$ |/  |$$ \__$$ |$$ |      
//$$    $$/ $$ |      $$    $$/ $$    $$/ $$    $$/                     $$    $$/ $$    $$ |$$ |$$       |$$    $$/ $$ |$$    $$ |  $$  $$/ $$    $$/ $$ |      
// $$$$$$/  $$/        $$$$$$/   $$$$$$/  $$$$$$$/                       $$$$$$/   $$$$$$$/ $$/  $$$$$$$/  $$$$$$/  $$/  $$$$$$$/    $$$$/   $$$$$$/  $$/       
//                                        $$ |                                                                                                                  
//                                        $$ |                                                                                                                  
//                                        $$/                  

Controller::Controller() {

	m_operations.push_back(std::make_shared<Union>());
	m_operations.push_back(std::make_shared<Intersection>());
	m_operations.push_back(std::make_shared<Diff>());
	//================ reading help text from file =================
	openAndReadFile(m_help, HELP_FILE_NAME);
}
//------------------------------------------------------------------
//this function running the calculater
void Controller::run()
{
	//====================== print title ===========================
	//make the printing with colors
	HANDLE coloredConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(coloredConsole, FOREGROUND_GREEN |FOREGROUND_INTENSITY);
	//holding the title
	string text;
	//open the file for the title
	openAndReadFile(text, TITLE_FILE_NAME);
	std::cout << text << std::endl;
	//======================== run calculator ======================
	do {
		print_list();
		
	} while (do_command());
}
//-------------------------------------------------------------------
//this function delete comand when user ask
void Controller::do_del(const int& func_num)
{
	if (isExistFunc(func_num)) {
		m_operations.erase(m_operations.begin() + func_num);
		std::cout << DEL_MSG;
	}
	else 
		std::cerr << INVALID_INP;
}
//-------------------------------------------------------------------
//printing command list
void Controller::print_list()
{
	HANDLE coloredConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(coloredConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	std::cout << COMMAND_LIST;
	//printing the numbers and commands
	for (size_t i = 0; i < m_operations.size(); i++){
		std::cout << i<<".  " ;
		m_operations[i]->printLabel();
		std::cout << std::endl;
	}
	SetConsoleTextAttribute(coloredConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	std::cout << INP_MSG;
}

//-------------------------------------------------------------------
//this function running the wanted command 
void Controller::doEval()
{
	int func_num;
	std::vector<Set> sets;
	//getting the number of command the user want
	std::cin >> func_num;
	if (isExistFunc(func_num)) {
	    //reading data of sets
		read_inp(sets, func_num);

		auto res = m_operations[func_num]->calculate(sets)[0];
		res.sort();
		std::cout << " = " << res << std::endl;
	}
	else std::cerr << INVALID_INP;
}
//-------------------------------------------------------------------
//this function handle comp command
void Controller::doComp()
{
	int func1, func2;
	std::cin >> func1 >> func2;
	if (isExistFunc(func1) && isExistFunc(func1)) {

		m_operations.push_back(std::make_shared<Comp>(m_operations[func1],
			m_operations[func2]));
		isExistFunc();
	}
}
//-------------------------------------------------------------------
//this function handle comp difference
void Controller::doDifference()
{
	int func1, func2;
	std::cin >> func1 >> func2;
	if (isExistFunc(func1) && isExistFunc(func1)) {

		m_operations.push_back(std::make_shared<CompDiff>(m_operations[func1],
			m_operations[func2]));
		isExistFunc();
	}
}
//-------------------------------------------------------------------
//this function handle Intersection command
void Controller::doIntersection()
{
	int func1, func2;
	std::cin >> func1 >> func2;
	if (isExistFunc(func1) && isExistFunc(func1)) {

		m_operations.push_back(std::make_shared<CompInter>(m_operations[func1],
			m_operations[func2]));
		isExistFunc();
	}
}
//-------------------------------------------------------------------
//this function handle prod command
void Controller::doProd()
{
	int func1, func2;
	std::cin >> func1 >> func2;
	if (isExistFunc(func1) && isExistFunc(func1)) {

		m_operations.push_back(std::make_shared<CompProd>(m_operations[func1],
			m_operations[func2]));
		isExistFunc();
	}
}
//-------------------------------------------------------------------
//this function handle union command
void Controller::doUnion()
{
	int func1, func2;
	std::cin >> func1 >> func2;
	if (isExistFunc(func1) && isExistFunc(func1)) {

		m_operations.push_back(std::make_shared<CompUni>(m_operations[func1],
			m_operations[func2]));
		isExistFunc();
	}
}
//-------------------------------------------------------------------
//this function get a string name and check if file exist and read if exist
void Controller::openAndReadFile(string& text,const string fileName)
{
	auto helpFile = std::ifstream(fileName);
	if (!helpFile) {
		std::cerr << "failed to open input file\n";
		exit(EXIT_FAILURE);
	}
	//read all text from file
	text = string((std::istreambuf_iterator<char>(helpFile)), std::istreambuf_iterator<char>());
	helpFile.close();
}
//-------------------------------------------------------------------
//this function handle all commands
bool Controller::do_command() {
	string command;
	std::cin >> command;
	if (command == EVAL_COMMAND){doEval();}
	
	else if (command == COMP_COMMAND){doComp();}
	
	else if (command == UNION_COMMAND){doUnion();}
	
	else if (command == INTER_COMMAND){doIntersection();}
	
	else if (command == DIFFER_COMMAND){doDifference();}
	
	else if (command == PROD_COMMAND){doProd();}
	
	else if (command == DEL_COMMAND)
	{
		int func_num;
		std::cin >> func_num;
		do_del(func_num);
	}
	else if (command == COMMAND_HELP){std::cout << m_help << std::endl; }
	
	else if (command == EXIT_COMMAND)
	{
		cout << EXIT_MSG;
		return EXIT;
	}
	else { std::cerr << INVALID_COMMAND << std::endl; }
	return CONTINUE;
}
//-------------------------------------------------------------------
bool Controller::isExistFunc(const int& fun_num)
{
	return 0 <= fun_num && fun_num < m_operations.size();
}
//-------------------------------------------------------------------
//overload function checking if the command exist if so delete it
void Controller::isExistFunc() {
	auto wanted = m_operations[m_operations.size() - 1]->getlabel();
	auto toDelete = false;
	for (size_t i = 0; i < m_operations.size()-1; i++)
	{
		if (m_operations[i]->getlabel() == wanted) {
			toDelete = true;
			break;
		}
	}
	if (toDelete)
	{
		m_operations.erase(m_operations.end()-1);
		std::cout << FUNC_EXIST_MSG;
	}
	else
		std::cout << ADDED_MSG;
}
//-------------------------------------------------------------------
//this function reading all data from the groups by the number of the needed command
void Controller::read_inp(vector<Set>& sets, const int& funNum) {
	int size;
	for (size_t i = 0; i < m_operations[funNum]->getNumOfGroups(); i++)
	{
		std::cin >> size;
		sets.emplace_back();
		sets[i].resize(size);
		std::cin >> sets[i];//insert values from the user by 
	}
}