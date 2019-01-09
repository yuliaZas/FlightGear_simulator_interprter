#pragma once
#include "command.h"
#include "openDataServer.h"
#include <pthread.h>
#include <string>
#include <iostream>
using namespace std;

struct data{
	int portNamber;
	int seconds;
	map<string, string> *bind;
};
class ODSCommand :
	public command
{
public:
	ODSCommand();
	~ODSCommand();
	int execute(vector <string> args, int index, map<string, double> *symbolTable, map<string, command*> commandParser, map<string, string> *bindMap);
};

