#include "assigmentCommand.h"



assigmentCommand::assigmentCommand()
{
}


assigmentCommand::~assigmentCommand()
{
}

int assigmentCommand::execute(vector <string> args, int index, map<string, double> *symbolTable, map<string, command*> commandParser, map<string, string> *bindMap)
{
	double newValue;
	string varName;
	map <string, double>::iterator iter;
	iter = symbolTable->find(args[index - 1]);
	if (iter == symbolTable->end()) {
		printf("invalid input");
		return 2;
	}
	if (args[index + 1] == "bind"){
		bindMap->insert(std::pair<string, string>(args[index - 1], args[index + 2]));
		return 3;
	}
	else{
		try {
			newValue = std::stod(args[index + 1]);
		}
		catch (std::exception invalid_argument) {
			printf("invalid input");
			return 2;
		}
		iter->second = newValue;
		return 2;
	}


}
