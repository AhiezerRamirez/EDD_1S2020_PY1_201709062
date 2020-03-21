#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include <string>

class NodoFicha
{
public:
    NodoFicha *siguiente,*atras;
    std::string letra;
    int puntos;
    NodoFicha(std::string letra, int puntos) {
        this->letra=letra;
        this->puntos=puntos;
        this->siguiente=NULL;
        this->atras=NULL;
    }
};

class ListaDoble
{
public:
    int size;
    NodoFicha *primero, *ultimo;
    ListaDoble();
    void insertar(std::string letra, int puntos);
    NodoFicha* borrar(int pos);
    std::string toString();
    void graficar(std::string usuario);
};

#endif // LISTADOBLE_H
