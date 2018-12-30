#pragma once
#include "command.h"
#include "Expression/ExpressionFactory.h"
#include "Parser.h"
class ifCommand :
	public command
{
public:
	ifCommand();
	~ifCommand();
	int execute(vector <string> args, int index, map<string, double> *symbolTable, map<string, command*> commandParser, map<string, string> *bindMap);
};

