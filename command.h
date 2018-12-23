#pragma once
#include <string>
#include <vector>
#include <map>
using std::vector;
using std::string;
using std::map;
class command
{
	
public:
	command();
	~command();
public:
	virtual int execute(vector <string> args, int index, map<string, double> *symbolTable, map<string, command*> commandParser) = 0;
};

