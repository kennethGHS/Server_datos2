//
// Created by kenneth on 25/02/18.
//

#ifndef ESTRUCTURES_SIMPLE_NODE_H
#define ESTRUCTURES_SIMPLE_NODE_H

template <typename T>
class Simple_Node {
public:
    int position;
    T valor;
    Simple_Node<T>* next = nullptr;
    ~Simple_Node(){

    };
    void DestroyList(){
        

    }
    Simple_Node(T);
    Simple_Node(T valor, int position);
    void eliminateNodeValue(){
        if(valor!= nullptr){
        delete valor;}

    }

};
//QApplication app(x,y);
//QWidget window;
//ventana_princ=&window;
//window.resize(800,800);
//window.setWindowTitle("Structures Representated");
//window.show();
//addButtons();
//app.exec();



#endif //ESTRUCTURES_SIMPLE_NODE_H
