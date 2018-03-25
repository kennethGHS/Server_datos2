//
// Created by kenneth on 25/03/18.
//
#include <iostream>
#include "Json_Factory.h"
json_object* Json_Factory::createJson(json_object *objeto) {
    char character = json_object_to_json_string(json_object_object_get(objeto,"Type"))[0];
    if(character=='C'){
        std::cout<<"Maping type Char"<<"\n";
        return createCharJson(objeto);
    }
    if(character=='D'){
        std::cout<<"Maping type Double"<<"\n";
        return createDoubleJson(objeto);
    }
    if(character=='F'){
        std::cout<<"Maping type Float"<<"\n";
        return createFloatJson(objeto);
    }
    if(character=='I'){
        std::cout<<"Maping type Int"<<"\n";
        return createIntJson(objeto);
    }
    if(character=='L'){
        std::cout<<"Maping type Long"<<"\n";
        return createLongJson(objeto);
    }
    if(character=='R'){
        std::cout<<"Maping type Reference"<<"\n";
        return createReferenceJson(objeto);

    }
    if(character=='S'){
        std::cout<<"Maping type Struct"<<"\n";
        return createStructJson(objeto);
    }
}
json_object* Json_Factory::createCharJson(json_object *objeto) {
    struct json_object* str1 = json_object_new_string("1");
    char *character =(char*)malloc(sizeof(char));
    json_object_object_add(objeto,"Tamano",str1);
    return objeto;

}
json_object* Json_Factory::createDoubleJson(json_object *objeto) {
    struct json_object* str1 = json_object_new_string("8");
    double *character =(double*)malloc(sizeof(double));
    json_object_object_add(objeto,"Tamano",str1);
    return objeto;
}
json_object* Json_Factory::createFloatJson(json_object *objeto) {
    struct json_object* str1 = json_object_new_string("4");
    float *character =(float*)malloc(sizeof(float));
    json_object_object_add(objeto,"Tamano",str1);
    return objeto;
}
json_object* Json_Factory::createIntJson(json_object *objeto) {
    struct json_object* str1 = json_object_new_string("4");
    int *character =(int*)malloc(sizeof(int));
    json_object_object_add(objeto,"Tamano",str1);
    return objeto;
}
json_object* Json_Factory::createLongJson(json_object *objeto) {
    struct json_object* str1 = json_object_new_string("8");
    long *character =(long*)malloc(sizeof(long));
    json_object_object_add(objeto,"Tamano",str1);
    return objeto;
}
json_object* Json_Factory::createReferenceJson(json_object *objeto) {
    struct json_object* str1 = json_object_new_string("4");
    int* *character =(int**)malloc(sizeof(int*));
    json_object_object_add(objeto,"Tamano",str1);
    return objeto;
}
json_object* Json_Factory::createStructJson(json_object *objeto) {
    struct json_object* str1 = json_object_new_string("4");
    int *character =(int*)malloc(sizeof(int));
    json_object_object_add(objeto,"Tamano",str1);
    return objeto;
}
