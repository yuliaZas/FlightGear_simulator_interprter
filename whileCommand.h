#pragma once
#include "command.h"
class whileCommand :
	public command
{
public:
	whileCommand();
	~whileCommand();
	int execute(vector <string> args, int index, map<string, double> *symbolTable, map<string, command*> commandParser, map<string, string> *bindMap);
};

