//
// Created by miri on 29/12/18.
//

#ifndef FLIGHT_SIMULATOR_EXITCOMMAND_H
#define FLIGHT_SIMULATOR_EXITCOMMAND_H

#include "command.h"
#include "openDataServer.h"
class exitCommand : public command {
    int execute(vector <string> args, int index, map<string, double> *symbolTable, map<string, command*> commandParser, map<string, string> *bindMap);
};


#endif //FLIGHT_SIMULATOR_EXITCOMMAND_H
