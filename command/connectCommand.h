#pragma once
#include "command/command.h"
class connectCommand :
	public command
{
public:
	connectCommand();
	~connectCommand();
	int execute(vector <string> args, int index, map<string, double> *symbolTable, map<string, command*> commandParser, map<string, string> *bindMap);
};

