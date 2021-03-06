#pragma once
#include "command.h"
#include "Expression/ExpressionFactory.h"
#include "Parser.h"
class whileCommand :
	public command
{
public:
	whileCommand();
	~whileCommand();
	int execute(vector <string> args, int index, map<string, double> *symbolTable, map<string, command*> commandParser, map<string, string> *bindMap);
};

