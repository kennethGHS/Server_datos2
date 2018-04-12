//
// Created by kenneth on 25/03/18.
//
#include <iostream>
#include "Json_Factory.h"
static Maper* map = new Maper(100000);
json_object* Json_Factory::createJson(json_object *objeto) {
    char character = json_object_to_json_string(json_object_object_get(objeto,"Type"))[1];
    if(character=='c'){
        std::cout<<"Maping type Char"<<"\n";
        return createCharJson(objeto);
    }
    if(character=='d'){
        std::cout<<"Maping type Double"<<"\n";
        return createDoubleJson(objeto);
    }
    if(character=='f'){
        std::cout<<"Maping type Float"<<"\n";
        return createFloatJson(objeto);
    }
    if(character=='i'){
        std::cout<<"Maping type Int"<<"\n";
        return createIntJson(objeto);
    }
    if(character=='l'){
        std::cout<<"Maping type Long"<<"\n";
        return createLongJson(objeto);
    }
    if(character=='r'){
        std::cout<<"Maping type Reference"<<"\n";
        return createReferenceJson(objeto);

    }
    if(character=='s'){
        std::cout<<"Maping type Struct"<<"\n";
        return createStructJson(objeto);
    }
}
json_object* Json_Factory::createCharJson(json_object *objeto) {
    struct json_object* str1 = json_object_new_string(std::to_string(map->freeposition).c_str());
    char *character =(char*)malloc(sizeof(char));

    json_object_object_add(objeto,"Position",str1);
    return objeto;

}
json_object* Json_Factory::createDoubleJson(json_object *objeto) {
    struct json_object* str1 = json_object_new_string(std::to_string(map->freeposition).c_str());
    double *character =(double*)malloc(sizeof(double));

    json_object_object_add(objeto,"Position",str1);
    return objeto;
}
json_object* Json_Factory::createFloatJson(json_object *objeto) {
    struct json_object* str1 = json_object_new_string(std::to_string(map->freeposition).c_str());
    float *character =(float*)malloc(sizeof(float));
    json_object_object_add(objeto,"Position",str1);
    return objeto;
}
json_object* Json_Factory::createIntJson(json_object *objeto) {
    struct json_object* str1 = json_object_new_string(std::to_string(map->freeposition).c_str());
    int *character =(int*)malloc(sizeof(int));
    json_object_object_add(objeto,"Position",str1);
    return objeto;
}
json_object* Json_Factory::createLongJson(json_object *objeto) {
    struct json_object* str1 = json_object_new_string(std::to_string(map->freeposition).c_str());
    long *character =(long*)malloc(sizeof(long));
    json_object_object_add(objeto,"Position",str1);
    return objeto;
}
json_object* Json_Factory::createReferenceJson(json_object *objeto) {
    struct json_object* str1 = json_object_new_string(std::to_string(map->freeposition).c_str());
    int* *character =(int**)malloc(sizeof(int*));
    json_object_object_add(objeto,"Position",str1);
    return objeto;
}
json_object* Json_Factory::createStructJson(json_object *objeto) {
    struct json_object* str1 = json_object_new_string(std::to_string(map->freeposition).c_str());
    int *character =(int*)malloc(sizeof(int));
    json_object_object_add(objeto,"Position",str1);
    return objeto;
}
