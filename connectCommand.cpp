#include "connectCommand.h"



connectCommand::connectCommand()
{
}


connectCommand::~connectCommand()
{
}

int connectCommand::execute(vector<string> args, int index, map<string, double>* symbolTable, map<string, command*> commandParser, map<string, string> *bindMap)
{
	string SserverIP = args[index + 1];
	char CserverIP[SserverIP.length()];
	// convert string to char*
	for(int i=0; i< SserverIP.length();i++){
		CserverIP[i] = SserverIP.at(i);
	}
	int port;
	// try to convert port number to an int
	try{
		port =  std::stoi(args[index + 2]);
	}
	catch(std::exception& invalid_argument){
		printf("invalid input");
	}
	// build data struct
	struct dataC dc;
	dc.portNum = port;
	dc.server = CserverIP;
    // call connect func
	connectToServer::connectTo(&dc);

	return 3;
}
