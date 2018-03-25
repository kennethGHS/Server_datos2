//
// Created by kenneth on 25/03/18.
//

#ifndef SERVER_D2_SERVER_H
#define SERVER_D2_SERVER_H

#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <json-c/json.h>
class Server {
public :
    int client,server;
    int portNum =1500;
    bool isExit= false;
    const int bufsize=1024;
    char buffer[1024];
    struct sockaddr_in server_addr;
    socklen_t size;
    void initiateConection();
    void parseObject(char* object);
    void sendJson(char* json);
};


#endif //SERVER_D2_SERVER_H
