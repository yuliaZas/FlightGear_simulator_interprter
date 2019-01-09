//
// Created by miri on 25/12/18.
//

#ifndef FLIGHT_SIMULATOR_OPENDATASERVER_H
#define FLIGHT_SIMULATOR_OPENDATASERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <sstream>
#include <map>

using namespace std;

void* openServer(void* args);
void get(char, map<string,string>*, map<string,double>*);
/**
 * help func for get. serch for the key to update and update it.
 */
void setValue(string ,double ,map<string,string>*, map<string,double>*);
void exit();

#endif //FLIGHT_SIMULATOR_OPENDATASERVER_H
