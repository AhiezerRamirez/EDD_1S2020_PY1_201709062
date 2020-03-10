#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include <string>
#include <iostream>

class NodoListaSimple
{
public:
    int x, y;
    std::string tipo;
    NodoListaSimple *siguiente;
    NodoListaSimple(std::string tipo,int x, int y) {
        this->tipo=tipo;
        this->x=x;
        this->y=y;
        this->siguiente=NULL;
    }
};

class ListaSimple
{
public:
    NodoListaSimple *primero;
    ListaSimple();
    void insertar(std::string tipo, int x, int y);
    NodoListaSimple* buscar(int x, int y);
    void toString();
};

#endif // LISTASIMPLE_H
