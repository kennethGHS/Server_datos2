//
// Created by kenneth on 11/04/18.
//

#include "Maper.h"
void Maper::add_variable(int value) {
    *(int*)((char*)variables+freeposition) =value;
    freeposition+=4;
}
void Maper::add_variable(bool value) {
    *(bool*)((char*)variables+freeposition) =value;
    freeposition+=1;
}
void Maper::add_variable(char value) {
    *(char*)((char*)variables+freeposition) =value;
    freeposition+=1;
}
void Maper::add_variable(float value) {
    *(float *)((char*)variables+freeposition) =value;
    freeposition+=4;
}
void Maper::add_variable(double value) {
    *(double *)((char*)variables+freeposition) =value;
    freeposition+=8;

}
void Maper::add_variable(long variable) {
    *(long *)((char*)variables+freeposition) =variable;
    freeposition+=8;
}
void Maper::free_memory() {
    free(variables);
    variables = malloc(bites);
    freeposition=0;
}
