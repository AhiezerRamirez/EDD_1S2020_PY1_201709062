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
            core->matriz->insertar("4",4,"5",5,"H","triple",2);
            core->matriz->insertar("4",4,"6",6,"O","normal",3);
            core->matriz->insertar("4",4,"7",7,"L","normal",9);
            core->matriz->insertar("4",4,"8",8,"A","doble",2);
            core->matriz->insertar("3",3,"8",8,"C","normal",1);
            core->matriz->insertar("5",5,"8",8,"S","normal",8);
            core->matriz->insertar("6",6,"8",8,"A","normal",2);
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
        std::cout<<"*  -Finalizar ESC         -cambio F1		-tablero F3  *"<<std::endl;
        std::cout<<"**********************************************************"<<std::endl;
        std::cout<<core->onlinePlayers->mostrarJugadores()<<std::endl;
        std::cout<<"        Turno de: "+actualJugador->jugador->dato+"\n"<<std::endl;
        std::cout<<core->matriz->mostrarMatriz()<<std::endl;
        std::cout<<actualJugador->jugador->dato+" ingrese el numero de letras a utilizar ->";
        std::vector<std::vector<int>> entradas;
        listaJugadas *listJ=new listaJugadas();
        std::string numeroLetras;
        std::cin>>numeroLetras;
        std::cout<<"Ingrese La posicion de su letra, posicion x y posicion y respectivamente."<<std::endl;
        std::cout<<"Divida cada dato con un \";\""<<std::endl;
        for (int i = 1; i <= stoi(numeroLetras); ++i) {
            std::string letras;
            std::cin>>letras;
            entradas.push_back(separar(letras));
        }

        if(verificarIndices(entradas,listJ)){
            std::cout<<"Orientacion de la palabra 0: para horizontal 1: vertical"<<std::endl;
            std::string orientacion;
            std::cin>>orientacion;
            if(colocarLetras(listJ,stoi(orientacion),actualJugador)){
                std::cout<<"Jugada acceptada. \nBien hecho"<<actualJugador->jugador->dato<<" tu puntedo ahora es: "<<actualJugador->jugador->puntos<<std::endl;
            }else {
                std::cout<<"La palabra que acabas de ingresar, no existe en el diccionario"<<std::endl;
                std::cout<<"        ***Pierde su turno***"<<std::endl;
            }
        }else{
            std::cout<<"Alguna posicion dada es mayor que el tamano de la matriz"<<std::endl;
            std::cout<<"        ***Pierde su turno***"<<std::endl;
        }
        actualJugador=actualJugador->siguiente;
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
bool Tablero::verificarIndices(std::vector<std::vector<int>> v,listaJugadas *listJ){

    for (unsigned int var = 0; var < v.size(); ++var) {
        std::vector<int> v1=v.at(var);
        listJ->ingresar(v1.at(0),v1.at(1),v1.at(2));

    }

    nodoJugada *temp=listJ->primero;
    bool flage=true;
    while (temp!=NULL) {
        if(temp->x>core->matriz->size || temp->y > core->matriz->size)
            flage=false;
        temp=temp->siguiente;
    }
    return flage;
}
bool Tablero::colocarLetras(listaJugadas *v,int orientacion,NodoJugadoresLinea *actualPlayer){
    //std::cout<<v->mostrar()<<std::endl;
    nodoJugada *temp=v->primero;
    while (temp!=NULL) {
        NodoListaSimple *aux=core->casillasEspeciales->buscar(temp->x,temp->y);
        NodoFicha *ficha=actualPlayer->jugador->fichas->getFichas(temp->pos);       //Puede cambiarse para que sea temp.letra o hacer un  nodoFicha
        temp->letra=ficha->letra;
        temp->puntos=ficha->puntos;
        core->matriz->insertar(std::to_string(temp->x),temp->x,std::to_string(temp->y),temp->y,ficha->letra,aux->tipo,ficha->puntos);
        temp=temp->siguiente;
    }

    if(orientacion==0){
        int inicial=v->findLowestX();
        int fin=v->findHightestX();
        std::string validacion="";
        int punteo=0;
        for (int var = inicial; var <= fin; ++var) {
            validacion+=core->matriz->buscar(var,v->primero->y);
            punteo+=core->matriz->sumar(var,v->primero->y);
        }
        bool contiene=core->diccionario->contains(validacion);
        if(contiene){
            actualPlayer->jugador->puntos+=punteo;
            return true;
        }else{
            nodoJugada *temp=v->primero;
            while (temp!=NULL) {
                core->matriz->borrar(std::to_string(temp->x),temp->x,std::to_string(temp->y),temp->y);
                temp=temp->siguiente;
            }

            return false;
        }
        //std::cout<<validacion<<" Esto es lo que se acaba de meter a la matrix Y este es el punteo"<<punteo<<std::endl;
    }else if(orientacion==1){
        int inicial=v->findLowestY();
        int fin=v->findHightestY();
        std::string validacion="";
        int punteo=0;
        for (int var = inicial; var < fin; ++var) {
            validacion+=core->matriz->buscar(v->primero->x,var);
            punteo+=core->matriz->sumar(v->primero->x,var);
        }
        bool contiene=core->diccionario->contains(validacion);
        if(contiene){
            actualPlayer->jugador->puntos+=punteo;
            return true;
        }else {
            nodoJugada *temp=v->primero;
            while (temp!=NULL) {
                core->matriz->borrar(std::to_string(temp->x),temp->x,std::to_string(temp->y),temp->y);
                temp=temp->siguiente;
            }
            return false;
        }
    }else {
        std::cout<<"Orientacion no acceptada. \n        ***Pierde su turno***"<<std::endl;
        return false;
    }
    //
}
