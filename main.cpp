#include <iostream>
#include <jsoncpp/json/json.h>
#include <json-c/json.h>
#include <thread>
#include "Server.h"
#include "threading/MyThread.h"

void activation(){
    Server* servidor = new Server();
    servidor->initiateConection();
}
int main() {

//    std::cout << "Hello, World!" << std::endl;
//    Json::Value lol;
//    lol["kol"];
//
    MyThread* threaded = new MyThread();
    threaded->addT(activation);
    threaded->startT();
    std::cout<<"ALJFHKJAFHJKAFKJ"<<std::endl;
    while (true){

    }
//   struct json_object* objeto = json_object_new_object();
//    struct json_object* str1 = json_object_new_string("PARSEO 1 :D");
//    struct json_object* str2 = json_object_new_string("MAS DE ESO ES EL NUMERO 2");
//     json_object_object_add(objeto,"Valor",str1);
//     json_object_object_add(objeto,"Valor2",str2);
//    std::cout<<json_object_to_json_string(objeto)<<"\n";
//    std::cout<<json_object_to_json_string(json_object_object_get(objeto,"Valor"));
    return 0;

}