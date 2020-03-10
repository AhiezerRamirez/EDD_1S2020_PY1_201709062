#ifndef COLA_H
#define COLA_H
#include <string>

class NodoCola
{
public:
    int puntos;
    std::string letra;
    NodoCola *siguiente;
    NodoCola(std::string letra, int puntos) {
        this->letra=letra;
        this->puntos=puntos;
        this->siguiente=NULL;
    }
};

class Cola
{
public:
    NodoCola* primero, *ultimo;
    Cola();
    void encolar(std::string letra, int puntos);
    NodoCola* desencolar();
};

#endif // COLA_H
