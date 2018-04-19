//
// Created by kenneth on 11/04/18.
//

#include <iostream>
#include "Maper.h"
/**
 * MAPEO de todas las variables
 * @param value
 */
void Maper::add_variable(int value) {
    std::cout<<"Entro el valor"<<value<<std::endl;
    if(freeposition>bites-bites/10){
        freeposition=0;
    }
    *(int*)((char*)variables+freeposition) =value;
    freeposition+=4;
}
void Maper::add_variable(bool value) {
    std::cout<<"Entro el valor"<<value<<std::endl;
    if(freeposition>bites-bites/10){
        freeposition=0;
    }
    *(bool*)((char*)variables+freeposition) =value;
    freeposition+=1;
}
void Maper::add_variable(char value) {
    std::cout<<"Entro el valor"<<value<<std::endl;
    if(freeposition>bites-bites/10){
        freeposition=0;
    }
    *(char*)((char*)variables+freeposition) =value;
    freeposition+=1;
}
void Maper::add_variable(float value) {
    std::cout<<"Entro el valor"<<value<<std::endl;
    if(freeposition>bites-bites/10){
        freeposition=0;
    }
    *(float *)((char*)variables+freeposition) =value;
    freeposition+=4;
}
void Maper::add_variable(double value) {
    std::cout<<"Entro el valor"<<value<<std::endl;
    if(freeposition>bites-bites/10){
        freeposition=0;
    }
    *(double *)((char*)variables+freeposition) =value;
    freeposition+=8;

}
void Maper::add_variable(long variable) {
    std::cout<<"Entro el valor"<<variable<<std::endl;
    if(freeposition>bites-bites/10){
        freeposition=0;
    }
    *(long *)((char*)variables+freeposition) =variable;
    freeposition+=8;
}
void Maper::free_memory() {
    free(variables);
    variables = malloc(bites);
    freeposition=0;
}
