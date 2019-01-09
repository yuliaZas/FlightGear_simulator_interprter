#pragma once
#include "command.h"
#include <pthread.h>
#include "connectToServer.h"
class assigmentCommand :
        public command
{
public:
    assigmentCommand();
    ~assigmentCommand();
    int execute(vector <string> args, int index, map<string, double> *symbolTable, map<string, command*> commandParser, map<string, string> *bindMap);
};
