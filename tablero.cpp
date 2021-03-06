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
        std::string player;
        std::cin>>player;
        NodoArbol *jugador1=core->arbol->get(player);
        std::cout<<"Escoja al jugador 2"<<std::endl;
        std::cout<<"Escriba el nombre dell jugador 2"<<std::endl;
        std::cin>>player;
        NodoArbol *jugador2=core->arbol->get(player);
        if(jugador1!=NULL && jugador2!=NULL){
            for (int var = 0; var < 7; ++var) {
                NodoCola *ficha1= core->Fichas->desencolar();
                if(ficha1!=NULL)
                    jugador1->fichas->insertar(ficha1->letra,ficha1->puntos);
                else
                    std::cout<<"Ya no hay mas fichas"<<std::endl;

            }
            core->onlinePlayers->ingrear(jugador1);
            for (int var = 0; var < 7; ++var) {
                NodoCola *ficha1= core->Fichas->desencolar();
                //std::cout<<ficha1->letra+" "+ std::to_string(ficha1->puntos)<<std::endl;
                if(ficha1!=NULL)
                    jugador2->fichas->insertar(ficha1->letra,ficha1->puntos);
                else
                    std::cout<<"Ya no hay mas fichas"<<std::endl;

            }
            core->onlinePlayers->ingrear(jugador2);
            /*core->matriz->insertar("4",4,"5",5,"H","triple",2);
            core->matriz->insertar("4",4,"6",6,"O","normal",3);
            core->matriz->insertar("4",4,"7",7,"L","normal",9);
            core->matriz->insertar("4",4,"8",8,"A","doble",2);
            core->matriz->insertar("3",3,"8",8,"C","normal",1);
            core->matriz->insertar("5",5,"8",8,"S","normal",8);
            core->matriz->insertar("6",6,"8",8,"A","normal",2);
            //break;*/
        }else{
            std::cout<<"Jugadores incorrectos"<<std::endl;
            //break;
        }
    //}
}

void Tablero::prepararTablero(int *tama){
    core->crearMatriz(*tama);
    std::cout<<"El tamano de la matriz es: "<<core->matriz->size<<std::endl;
    NodoListaSimple *temp=core->casillasEspeciales->primero;
    while (temp!=NULL) {
        if(temp->tipo=="doble")
            core->matriz->insertar(std::to_string(temp->x),temp->x,std::to_string(temp->y),temp->y,"2",temp->tipo,0);
        else if(temp->tipo=="triple")
            core->matriz->insertar(std::to_string(temp->x),temp->x,std::to_string(temp->y),temp->y,"3",temp->tipo,0);
        temp=temp->siguiente;
    }
}

