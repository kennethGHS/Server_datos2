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
    int server;

    const int bufsize=1024;


    void initiateConection();
    void parseObject(char* object);
    void sendJson(char* json);

};


#endif //SERVER_D2_SERVER_H
