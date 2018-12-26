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


class openDataServer {
public:
    static void* openServer(void* args);
};


#endif //FLIGHT_SIMULATOR_OPENDATASERVER_H
