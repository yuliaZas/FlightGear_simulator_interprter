#include "varCommand.h"



varCommand::varCommand()
{
}


varCommand::~varCommand()
{
}
int varCommand::execute(vector <string> args, int index, map<string, double> *symbolTable, map<string, command*> commandParser) {
	int indexIndent;
	double varValue;
	std::string varName = args[index + 1];
	if (args[index + 2] == "=") {
		indexIndent = 4;
		try {
			varValue = std::stod(args[index + 3]);
		}
		catch (std::exception invalid_argument) {
			map <string, double>::iterator iter;
			iter = symbolTable->find(args[index + 1]);
			if (iter == symbolTable->end()) {
				printf("invalid input");
				return indexIndent;
			}
			else {
				varValue = iter->second;
			}
		}
	}
	else {
		indexIndent = 2;
		varValue = 0;
	}
	symbolTable->insert (std::pair <string, double>(varName, varValue));
	return indexIndent;
}