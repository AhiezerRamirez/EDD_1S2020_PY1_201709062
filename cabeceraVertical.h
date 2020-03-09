#ifndef CABEZERAHORIZONTAL_H
#define CABEZERAHORIZONTAL_H
#include<iostream>
#include "listarhorizontal.h"

//template<typename T>
class Nodo
{
public:
    std::string dato;
    std::string Gnombre;
    int y;
    Nodo *arriba;
    Nodo *abajo;
    ListarHorizontal *listahorizonta;
    Nodo(std::string dato,int y) {
        this->dato=dato;
        this->y=y;
        this->arriba=NULL;
        this->abajo=NULL;
        this->Gnombre="CV"+std::to_string(y);
        this->listahorizonta=new ListarHorizontal();
    }
};

class CabeceraVertica
{
private:
    void insertarArriba(std::string dato,int y);
    void insertarAbajo(std::string dato,int y);
public:
    Nodo *primero;
    Nodo *ultimo;
    int size;
    CabeceraVertica();
    Nodo* insertarEn(std::string dato,int pos);
    void borrarEn(int y);
    Nodo* buscary(int y);
    Nodo* buscar(std::string dato);

};

#endif // CABEZERAHORIZONTAL_H
