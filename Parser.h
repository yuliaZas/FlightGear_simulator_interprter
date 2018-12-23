#pragma once
#include <map>
#include <string>
#include <vector>
#include "command.h"
#include "assigmentCommand.h"
#include "printCommand.h"
#include "sleepCommand.h"
#include "varCommand.h"
#include "ODSCommand.h"
#include "connectCommand.h"
#include "whileCommand.h"
#include "ifCommand.h"

using namespace std;
class Parser
{
private:
	map<string, double> symbolTable;
	map<string, command*> commandMap;
	vector<string> tokens;
public:
	Parser(vector<string> args);
	~Parser();
	int parse();
};

