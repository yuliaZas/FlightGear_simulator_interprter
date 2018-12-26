#pragma once
#include "command.h"

struct dataC{
	int portNum;
	char* server;
};
class connectCommand :
	public command
{
public:
	connectCommand();
	~connectCommand();
	int execute(vector <string> args, int index, map<string, double> *symbolTable, map<string, command*> commandParser, map<string, string> *bindMap);
};

