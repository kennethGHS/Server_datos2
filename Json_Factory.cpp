//
// Created by kenneth on 25/03/18.
//
#include <iostream>
#include "Json_Factory.h"
#include "Allocator/static_reserver.h"
#include <QString>
 Maper* Json_Factory::map = new Maper(100000);
/**
 * crea un json
 * @param objeto
 * @return
 */
json_object* Json_Factory::createJson(json_object *objeto) {
    std::cout<<json_object_to_json_string(json_object_object_get(objeto,"type"))<<std::endl;
    char character = json_object_to_json_string(json_object_object_get(objeto,"type"))[1];
    std::cout<<character<<"KAJFAKJFKAJFGKAJGFKAJGF"<<std::endl;
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
    if(character=='b'){
        std::cout<<"Maping type Struct"<<"\n";
        return createCharJson(objeto);
    }
    return nullptr;
}

/**
 * creacion de referencias
 * @param objeto
 * @return
 */
json_object* Json_Factory::createCharJson(json_object *objeto) {
     json_object* str1 = json_object_new_string(std::to_string(map->freeposition).c_str());

    json_object_object_add(objeto,"Position",str1);
    QString * value =parse_whitout_comillas((char*)json_object_to_json_string(json_object_object_get(objeto,"value")));
    bool y = false;
    QChar valor =(*value)[1];
    if(value->contains("true")||value->contains("false")){
        if(value->contains("true")){
            static_reserver::var->add_variable('1');
        }
        else{
            static_reserver::var->add_variable('0');
        }
    }
    else{
        static_reserver::var->add_variable(valor.toLatin1());
    }

    return objeto;

}
json_object* Json_Factory::createDoubleJson(json_object *objeto) {
    struct json_object* str1 = json_object_new_string(std::to_string(map->freeposition).c_str());
    double *character =(double*)malloc(sizeof(double));

    json_object_object_add(objeto,"Position",str1);
    QString * value =parse_whitout_comillas((char*)json_object_to_json_string(json_object_object_get(objeto,"value")));
    bool y = false;
    double valor =value->toDouble(&y);
    if(y== false){
        static_reserver::var->add_variable(2323.2323);
    }
    else{
        static_reserver::var->add_variable(valor);
    }
    return objeto;
}
json_object* Json_Factory::createFloatJson(json_object *objeto) {
    struct json_object* str1 = json_object_new_string(std::to_string(static_reserver::var->freeposition).c_str());

    json_object_object_add(objeto,"Position",str1);
    QString * value =parse_whitout_comillas((char*)json_object_to_json_string(json_object_object_get(objeto,"value")));
    bool y = false;
    float valor =value->toFloat(&y);
    if(y== false){
        static_reserver::var->add_variable(0.1);
    }
    else{
        static_reserver::var->add_variable(valor);
    }
    return objeto;
}
json_object* Json_Factory::createIntJson(json_object *objeto) {

    struct json_object* str1 = json_object_new_string(std::to_string(static_reserver::var->freeposition).c_str());
    json_object_object_add(objeto,"Position",str1);
    QString * value =parse_whitout_comillas((char*)json_object_to_json_string(json_object_object_get(objeto,"value")));
    bool y = false;
    int valor =value->toInt(&y);
    if(y== false){
        static_reserver::var->add_variable(12);
    }
    else{
        static_reserver::var->add_variable(valor);
    }
    return objeto;
}
json_object* Json_Factory::createLongJson(json_object *objeto) {

    struct json_object* str1 = json_object_new_string(std::to_string(static_reserver::var->freeposition).c_str());
    json_object_object_add(objeto,"Position",str1);
    QString * value =parse_whitout_comillas((char*)json_object_to_json_string(json_object_object_get(objeto,"value")));
    bool y = false;
    long valor =value->toLong(&y);
    long c =232323;
    if(y== false){
        static_reserver::var->add_variable(c);
    }
    else{
        static_reserver::var->add_variable(valor);
    }
    return objeto;
}
json_object* Json_Factory::createReferenceJson(json_object *objeto) {
    struct json_object* str1 = json_object_new_string(std::to_string(static_reserver::var->freeposition).c_str());
    json_object_object_add(objeto,"Position",str1);
    QString * value =parse_whitout_comillas((char*)json_object_to_json_string(json_object_object_get(objeto,"value")));
    bool y = false;
    int valor =value->toInt(&y);
    if(y== false){
        static_reserver::var->add_variable(2);
    }
    else{
        static_reserver::var->add_variable(valor);
    }
    return objeto;
}
json_object* Json_Factory::createStructJson(json_object *objeto) {
    QString * value =parse_whitout_comillas((char*)json_object_to_json_string(json_object_object_get(objeto,"value")));

    struct json_object* str1 = json_object_new_string(std::to_string(map->freeposition).c_str());
    int *character =(int*)malloc(sizeof(int));
    json_object_object_add(objeto,"Position",str1);
    return objeto;
}
QString* Json_Factory::parse_whitout_comillas(char* string) {
    QString var = QString(string);
    QString *var_toreturn=new QString();
    int index = 0;
    while(index<var.size()){
        if(var[index]!='"'){
        var_toreturn->append(var[index]);
        }
        index++;
    }
    return var_toreturn;
}
bool Json_Factory::parse_bool(char *string) {
    QString var = QString(string);
    return var.contains("true");
}