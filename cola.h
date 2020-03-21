#ifndef COLA_H
#define COLA_H
#include <string>

struct Ficha
{
public:
    std::string letra;
    int puntos;
    int cantfichas;
    Ficha(std::string letra, int puntos, int cantfichas) {
        this->letra=letra;
        this->puntos=puntos;
        this->cantfichas=cantfichas;
    }
};

class NodoCola
{
public:
    int puntos;
    std::string letra;
    NodoCola *siguiente;
    Ficha *ficha;
    NodoCola(std::string letra, int puntos) {
        this->letra=letra;
        this->puntos=puntos;
        this->siguiente=NULL;
    }
    NodoCola(Ficha *fic){
        this->ficha=fic;
    }
};

class Cola
{  
public:
    NodoCola* primero, *ultimo;
    Cola();
    void encolar(std::string letra, int puntos);
    void meterradom(std::string letra,int puntos, int pos);
    void encolar(std::string letra, int puntos, int cantidad);
    NodoCola* desencolar();
    void imprimir();
    std::string toString();
    int size;
};

#endif // COLA_H
