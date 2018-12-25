#pragma once
#include "command/command.h"
#include <string>
#include <iostream>       // std::cout, std::endl
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
using std::string;
class sleepCommand :
	public command
{
public:
	sleepCommand();
	~sleepCommand();
	int execute(vector <string> args, int index, map<string, double> *symbolTable, map<string, command*> commandParser, map<string, string> *bindMap);
};

