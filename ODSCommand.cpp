#include "ODSCommand.h"



ODSCommand::ODSCommand()
{
}


ODSCommand::~ODSCommand()
{
}

int ODSCommand::execute(vector<string> args, int index, map<string, double>* symbolTable, map<string, command*> commandParser, map<string, string> *bindMap)
{pthread_t pthreadID;
    struct data  d;
    d.bind = bindMap;
    try{
        double portNum = stod(args[index +1]);
        double sec = stod(args[index +2]);
    }
    catch (exception invalid_argument){
        cout << "invalid input" << endl;
        return 2;
    }
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&pthreadID, &attr, openDataServer::openServer, &d);
    return 2;
}
