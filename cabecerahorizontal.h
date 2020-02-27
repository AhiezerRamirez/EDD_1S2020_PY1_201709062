#ifndef CABECERAHORIZONTAL_H
#define CABECERAHORIZONTAL_H
#include <iostream>
#include "listavertical.h"

//template<typename T>
class NodoH
{
public:
    std::string dato;
    std::string Gnombre;
    int x;
    NodoH *adelante;
    NodoH *atras;
    ListaVertical *listavertica;
    NodoH(std::string dato,int x) {
        this->adelante=NULL;
        this->atras=NULL;
        this->dato=dato;
        this->x=x;
        this->Gnombre="CH"+std::to_string(x);
        listavertica=new ListaVertical();
        //this->listavertica=new ListaVertical();
    }
};

//template<typename T>
class CabeceraHorizontal
{
public:
    NodoH *primero;
    NodoH *ultimo;
    int size;
    CabeceraHorizontal();
    NodoH* insertarEn(std::string dato,int x);
    void borrar(std::string dato);
    NodoH*buscar(std::string dato);

};

#endif // CABECERAHORIZONTAL_H
