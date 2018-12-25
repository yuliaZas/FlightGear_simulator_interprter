#pragma once
#include "command.h"
#include <iostream>
#include <string>
using namespace std;	
class printCommand :
	public command
{
public:
	printCommand();
	~printCommand();
	int execute(vector <string> args, int index, map<string, double> *symbolTable, map<string, command*> commandParser);
};

