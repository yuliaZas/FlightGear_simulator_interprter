#include "ODSCommand.h"



ODSCommand::ODSCommand()
{
}


ODSCommand::~ODSCommand()
{
}

int ODSCommand::execute(vector<string> args, int index, map<string, double>* symbolTable, map<string, command*> commandParser, map<string, string> *bindMap)
{
    pthread_t pthreadID;
    struct data* d = new data();
    d->bind = bindMap;
    try{
        int portNum = (int) stod(args[index +1]);
        int sec = (int) stod(args[index +2]);
        d->portNamber = portNum;
        d->seconds = sec;
    }
    catch (exception& invalid_argument){
        cout << "invalid input" << endl;
        return 3;
    }
    pthread_create(&pthreadID, nullptr, openServer, d);
    pthread_join(pthreadID, nullptr);
    return 3;
}
