#ifndef TABLERO_H
#define TABLERO_H
#include "core.h"
#include <vector>

class nodoJugada
{
public:
    std::string letra;
    int x,y,pos,puntos;
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
    nodoJugada *primero,*ultimo;
    listaJugadas() {primero=ultimo=NULL;}
    void ingresar(int pos, int x,int y){
        nodoJugada *n=new nodoJugada(pos,x,y);
        if(primero==NULL){
            primero=n;
            ultimo=n;
        }else if(pos==primero->pos||pos==ultimo->pos);
        else{
            //Hay que arreglar para que sea ordenada
            if(pos<ultimo->pos){
                ultimo->siguiente=n;
                ultimo=n;
            }else if(pos>primero->pos){
                nodoJugada *temp=primero;
                primero=n;
                primero->siguiente=temp;
            }else{
                nodoJugada *aux=primero;
                nodoJugada *ant;
                while (aux->pos>pos) {
                    ant=aux;
                    aux=aux->siguiente;
                }
                ant->siguiente=n;
                n->siguiente=aux;
            }
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

    std::string mostrar(){
        std::string cadena="";
        nodoJugada *temp=primero;
        while (temp!=NULL) {
            cadena+=std::to_string(temp->pos);
            temp=temp->siguiente;
        }
        return cadena;
    }
};

class Tablero
{
public:
    Core *core;
    Tablero(Core *core);
    void escojerJugadores();
    void dibujaTablero();
    bool colocarLetras(listaJugadas *v,int orientacion,NodoJugadoresLinea *actualPlayer);
    bool verificarIndices(std::vector<std::vector<int>> v,listaJugadas *listJ);
    std::vector<int> separar(std::string letras);
    void cambiarFichas(NodoJugadoresLinea *jugador);
    void mostrarReportes();
};

#endif // TABLERO_H
