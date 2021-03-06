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
#include "exitCommand.h"
#include "Expression/ExpressionFactory.h"

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
	void preParser();
};

