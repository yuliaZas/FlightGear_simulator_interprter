#pragma once
#include <map>
#include <string>
#include <vector>
#include "command/command.h"
#include "command/assigmentCommand.h"
#include "command/printCommand.h"
#include "command/sleepCommand.h"
#include "command/varCommand.h"
#include "command/ODSCommand.h"
#include "command/connectCommand.h"
#include "command/whileCommand.h"
#include "command/ifCommand.h"

using namespace std;
class Parser
{
private:
	map<string, double> symbolTable;
	map<string, command*> commandMap;
	map<string, string> bindMap;
	vector<string> tokens;
public:
	Parser(vector<string> args);
	~Parser();
	int parse();
};

