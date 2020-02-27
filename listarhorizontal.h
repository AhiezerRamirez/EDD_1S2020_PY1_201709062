#ifndef LISTARHORIZONTAL_H
#define LISTARHORIZONTAL_H
#include <iostream>
#include "nodomatriz.h"

//template<typename M>
class ListarHorizontal
{
public:
    NodoMatriz *primero,*ultimo;
    int size;
    ListarHorizontal();
    void insertar(NodoMatriz *node,int x);
    NodoMatriz *buscar(std::string dato);
};

#endif // LISTARHORIZONTAL_H
