//
// Created by kenneth on 25/03/18.
//
#include <iostream>
#include "Server.h"
#include "Json_Factory.h"

void Server::initiateConection() {

    client=socket(AF_INET,SOCK_STREAM,0);
    if(client<0){
        std::cout<<"ERROR CREATING SOCKET"<< "\n";
        exit(1);
    }
    std::cout<<"Server created"<<"\n";
    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    server_addr.sin_port=htonl(portNum);
    if((bind(client,(struct sockaddr*)&server_addr, sizeof(server_addr)))<0){
        std::cout<<"ERROR enlazando coneecion, el socket ya se ha establecido"<<"\n";
        return;
    }
    size= sizeof(server_addr);
    std::cout<<"Buscando un cliente....."<<"\n";
    listen(client,1);
    int clientCount = 1;
    server= accept(client,(struct sockaddr*)&server_addr,&size);
    if (server<0){
        std::cout<<"ERROR, no acpetado"<<"\n";
    }
    while(server>0){
        strcpy(buffer,"ServerConnected////\n");
        recv(server,buffer,bufsize,0);
        std::cout<<buffer<<"JSON recibido....."<<"\n"<<"Parsing"<<"\n";
        parseObject(buffer);
    }
}
void Server::parseObject(char *object) {
    json_object* json = json_tokener_parse(object);
    json_object* to_Return=Json_Factory::createJson(json);
    send(server,json_object_to_json_string(to_Return),bufsize,0);


}