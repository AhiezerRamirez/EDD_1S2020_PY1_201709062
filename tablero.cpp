#include "tablero.h"
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

Tablero::Tablero(Core *core)
{
    this->core=core;
}

void Tablero::escojerJugadores(){
    //while (true) {
        std::cout<<"Escoja al jugador 1"<<std::endl;
        std::cout<<"Escriba el nombre dell jugador 1"<<std::endl;
        std::string player="Silvia";
        //std::cin>>player;
        NodoArbol *jugador1=core->arbol->get(player);
        std::cout<<"Escoja al jugador 2"<<std::endl;
        std::cout<<"Escriba el nombre dell jugador 2"<<std::endl;
        //std::cin>>player;
        NodoArbol *jugador2=core->arbol->get("Mario");
        if(jugador1!=NULL && jugador2!=NULL){
            for (int var = 0; var < 7; ++var) {
                NodoCola *ficha1= core->Fichas->desencolar();
                //std::cout<<ficha1->letra+" " +std::to_string(ficha1->puntos)<<std::endl;
                jugador1->fichas->insertar(ficha1->letra,ficha1->puntos);

            }
            core->onlinePlayers->ingrear(jugador1);
            for (int var = 0; var < 7; ++var) {
                NodoCola *ficha1= core->Fichas->desencolar();
                //std::cout<<ficha1->letra+" "+ std::to_string(ficha1->puntos)<<std::endl;
                jugador2->fichas->insertar(ficha1->letra,ficha1->puntos);

            }
            core->onlinePlayers->ingrear(jugador2);
            core->matriz->insertar("4",4,"5",5,"H","triple");
            core->matriz->insertar("4",4,"6",6,"O","normal");
            core->matriz->insertar("4",4,"7",7,"L","normal");
            core->matriz->insertar("4",4,"8",8,"A","doble");
            core->matriz->insertar("3",3,"8",8,"C","normal");
            core->matriz->insertar("5",5,"8",8,"S","normal");
            core->matriz->insertar("6",6,"8",8,"A","normal");
            //break;
        }else{
            std::cout<<"Jugadores incorrectos"<<std::endl;
            //break;
        }
    //}
}

void Tablero::dibujaTablero(){
    NodoJugadoresLinea *actualJugador=this->core->onlinePlayers->inicio;
    while (true) {
        std::cout<<"**********************************************************"<<std::endl;
        std::cout<<"*  -Finalizar ESC  -cambio F1		-tablero F3  *"<<std::endl;
        std::cout<<"**********************************************************"<<std::endl;
        std::cout<<core->onlinePlayers->mostrarJugadores()<<std::endl;
        std::cout<<"        Turno de: "+actualJugador->jugador->dato+"\n"<<std::endl;
        std::cout<<core->matriz->mostrarMatriz()<<std::endl;
        std::cout<<actualJugador->jugador->dato+" ingrese el numero de letras a utilizar ->";
        std::vector<int> entradas;
        listaJugadas *listJ=new listaJugadas();
        std::string numeroLetras;
        std::cin>>numeroLetras;
        std::cout<<"Ingrese La posicion de su letra, posicion x y posicion y respectivamente."<<std::endl;
        std::cout<<"Divida cada dato con un \";\""<<std::endl;
        for (int i = 0; i <= stoi(numeroLetras); ++i) {
            std::string letras;
            std::cin>>letras;
            entradas=separar(letras);
        }
        bool flageSize=verificarIndices(entradas,listJ);
        if(flageSize){
            std::cout<<"Orientacion de la palabra 0: para horizontal 1: vertical"<<std::endl;
            std::string orientacion;
            std::cin>>orientacion;
        }
    }
}
std::vector<int> Tablero::separar(std::string letras){
    std::replace(letras.begin(),letras.end(),';',' ');
    std::vector<int> v;
    std::stringstream ss(letras);
    int temp;
    while (ss>>temp) {
        v.push_back(temp);
    }
    return v;
}
bool Tablero::verificarIndices(std::vector<int> v,listaJugadas *listJ){

    listJ->ingresar(v.at(0),v.at(1),v.at(2));
    nodoJugada *temp=listJ->primero;
    bool flage=true;
    while (temp!=NULL) {
        if(temp->x>core->matriz->size || temp->y > core->matriz->size)
            flage=false;
    }
    return flage;
}
void Tablero::colocarLetras(listaJugadas *v,int orientacion){
    //Hay que arreglar la lista ordenada;
}
