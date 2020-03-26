#ifndef TABLERO_H
#define TABLERO_H
#include "core.h"
#include <vector>

class nodoJugada
{
public:
    std::string letra;
    int x,y,pos;
    nodoJugada *siguiente;
    nodoJugada(int pos,int x, int y) {
        this->pos=pos;
        this->x=x;
        this->y=y;
    }
};

class listaJugadas
{
public:
    nodoJugada *primero;
    listaJugadas() {primero=NULL;}
    void ingresar(int pos, int x,int y){
        nodoJugada *n=new nodoJugada(pos,x,y);
        if(primero==NULL)
            primero=n;
        else{
            //Hay que arreglar para que sea ordenada
            n->siguiente=primero;
            primero=n;
        }
    }
};

class Tablero
{
public:
    Core *core;
    Tablero(Core *core);
    void escojerJugadores();
    void dibujaTablero();
    void colocarLetras(listaJugadas *v,int orientacion);
    bool verificarIndices(std::vector<int> v,listaJugadas *listJ);
    std::vector<int> separar(std::string letras);
};

#endif // TABLERO_H
