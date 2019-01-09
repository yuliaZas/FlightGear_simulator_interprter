//
// Created by miri on 26/12/18.
//

#ifndef FLIGHT_SIMULATOR_CONNECTTOSERVER_H
#define FLIGHT_SIMULATOR_CONNECTTOSERVER_H

#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>
#include <string>
#include "connectCommand.h"


class connectToServer{
public:
    static void set(const char* massege);
    static void* connectTo(void* args);

};



#endif //FLIGHT_SIMULATOR_CONNECTTOSERVER_H
