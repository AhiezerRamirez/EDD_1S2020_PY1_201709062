#ifndef LISTASIMPLEORDENADA_H
#define LISTASIMPLEORDENADA_H
#include <string>

class NodoPunteo
{
public:
    int punteo;
    std::string nombre;
    NodoPunteo *siguiente;
    NodoPunteo(std::string nombre, int punteo) {
        this->nombre=nombre;
        this->punteo=punteo;
        this->siguiente=NULL;
    }
};

class ListaSimpleOrdenada
{
public:
    NodoPunteo *primero, *ultimo;
    ListaSimpleOrdenada();
    void insertar(std::string nombre, int punteo);
    std::string toString();
    void graficar();
    std::string toString2();
    void graficar2();
};

#endif // LISTASIMPLEORDENADA_H
