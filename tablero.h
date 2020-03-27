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
        if(primero==NULL){
            primero=n;
        }
        else{
            //Hay que arreglar para que sea ordenada
            n->siguiente=primero;
            primero=n;
        }
    }
    int findLowestX(){
        nodoJugada *temp=this->primero;
        int lowest=this->primero->x;
        while (temp!=NULL) {
            if(temp->x < lowest){
                lowest=temp->x;
            }
            temp=temp->siguiente;
        }
        return lowest;
    }
    int findHightestX(){
        nodoJugada *temp=this->primero;
        int hightest=this->primero->x;
        while (temp!=NULL) {
            if(temp->x > hightest){
                hightest=temp->x;
            }
            temp=temp->siguiente;
        }
        return hightest;
    }
    int findLowestY(){
        nodoJugada *temp=this->primero;
        int lowest=this->primero->y;
        while (temp!=NULL) {
            if(temp->y < lowest){
                lowest=temp->y;
            }
            temp=temp->siguiente;
        }
        return lowest;
    }
    int findHightestY(){
        nodoJugada *temp=this->primero;
        int hightest=this->primero->y;
        while (temp!=NULL) {
            if(temp->y > hightest){
                hightest=temp->y;
            }
            temp=temp->siguiente;
        }
        return hightest;
    }
    void ordenar(){}
    void swapped(){}//Falta ordenar la lista
};

class Tablero
{
public:
    Core *core;
    Tablero(Core *core);
    void escojerJugadores();
    void dibujaTablero();
    void colocarLetras(listaJugadas *v,int orientacion);
    bool verificarIndices(std::vector<std::vector<int>> v,listaJugadas *listJ);
    std::vector<int> separar(std::string letras);
};

#endif // TABLERO_H
