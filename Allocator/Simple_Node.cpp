//
// Created by kenneth on 25/02/18.
//
#include "Simple_Node.h"
template <typename T>
Simple_Node<T>::Simple_Node(T value){
 this->valor=value;
}
template<typename T>
Simple_Node<T>::Simple_Node(T value,int position){
    this->valor=value;
    this->position=position;
}
template class Simple_Node<char*>;
