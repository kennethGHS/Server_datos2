//
// Created by kenneth on 25/03/18.
//

#ifndef SERVER_D2_JSON_FACTORY_H
#define SERVER_D2_JSON_FACTORY_H


#include <json-c/json_object.h>
#include "Allocator/Maper.h"

class Json_Factory {
public:
    static Maper* map;
static json_object* createJson(json_object* objeto);
    static json_object* createIntJson(json_object* objeto);
    static json_object* createCharJson(json_object* objeto);
    static json_object* createLongJson(json_object* objeto);
    static json_object* createDoubleJson(json_object* objeto);
    static json_object* createReferenceJson(json_object* objeto);
    static json_object* createFloatJson(json_object* objeto);
    static json_object* createStructJson(json_object* objeto);

};


#endif //SERVER_D2_JSON_FACTORY_H
