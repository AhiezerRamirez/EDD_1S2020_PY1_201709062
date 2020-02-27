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
    void borrar(int x, int y);
    NodoMatriz *buscarxy(int x, int y);
    NodoMatriz *buscar(std::string dato);
};

#endif // LISTARHORIZONTAL_H