void Tablero::dibujaTablero(){
    NodoJugadoresLinea *actualJugador=this->core->onlinePlayers->inicio;
    //system("clear");
    while (true) {
        std::cout<<"*****************************************************************"<<std::endl;
        std::cout<<"* -Finalizar: salir  -Cambio: cambiar   -tablero reportes       *"<<std::endl;
        std::cout<<"*****************************************************************"<<std::endl;
        std::cout<<core->onlinePlayers->mostrarJugadores()<<std::endl;
        std::cout<<"        Turno de: "+actualJugador->jugador->dato+"\n"<<std::endl;
        std::cout<<"Casillas especiales: "<<std::endl;
        core->casillasEspeciales->toString();
        std::cout<<"Diccionario: "<<std::endl;
        std::cout<<core->diccionario->mostrarDiccionario();
        //std::cout<<core->matriz->mostrarMatriz()<<std::endl;
        std::cout<<actualJugador->jugador->dato+" ingrese el numero de letras a utilizar ->";
        std::vector<std::vector<int>> entradas;
        listaJugadas *listJ=new listaJugadas();
        std::string numeroLetras;
        std::cin>>numeroLetras;
        if(numeroLetras.length()==1){
            //const char*auxnumeroletra=numeroLetras.c_str();
            if(isdigit(numeroLetras[0])){
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
            }else{
                std::cout<<"Solamente se acceptan numeros"<<std::endl;
                std::cout<<"        ***Pierde su turno***"<<std::endl;
            }
            actualJugador=actualJugador->siguiente;
        }else{
            if(numeroLetras=="salir"){
                core->onlinePlayers->inicio->jugador->punteo->insertar(core->onlinePlayers->inicio->jugador->dato,core->onlinePlayers->inicio->jugador->puntos);
                core->onlinePlayers->fin->jugador->punteo->insertar(core->onlinePlayers->fin->jugador->dato,core->onlinePlayers->fin->jugador->puntos);
                std::cout<<core->onlinePlayers->inicio->jugador->dato<<" : "<<core->onlinePlayers->inicio->jugador->puntos<<std::endl;
                std::cout<<core->onlinePlayers->fin->jugador->dato<<" : "<<core->onlinePlayers->fin->jugador->puntos<<std::endl;
                core->scoreboard->insertar(core->onlinePlayers->inicio->jugador->dato,core->onlinePlayers->inicio->jugador->puntos);
                core->scoreboard->insertar(core->onlinePlayers->fin->jugador->dato,core->onlinePlayers->fin->jugador->puntos);
                core->onlinePlayers->vaciar();
                //std::string algo;
                //std::cin>>algo;
                break;
            }else if (numeroLetras=="cambiar") {
                cambiarFichas(actualJugador);
                actualJugador=actualJugador->siguiente;
            }else if (numeroLetras=="reportes") {
                mostrarReportes();
            }else {
                std::cout<<"Opcion no reconocida"<<std::endl;
            }
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
        NodoFicha *ficha=actualPlayer->jugador->fichas->getFichas(temp->pos);
        if(aux->tipo=="normal"){
            temp->letra=ficha->letra;
            temp->puntos=ficha->puntos;
            core->matriz->insertar(std::to_string(temp->x),temp->x,std::to_string(temp->y),temp->y,ficha->letra,aux->tipo,ficha->puntos);
        }else{
            core->matriz->modificar(ficha->letra,ficha->puntos,temp->x,temp->y);
        }
        temp=temp->siguiente;
    }

    if(orientacion==0){
        std::cout<<"Ingrese la coordenada en x de inicio de su palabra"<<std::endl;
        std::string ini;
        std::cin>>ini;
        std::cout<<"Ingrese la coordenada en x del fin de su palabra"<<std::endl;
        std::string finn;
        std::cin>>finn;
        int inicial=stoi(ini);
        int fin=stoi(finn);
        std::string validacion="";
        int punteo=0;
        for (int var = inicial; var <= fin; ++var) {
            validacion+=core->matriz->buscar(var,v->primero->y);
            punteo+=core->matriz->sumar(var,v->primero->y);
        }
        std::cout<<validacion<<" esto es lo que deberia de validar"<<std::endl;
        bool contiene=core->diccionario->contains(validacion);
        if(contiene){
            actualPlayer->jugador->puntos+=punteo;
            nodoJugada *temp=v->primero;
            while (temp!=NULL) {
                NodoCola *tempficha=core->Fichas->desencolar();
                actualPlayer->jugador->fichas->insertar(tempficha->letra,tempficha->puntos);
                temp=temp->siguiente;
            }
            return true;
        }else{
            nodoJugada *temp=v->primero;
            while (temp!=NULL) {
                NodoListaSimple *aux=core->casillasEspeciales->buscar(temp->x,temp->y);
                if(aux->tipo=="normal")
                    core->matriz->borrar(std::to_string(temp->x),temp->x,std::to_string(temp->y),temp->y);
                else if(aux->tipo=="doble")
                    core->matriz->modificar("x2",0,temp->x,temp->y);
                else
                    core->matriz->modificar("x3",0,temp->x,temp->y);
                actualPlayer->jugador->fichas->insertar(temp->letra,temp->puntos);
                temp=temp->siguiente;
            }

            return false;
        }
        //std::cout<<validacion<<" Esto es lo que se acaba de meter a la matrix Y este es el punteo"<<punteo<<std::endl;
    }else if(orientacion==1){
        std::cout<<"Ingrese la coordenada en y de inicio de su palabra"<<std::endl;
        std::string ini;
        std::cin>>ini;
        std::cout<<"Ingrese la coordenada en y del fin de su palabra"<<std::endl;
        std::string finn;
        std::cin>>finn;
        int inicial=stoi(ini);
        int fin=stoi(finn);
        std::string validacion="";
        int punteo=0;
        for (int var = inicial; var <=fin; ++var) {
            validacion+=core->matriz->buscar(v->primero->x,var);
            punteo+=core->matriz->sumar(v->primero->x,var);
        }
        std::cout<<validacion<<" esto es lo que deberia de validar"<<std::endl;
        bool contiene=core->diccionario->contains(validacion);
        if(contiene){
            actualPlayer->jugador->puntos+=punteo;
            nodoJugada *temp=v->primero;
            while (temp!=NULL) {
                NodoCola *tempficha=core->Fichas->desencolar();
                actualPlayer->jugador->fichas->insertar(tempficha->letra,tempficha->puntos);
                temp=temp->siguiente;
            }
            return true;
        }else {
            nodoJugada *temp=v->primero;
            while (temp!=NULL) {
                NodoListaSimple *aux=core->casillasEspeciales->buscar(temp->x,temp->y);
                if(aux->tipo=="normal")
                    core->matriz->borrar(std::to_string(temp->x),temp->x,std::to_string(temp->y),temp->y);
                else if(aux->tipo=="doble")
                    core->matriz->modificar("x2",0,temp->x,temp->y);
                else
                    core->matriz->modificar("x3",0,temp->x,temp->y);
                actualPlayer->jugador->fichas->insertar(temp->letra,temp->puntos);
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

void Tablero::cambiarFichas(NodoJugadoresLinea *jugador){
    while (true) {
        std::cout<<"Ingrese el numero de fichas que va a cambiar"<<std::endl;
        std::string cantfichas;
        std::cin>>cantfichas;
        int auxcantefichas=stoi(cantfichas);
        if(auxcantefichas < 1 || auxcantefichas > jugador->jugador->fichas->size){
            std::cout<<"Numero incorrecto, solo puede cambiar de una a "<<jugador->jugador->fichas->size<<std::endl;
            std::cout<<"        ***Pierde su turno***"<<std::endl;
        }else{
            std::cout<<"Ingrese el (los) numero(s) de posicion de ficha(s) que va a cambiar"<<std::endl;
            for (int var = 0; var < auxcantefichas; ++var) {
                std::string pos;
                std::cin>>pos;
                int auxpos=stoi(pos);
                NodoFicha *auxficha=jugador->jugador->fichas->getFichas(auxpos);
                core->Fichas->encolar(auxficha->letra,auxficha->puntos);
                NodoCola *ficha2=core->Fichas->desencolar();
                jugador->jugador->fichas->insertar(ficha2->letra,ficha2->puntos);
                std::cout<<"Fichas cambiadas con exito"<<std::endl;
                //break;
            }
            break;
        }
    }
}

void Tablero::mostrarReportes(){
    bool continuar=true;
    while (continuar) {
        std::cout<<"1)Diccionario\n2)Fichas\n3)Arbol de Usuarios\n4)Preorden\n5)Inorden\n6)Postorden\n7)Punteo por Usuario\n8)Punteo General\n9)Tablero\n10)Ficha de jugadores\n11)Salir"<<std::endl;
        std::string opcion;
        std::cin>>opcion;
        int seleccion=stoi(opcion);
        switch (seleccion) {
        case 1:
            core->diccionario->graficar();
            break;
        case 2:
            core->Fichas->imprimir();
            break;
        case 3:
            core->arbol->graficar();
            break;
        case 4:
            core->arbol->preorder();
            break;
        case 5:
            core->arbol->inorder();
            break;
        case 6:
            core->arbol->postorder();
            break;
        case 8:
            core->scoreboard->graficar2();
            break;
        case 9:
            core->matriz->imprimir();
            break;
        case 10:
            if(core->onlinePlayers->inicio!=NULL && core->onlinePlayers->fin!=NULL){
                core->onlinePlayers->inicio->jugador->fichas->graficar(core->onlinePlayers->inicio->jugador->dato);
                core->onlinePlayers->fin->jugador->fichas->graficar(core->onlinePlayers->fin->jugador->dato);
            }else{
                std::cout<<"No hay nadie jugando en este momento"<<std::endl;
            }
            break;
        case 11:
            continuar=false;
            break;
        default:
            std::cout<<"Por favor, ingrese el nombre del usuario del que quiere saber su punteo"<<std::endl;
            std::string usaurio;
            std::cin>>usaurio;
            graficarPuntaje(usaurio);
            break;
        }
    }
}

void Tablero::graficarPuntaje(std::string usuario){
    NodoArbol *auxusuario=core->arbol->get(usuario);
    if(auxusuario!=NULL)
        auxusuario->punteo->graficar(auxusuario->dato);
    else
        std::cout<<"Usuario no encontrado, por favor verifique el nombre y trate otra vez"<<std::endl;
}
