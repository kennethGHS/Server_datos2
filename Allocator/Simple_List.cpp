//
// Created by kenneth on 25/02/18.
//

#include "Simple_List.h"
#include <iostream>

template <typename T>
void Simple_List<T>::deletePosition(int numero) {
    if(head== nullptr){
        return;
    }
    if(numero>lenght){
        return;
    }

    if(numero==0){
        if(head==tail){
            lenght--;
            head= nullptr;

            delete tail;
            tail= nullptr;
            return;
        }
        lenght--;
        Simple_Node<T>* headed = this->head;
        this->head= headed->next;
        headed->~Simple_Node();
        return;
    }
    if(numero==lenght-1){
        return deleteTail();
    }
    else{
        Simple_Node<T>* node=get(numero-1);
        Simple_Node<T>* node_to_delete = node->next;
        node->next= node_to_delete->next;
        lenght--;
        delete node_to_delete;
        return;
    }

}
template <typename T>
Simple_Node<T>* Simple_List<T>::get(int num) {
    if(num<0){
        return nullptr;
    }
    if (num>=lenght){
        return nullptr;
    }
    Simple_Node<T>* nodo = this->head;
    if(num==0){
        return head;
    }
    if(num==lenght-1){
        return tail;
    }
    while(num>0){
        num--;
        nodo=nodo->next;
    }
    return nodo;
}
template <typename T>
void Simple_List<T>::deleteTail() {
    if(head== nullptr){
        return;
    }
    if(head==tail){
        delete head;
        lenght--;
        head== nullptr;
        tail== nullptr;
        return;
    }
    lenght--;
    Simple_Node<T>* nodo = this->get(lenght-2);
    delete nodo->next->valor;
    nodo->next= nullptr;
    this->tail=nodo;
}
template <typename T>
void Simple_List<T>::addNode(T valor) {
    lenght++;
    Simple_Node<T>* nodo= new Simple_Node<T>(valor);
    if(head== nullptr){
        head=nodo;
        tail=nodo;
        return;
    }
    else{
        tail->next=nodo;
        tail=nodo;
    }
}
template <typename T>
void Simple_List<T>::deleteHead() {
    if(head== nullptr){
        return;
    }
    if(this->head==this->tail){
        lenght--;
        delete head;
        head= nullptr;
        tail= nullptr;
        return;
    }
    else{
        lenght--;
        Simple_Node<T>* nodo = head;
        head=nodo->next;
        delete nodo;
    }
}
template <typename T>
void Simple_List<T>::printList() {
    Simple_Node<T>* nodo = head;
    while(nodo!=nullptr){
        std::cout << nodo->valor << std::endl;
        nodo = nodo->next;
    }
}template <typename T>
void Simple_List<T>::editar(int num, T valor)  {
    if(num<0){
        return ;
    }
    Simple_Node<T>* nodo = this->head;
    if(num==0){
        head->valor=valor;
        return;
    }
    if(num==lenght-1){
tail->valor=valor;
        return;
    }
    while(num>0){
        num--;
        nodo=nodo->next;
    }
nodo->valor=valor;
}
template <typename T>
void Simple_List<T>::insertNode(T valor, int numero) {
    if(numero>lenght){
        return;
    }
    if(numero==lenght-1){
        addNode(valor);
        return;
    }
    if(numero==0){
        insertNodeHead(valor);
        return;
    }
    if(numero<lenght-1){
    Simple_Node<T>* nodo =get(numero-1);
    Simple_Node<T>* nodo2 = new Simple_Node<T>(valor);
        nodo2->next=nodo->next;
        nodo->next=nodo2;
        lenght++;
    }
}
template <typename T>
void Simple_List<T>::insertNodeHead(T value) {
    lenght++;
    Simple_Node<T>* nodo = new Simple_Node<T>(value);;
    if(this->head== nullptr){
        this->head=nodo;
        this->tail=nodo;
        return;
    }
    else{
        nodo->next=head;
        head=nodo;
    }
}
template <typename T>

void Simple_List<T>::destroyList() {
    if(this->head== nullptr){
        return;
    }
   Simple_Node<T>* nodo=this->head;
    this->head= nullptr;
    while(nodo!= nullptr){
        if(nodo==this->tail){
            tail= nullptr;
        }
        nodo->eliminateNodeValue();
        Simple_Node<T>* next =nodo->next;
        delete nodo;
        nodo=next;
    }
}
template class Simple_List<char*>;
