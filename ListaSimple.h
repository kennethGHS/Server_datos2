//
// Created by dario1227 on 11/04/18.
//

#ifndef SERVER_D2_LISTASIMPLE_H
#define SERVER_D2_LISTASIMPLE_H

class NodoS;
class ListaSimple {
public:
    ListaSimple();
    NodoS* head= nullptr;
    int large=0;
    void addL(NodoS* x);
    void delF();
    void delL();
    void del(int pos);
};




#endif //SERVER_D2_LISTASIMPLE_H
