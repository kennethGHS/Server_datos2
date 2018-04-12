//
// Created by dario1227 on 11/04/18.
//
#include <iostream>
using namespace std;
#include "ListaSimple.h"
#include "NodoS.h"

ListaSimple::ListaSimple() {
    this->head= nullptr;
}
void ListaSimple::addL(NodoS* nodo) {
    this->large++;
    if(this->head== nullptr){
        this->head=nodo;

    }
    else{
        NodoS* temp=this->head;
        while(temp->next!= nullptr){
            temp=temp->next;
        }
        temp->next=nodo;
    }
}
void ListaSimple::delF() {
    if(this->head== nullptr){
        cout<<"Lista Vacia";
    }
    else{
        this->large--;
        this->head=this->head->next;
    }
}

void ListaSimple::delL() {
    if(this->head== nullptr){
        cout<<"Lista Vacia";
    }
    else if(this->head->next== nullptr){
        this->large--;
        this->head= nullptr;
    }
    else{
        this->large--;
        NodoS* nodo=this->head;
        while(nodo->next->next!= nullptr){
            nodo=nodo->next;
        }
        nodo->next= nullptr;
    }
}
void ListaSimple::del(int pos) {
    if(pos>this->large){
        cout<<"Fuera de rango";
    }
    else if(pos==0){
        ListaSimple::delF();
    }
    else if(pos==this->large){
        ListaSimple::delL();
    }
    else{
        this->large--;
        NodoS* temp=this->head;
        for(int y=0;y<pos-1;y++){
            temp=temp->next;
        }
        NodoS* temp2=temp->next;
        temp->next=temp2->next;

    }
}
