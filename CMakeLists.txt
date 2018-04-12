cmake_minimum_required(VERSION 3.9)
project(Server_d2)

set(CMAKE_CXX_STANDARD 11)

add_executable(Server_d2 main.cpp Server.cpp Server.h Json_Factory.cpp Json_Factory.h MyThread.cpp MyThread.h ListaSimple.cpp ListaSimple.h NodoS.cpp NodoS.h)
target_link_libraries(Server_d2 json-c)
