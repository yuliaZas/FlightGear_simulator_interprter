#include <utility>

#include "Parser.h"



Parser::Parser(vector<string> args)
{
	// Initializa an empty symbol table
	this->symbolTable = map<string, double>();
	this->tokens = std::move(args);
	// initialize all the commands
	command* ODSCom = new ODSCommand();
	command* connectCom = new connectCommand();
	command* varCom = new varCommand();
	command* assignCom = new assigmentCommand();
	command* whileCom = new whileCommand();
	command* printCom = new printCommand();
	command* sleepCom = new sleepCommand();
	command* ifCom = new ifCommand();
	command* exitCom = new exitCommand();
	// Initialize a command map
	this->commandMap = map<string, command*>();
	// insert the commands into the command map
	commandMap.insert(pair<string, command*>("openDataServer", ODSCom));
	commandMap.insert(pair<string, command*>("connect", connectCom));
	commandMap.insert(pair<string, command*>("var", varCom));
	commandMap.insert(pair<string, command*>("=", assignCom));
	commandMap.insert(pair<string, command*>("while", whileCom));
	commandMap.insert(pair<string, command*>("print", printCom));
	commandMap.insert(pair<string, command*>("sleep", sleepCom));
	commandMap.insert(pair<string, command*>("if", ifCom));
	commandMap.insert(pair<string, command*>("exit",exitCom));
	// Initialize an empty bind map
	this->bindMap = map<string, string>();
}


Parser::~Parser()
{
}

int Parser::parse()
{
	int index = 0;
	while (index < tokens.size()) {
		map <string, command*>::iterator iterCom;
		map <string, double>::iterator iterSym;
		iterCom = commandMap.find(tokens[index]);
		if (iterCom == commandMap.end()) {
			iterSym = symbolTable.find(tokens[index]);
			if (iterSym == symbolTable.end()) {
				printf("invalid input");
				return 1;
			}
			else {
				index += 1;
			}
		}
		else {
			index += iterCom->second->execute(tokens, index, &symbolTable, commandMap, &bindMap);
		}
	}
	return 0;
}
