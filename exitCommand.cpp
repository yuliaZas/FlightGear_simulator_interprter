//
// Created by miri on 29/12/18.
//

#include "exitCommand.h"
int exitCommand::execute(vector <string> args, int index, map<string, double> *symbolTable, map<string, command*> commandParser, map<string, string> *bindMap){
    exit();
}