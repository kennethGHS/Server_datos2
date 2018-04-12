//
// Created by dario1227 on 11/04/18.
//

#ifndef SERVER_D2_MYTHREAD_H
#define SERVER_D2_MYTHREAD_H


class ListaSimple;
class MyThread {
public:
    MyThread();
    ListaSimple* lista= nullptr;
    void addT(void (*function)());
    void startT();

};


#endif //SERVER_D2_MYTHREAD_H
