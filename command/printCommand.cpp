#include "printCommand.h"
printCommand::printCommand()
{
}


printCommand::~printCommand()
{
}

int printCommand::execute(vector <string> args, int index, map<string, double> *symbolTable, map<string, command*> commandParser, map<string, string> *bindMap)
{
	string printString = args[index + 1];
	if (printString[0] == ' " ') {
		printString = printString.substr(1, printString.size() - 2);
	}
	else {
		map <string, double>::iterator iter;
		iter = symbolTable->find(printString);
		if (iter == symbolTable->end()) {
			printString = "invalid input, did you forget \"\"? ";
		}
		else {
			printString = std::to_string(iter->second);
		}
	}
	
	std::cout << printString << endl;
	return 2;
}
