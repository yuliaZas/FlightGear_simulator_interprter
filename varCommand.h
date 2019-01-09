#pragma once
#include "command.h"
#include <string>
#include <map>
class varCommand :
	public command
{
public:
	varCommand();
	~varCommand();
	int execute(vector <string> args, int index, map<string, double> *symbolTable, map<string, command*> commandParser, map<string, string> *bindMap);
};

