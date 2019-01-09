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
	// add map holder here
	// send the bindMap and symbolTable to it
}


Parser::~Parser()
{
}

int Parser::parse()
{
	Parser::preParser();
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
void Parser::preParser() {
	string expression = "";
	double value;
	ExpressionFactory factory = ExpressionFactory();
	// initialize iterators
	std::vector<string>::iterator start; // to mark the begining of the tokens to delete
	std::vector<string>::iterator end; // to mark the end of the tokens to delete
	std::map<string, command*>::iterator iterCom; // itereat throught the command map
	std::map<string, double >::iterator iterSym; // iteraet throught the symbol table
	for(std::vector<string>::iterator it = this->tokens.begin(); it != this->tokens.end(); ++it) {
		// stop for every =
		if(*it == "="){
			start = it;
			++it;
			if(*it != "bind"){
				iterCom = this->commandMap.find(*it);
				// while the token is not a commend asume its fart of the expression
				while(iterCom == commandMap.end()){
					iterSym = this->symbolTable.find(*it);
					// if this token is not a varible then assume it's a number or a sign and add it to the expression string as is
					if(iterSym == this->symbolTable.end()){
						expression += *it;
					}
						// if the token is a varible add it's value to the string
					else{
						expression +=to_string(iterSym->second);
					}
					++it;
					iterCom = this->commandMap.find(*it);
				}
				// calculate the value of the expression
				ExpressionFactory factory = ExpressionFactory();
				Expression* e = factory.expressionEvaluate(expression);
				// empty exprssion string
				expression = "";
				// place the value in the token array instead of the expression
				*start = std::to_string(value);
				++start;
				// delete exess cells
				tokens.erase(start, end);
			}
			else{
				it++;
			}
		}
	}
}