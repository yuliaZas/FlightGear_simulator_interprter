#include "connectCommand.h"



connectCommand::connectCommand()
{
}


connectCommand::~connectCommand()
{
}

int connectCommand::execute(vector<string> args, int index, map<string, double>* symbolTable, map<string, command*> commandParser, map<string, string> *bindMap)
{
	string serverIP = args[index + 1];
	int port;
	try{
		port =  std::stoi(args[index + 2]);
	}
	catch(std::exception& invalid_argument){
		printf("invalid input");
	}
	struct dataC* dc;
	dc->portNum = port;
	dc->server = serverIP;

	connectToServer::connectTo(dc);

	return 0;
}
