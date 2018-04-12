//
// Created by kenneth on 25/02/18.
//

#ifndef ESTRUCTURES_SIMPLE_LIST_H
#define ESTRUCTURES_SIMPLE_LIST_H

#include "Simple_Node.h"
template <typename T>
class Simple_List {
public:
    int lenght =0;
    Simple_Node<T>* head = nullptr;
    Simple_Node<T>* tail = nullptr;
    void addNode(T );
    void insertNode(T,int);
    void insertNodeHead(T);
    void insertNodeTail(T);
    void deleteTail();
    void deleteHead();
    void deletePosition(int);
    void printList();
    void editar(int,T);
    Simple_Node<T>* get(int);
    void destroyList();


};


#endif //ESTRUCTURES_SIMPLE_LIST_H
