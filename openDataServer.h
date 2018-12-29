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


void* openServer(void* args);
void get(char buffer[256]);
void exit();

#endif //FLIGHT_SIMULATOR_OPENDATASERVER_H
