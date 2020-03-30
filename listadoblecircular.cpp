#include "listadoblecircular.h"
#include <fstream>
#include <chrono>
#include <thread>


ListaDobleCircular::ListaDobleCircular()
{
    this->primero=NULL;
    this->ultimo=NULL;
}

void ListaDobleCircular::insertar(std::string dato){
    NodoCircular *n=new NodoCircular(dato);
     if(primero==NULL){
         primero=n;
         ultimo=n;
         primero->anterior=ultimo;
         ultimo->siguiente=primero;
     }else{
         primero->anterior=n;
         n->siguiente=primero;
         primero=n;
         primero->anterior=ultimo;
         ultimo->siguiente=primero;
     }
     this->size++;
}

std::string ListaDobleCircular::mostrarDiccionario(){
    std::string cadena="";
    NodoCircular *aux=this->primero;
    while (aux!=ultimo) {
        cadena+=aux->palabra+"\n";
        aux=aux->siguiente;
    }
    cadena+=aux->palabra+"\n";
    return cadena;
}

std::string ListaDobleCircular::toString(){
    NodoCircular *aux=this->primero;
    std::string cadena="digraph G {\n node [shape = square]; \n graph [rankdir=LR];\n";
    while (aux!=ultimo) {
        cadena+=aux->palabra+" -> "+aux->siguiente->palabra +"[ dir=both];\n";
        aux=aux->siguiente;
    }
    cadena+=aux->palabra+" -> "+aux->siguiente->palabra +"[ dir=both];\n }";

    return cadena;
}
void ListaDobleCircular::graficar(){
    std::string texto,ruta;
        ruta="/home/ahiezer/Proyecto1Edd2020/Diccionario.dot";
        texto=toString();
        std::ofstream fileCitas;
        fileCitas.open(ruta.c_str());
        fileCitas<<texto;
        fileCitas.close();
        system("cd /home/ahiezer/Proyecto1Edd2020/ && dot Diccionario.dot -Tjpg -o Diccionario.jpg");
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        system("xdg-open /home/ahiezer/Proyecto1Edd2020/Diccionario.jpg");
}

bool ListaDobleCircular::contains(std::string buscar){
    NodoCircular *aux=this->primero;
    while (aux!=ultimo) {
        if(aux->palabra==buscar)
            return true;
        aux=aux->siguiente;
    }
    return false;
}
