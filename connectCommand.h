#pragma once
#include "command.h"
#include "connectToServer.h"

struct dataC{
	int portNum;
	string server;
};
class connectCommand :
	public command
{
public:
	connectCommand();
	~connectCommand();
	int execute(vector <string> args, int index, map<string, double> *symbolTable, map<string, command*> commandParser, map<string, string> *bindMap);
};

