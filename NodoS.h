//
// Created by dario1227 on 11/04/18.
//

#ifndef SERVER_D2_NODOS_H
#define SERVER_D2_NODOS_H


class NodoS {
public:
    NodoS();
    void (*Function)();
    NodoS* next= nullptr;
};

};


#endif //SERVER_D2_NODOS_H
