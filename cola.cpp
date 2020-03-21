#include "cola.h"
#include <fstream>
#include <thread>
#include <chrono>

Cola::Cola()
{
    this->primero=NULL;
    this->ultimo=NULL;
    this->size=0;
}

void Cola::encolar(std::string letra, int puntos){
    NodoCola* n=new NodoCola(letra,puntos);
    if(this->primero==NULL){
        this->primero=n;
        this->ultimo=n;
    }else {
        ultimo->siguiente=n;
        ultimo=n;
    }
    size++;
}
void Cola::meterradom(std::string letra, int puntos, int pos){
    NodoCola *n=new NodoCola(letra,puntos);
    if(primero==NULL){
        this->primero=n;
        this->ultimo=n;
    }
    else{
        if(pos >= this->size){
            ultimo->siguiente=n;
            ultimo=n;
        }else if (pos <=1) {
            NodoCola *temp=primero;
            primero=n;
            n->siguiente=temp;
        }else {
            NodoCola *aux=primero;
            NodoCola *anterior;
            for (int i=1;i<pos;i++) {
                anterior=aux;
                aux=aux->siguiente;
            }
            anterior->siguiente=n;
            n->siguiente=aux;
        }
    }
    this->size++;
}

void Cola::encolar(std::string letra, int puntos, int cantidad){
    Ficha *fich=new Ficha(letra,puntos,cantidad);
    NodoCola* n=new NodoCola(fich);
    if(this->primero==NULL){
        this->primero=n;
        this->ultimo=n;
    }else {
        ultimo->siguiente=n;
        ultimo=n;
    }
}

NodoCola *Cola::desencolar(){
    if(this->primero==NULL){
        return NULL;
    }else {
        NodoCola *temp=this->primero;
        if(primero==ultimo){
            this->primero=NULL;
            this->ultimo=NULL;
        }else{
            primero=primero->siguiente;
            temp->siguiente=NULL;
        }
            return temp;
    }
}



std::string Cola::toString(){
    NodoCola *aux=this->primero;
    std::string cadena="digraph G {\n node [shape=record, fontname=\"Arial\"];\n";
    cadena+="\tset1 [label = \"{";
    while (aux->siguiente!=NULL) {
        cadena+=aux->letra+" X "+std::to_string(aux->puntos)+"pts |";
        aux=aux->siguiente;
    }
    cadena+=aux->letra+" X "+std::to_string(aux->puntos) +"pts}\"];\n }";

    return cadena;
}

void Cola::imprimir(){
    std::string texto,ruta;
    ruta="/home/ahiezer/Proyecto1Edd2020/Fichas.dot";
    texto=toString();
    std::ofstream fileCitas;
    fileCitas.open(ruta.c_str());
    fileCitas<<texto;
    fileCitas.close();
    system("cd /home/ahiezer/Proyecto1Edd2020/ && dot Fichas.dot -Tjpg -o Fichas.jpg");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    system("xdg-open /home/ahiezer/Proyecto1Edd2020/Fichas.jpg");
}
