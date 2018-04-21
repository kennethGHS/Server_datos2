//
// Created by kenneth on 11/04/18.
//

#ifndef SERVER_D2_MAPER_H
#define SERVER_D2_MAPER_H


#include <cstdlib>
#include "Simple_List.h"

class Maper {
public:
    Simple_List<char*>* vars = new Simple_List<char*>();
    int freeposition = 0;
    int bites;
void* variables = nullptr;
Maper(int bits){
    variables = malloc(bits);
    bites=bits;
}

    void free_memory();
    void add_variable(long variable);
    void add_variable(int value);
    void add_variable(double value);
    void add_variable(char value);
    void add_variable(struct value);
    void add_variable(bool value);
    void add_variable(float value);
    void sumar_free(int var);

};


#endif //SERVER_D2_MAPER_H
