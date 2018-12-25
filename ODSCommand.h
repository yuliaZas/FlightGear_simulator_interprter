#pragma once
#include "command.h"
class ODSCommand :
	public command
{
public:
	ODSCommand();
	~ODSCommand();
	int execute(vector <string> args, int index, map<string, double> *symbolTable, map<string, command*> commandParser);
};

