//
// Created by kenneth on 25/03/18.
//
#include <iostream>
#include "Server.h"
#include "Json_Factory.h"
#include <json-c/json_tokener.h>
void Server::initiateConection() {
    int client, server;
    int portNum = 1500;
    bool isExit = false;
    int bufsize = 1024;
    char buffer[bufsize];
//
    struct sockaddr_in server_addr;
    socklen_t size;
    client = socket(AF_INET, SOCK_STREAM, 0);

    if (client < 0)
    {
        std::cout << "\nError establishing socket..." << std::endl;
        exit(1);
    }
    std::cout << "\n=> Socket server has been created..." << std::endl;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(portNum);
    if ((bind(client, (struct sockaddr*)&server_addr,sizeof(server_addr))) < 0)
    {
        std::cout << "=> Error binding connection, the socket has already been established..." << std::endl;
        return ;
    }
    size = sizeof(server_addr);
    std::cout << "=> Looking for clients..." << std::endl;

    /* ------------- LISTENING CALL ------------- */
    /* ---------------- listen() ---------------- */

    listen(client, 1);
    int clientCount = 1;
    server = accept(client,(struct sockaddr *)&server_addr,&size);
this->server=server;
    // first check if it is valid or not
    if (server < 0)
        std::cout << "=> Error on accepting..." << std::endl;
    int counter = 0;
    while (server > 0)
    {
        try {
            if (counter == 0) {
                strcpy(buffer, "=> Server connected...\n");
                counter++;
//
                send(server, buffer, bufsize, 0);
                std::cout << "=> Connected with the client #" << clientCount << ", you are good to go..." << std::endl;
                std::cout << "\n=> Enter # to end the connection\n" << std::endl;
            }
            recv(server, buffer, bufsize, 0);
            if (buffer == nullptr || sizeof(buffer) == 0) {
                return;
            }
            std::cout << buffer << "JSON recibido....." << "\n" << "Parsing" << "\n";
            json_object *variable = parseObject(buffer);

            if (variable == nullptr) {
                std::cout << "ERROR se perdio la conexion con el servidor" << std::endl;
                return;
            }
            json_object_put(variable);
        }catch(__exception){
            return;
        }

    }


}
/**
 * parsea el objeto
 * @param object
 * @return lol
 */
json_object* Server::parseObject(char *object) {

    if(object== nullptr){
        std::cout<<"LLOLOLOL"<<std::endl;
    }
    //
    std::cout<<object<<std::endl;
    json_object* json = json_tokener_parse(object);
    json_object* to_Return=Json_Factory::createJson(json);
    if(to_Return== nullptr){
        return nullptr;
    }
    std::cout<<json_object_to_json_string(to_Return)<<std::endl;
    const char* enviar =json_object_to_json_string(to_Return);
    send(server,enviar,bufsize,0);
    return to_Return;

//    while(server>0){
//        std::cout<<"ENTRE EN LA ESPERA"<<std::endl;
//        strcpy(buffer,"ServerConnected////\n");
//
//    }
}

const char *Server::parse(char *object) {
    QString str = QString(object);
    QString vara = QString();
    int index = 0;
    int parenCounter=0;
}
