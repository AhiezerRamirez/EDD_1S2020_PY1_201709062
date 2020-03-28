#include "listasimpleordenada.h"
#include <fstream>
#include <chrono>
#include <thread>

ListaSimpleOrdenada::ListaSimpleOrdenada()
{
    this->primero=NULL;
    this->ultimo=NULL;
}
void ListaSimpleOrdenada::insertar(std::string nombre, int punteo){
    NodoPunteo *n=new NodoPunteo(nombre,punteo);
    if(primero==NULL){
        this->primero=n;
        this->ultimo=n;
    }else if(punteo==ultimo->punteo || punteo == primero->punteo)
            ;
    else{
        if(punteo > ultimo->punteo){
            ultimo->siguiente=n;
            ultimo=n;
        }else if (punteo < primero->punteo) {
            NodoPunteo *temp=primero;
            primero=n;
            n->siguiente=temp;
        }else {
            NodoPunteo *aux=primero;
            NodoPunteo *anterior;
            while (aux->punteo < punteo) {
                anterior=aux;
                aux=aux->siguiente;
            }
            anterior->siguiente=n;
            n->siguiente=aux;
        }
    }
}

std::string ListaSimpleOrdenada::toString(){
    NodoPunteo *temp=primero;
        std::string cadena;
        cadena="digraph G {node [shape = square]; \n graph [rankdir=LR]; \n";
        while (temp->siguiente!=NULL) {
            cadena+="\"["+std::to_string(temp->punteo)+"]\" ->";
            temp=temp->siguiente;
        }
        cadena+="\"["+std::to_string(temp->punteo)+"]\"}";
        return cadena;
}

void ListaSimpleOrdenada::graficar(){
    std::string texto,ruta;
    ruta="/home/ahiezer/Proyecto1Edd2020/Punteos.dot";
    texto=toString();
    std::ofstream fileCitas;
    fileCitas.open(ruta.c_str());
    fileCitas<<texto;
    fileCitas.close();
    system("cd /home/ahiezer/Proyecto1Edd2020/ && dot Punteos.dot -Tjpg -o Punteos.jpg");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    system("xdg-open /home/ahiezer/Proyecto1Edd2020/Punteos.jpg");
}

std::string ListaSimpleOrdenada::toString2(){
    NodoPunteo *temp=primero;
    std::string cadena;
    cadena="digraph G {node [shape = square]; \n graph [rankdir=LR]; \n";
    while (temp->siguiente!=NULL) {
        cadena+="\"["+temp->nombre+": "+std::to_string(temp->punteo)+"]\" ->";
        temp=temp->siguiente;
    }
    cadena+="\"["+temp->nombre+": "+std::to_string(temp->punteo)+"]\"}";
    return cadena;
}

void ListaSimpleOrdenada::graficar2(){
    std::string texto,ruta;
    ruta="/home/ahiezer/Proyecto1Edd2020/Scoreboard.dot";
    texto=toString2();
    std::ofstream fileCitas;
    fileCitas.open(ruta.c_str());
    fileCitas<<texto;
    fileCitas.close();
    system("cd /home/ahiezer/Proyecto1Edd2020/ && dot Scoreboard.dot -Tjpg -o Scoreboard.jpg");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    system("xdg-open /home/ahiezer/Proyecto1Edd2020/Scoreboard.jpg");
}
