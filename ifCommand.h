#pragma once
#include "command.h"
class ifCommand :
	public command
{
public:
	ifCommand();
	~ifCommand();
	int execute(vector <string> args, int index, map<string, double> *symbolTable, map<string, command*> commandParser, map<string, string> *bindMap);
};

