#ifndef LISTAVERTICAL_H
#define LISTAVERTICAL_H
#include "nodomatriz.h"

class ListaVertical
{
public:
    NodoMatriz *primero;
    NodoMatriz *ultimo;
    int size;
    ListaVertical();
    void insertar(NodoMatriz *node,int y);
    NodoMatriz* buscar(std::string dato);
};

#endif // LISTAVERTICAL_H
