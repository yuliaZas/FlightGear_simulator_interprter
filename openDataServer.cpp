//
// Created by miri on 25/12/18.
//
int socfd;
#include "openDataServer.h"
void* openServer(void* ar){
    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int  n;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    socfd = sockfd;

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 5400;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    /* If connection is established then start communicating */
    bzero(buffer,256);
    n = read( newsockfd,buffer,255 );

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("Here is the message: %s\n",buffer);

    /* Write a response to the client */
    n = write(newsockfd,"I got your message",18);

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
}
void get(char buffer[256],map<string,string>* bindMap, map<string,double>* symboleTable){
    double values[23];
    stringstream parser;
    int i = 0;
    string str;
    str += buffer;

    parser.str(str);
    while (parser.good() && i < 23) {
        string value;
        getline(parser,value,',');
        values[i] = strtod(value.c_str(), nullptr);
        i++;
    }
    parser.clear();

    setValue("/instrumentation/airspeed-indicator/indicated-speed-kt",values[0], bindMap, symboleTable);
    setValue("/instrumentation/altimeter/indicated-altitude-ft",values[1],bindMap,symboleTable);
    setValue("/instrumentation/altimeter/pressure-alt-ft",values[2],bindMap,symboleTable);
    setValue("/instrumentation/attitude-indicator/indicated-pitch-deg",values[3],bindMap,symboleTable);
    setValue("/instrumentation/attitude-indicator/indicated-roll-deg",values[4],bindMap,symboleTable);
    setValue("/instrumentation/attitude-indicator/internal-pitch-deg",values[5],bindMap,symboleTable);
    setValue("/instrumentation/attitude-indicator/internal-roll-deg",values[6],bindMap,symboleTable);
    setValue("/instrumentation/encoder/indicated-altitude-ft",values[7],bindMap,symboleTable);
    setValue("/instrumentation/encoder/pressure-alt-ft",values[8],bindMap,symboleTable);
    setValue("/instrumentation/gps/indicated-altitude-ft",values[9],bindMap,symboleTable);
    setValue("/instrumentation/gps/indicated-ground-speed-kt",values[10],bindMap,symboleTable);
    setValue("/instrumentation/gps/indicated-vertical-speed",values[11],bindMap,symboleTable);
    setValue("/instrumentation/heading-indicator/indicated-heading-deg",values[12],bindMap,symboleTable);
    setValue("/instrumentation/magnetic-compass/indicated-heading-deg",values[13],bindMap,symboleTable);
    setValue("/instrumentation/slip-skid-ball/indicated-slip-skid",values[14],bindMap,symboleTable);
    setValue("/instrumentation/turn-indicator/indicated-turn-rate",values[15],bindMap,symboleTable);
    setValue("/instrumentation/vertical-speed-indicator/indicated-speed-fpm",values[16],bindMap,symboleTable);
    setValue("/controls/flight/aileron",values[17],bindMap,symboleTable);
    setValue("/controls/flight/elevator",values[18],bindMap,symboleTable);
    setValue("/controls/flight/rudder",values[19],bindMap,symboleTable);
    setValue("/controls/flight/flaps",values[20],bindMap,symboleTable);
    setValue("/controls/engines/current-engine/throttle",values[21],bindMap,symboleTable);
    setValue("/engines/engine/rpm",values[22],bindMap,symboleTable);

}

void setValue(string str,double newVal ,map<string,string>* bindMap, map<string,double>* symboleTable) {
    if (bindMap->count(str) == 1) {
        symboleTable->at(bindMap->at(str)) = newVal;
    }
}

void exit(){
    close(socfd);
}