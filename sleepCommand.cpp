#include "sleepCommand.h"



sleepCommand::sleepCommand()
{
}


sleepCommand::~sleepCommand()
{
}

int sleepCommand::execute(vector <string> args, int index, map<string, double> *symbolTable, map<string, command*> commandParser)
{
	double sleepTime;
	try {
		 sleepTime = stod(args[index + 1]);
	}
	catch (std::exception invalid_argument) {
		map <string, double>::iterator iter;
		iter = symbolTable->find(args[index + 1]);
		if (iter == symbolTable->end()) {
			printf("invalid input");
			return 2;
		}
		else {
			sleepTime = iter->second;
		}
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(int(sleepTime)));
	return 2;
}
