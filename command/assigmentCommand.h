#pragma once
#include "command.h"
class assigmentCommand :
	public command
{
public:
	assigmentCommand();
	~assigmentCommand();
	int execute(vector <string> args, int index, map<string, double> *symbolTable, map<string, command*> commandParser, map<string, string> *bindMap);
};

