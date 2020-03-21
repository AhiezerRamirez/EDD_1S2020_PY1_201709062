#include "listadoble.h"
#include <fstream>
#include <chrono>
#include <thread>

ListaDoble::ListaDoble()
{
    this->primero=NULL;
    this->ultimo=NULL;
    this->size=0;
}

void ListaDoble::insertar(std::string letra, int puntos){
    NodoFicha *n=new NodoFicha(letra,puntos);
    if(this->primero==NULL){
        this->primero=n;
        this->ultimo=n;
    }else{
        n->siguiente=primero;
        primero->atras=n;
        primero=n;

    }
    this->size++;
}
NodoFicha* ListaDoble::borrar(int pos){
    if(this->primero==NULL){
        return NULL;
    }else if(primero->siguiente==NULL){
        NodoFicha *temp=primero;
        this->primero=NULL;
        this->ultimo=NULL;
        this->size--;
        return temp;
    }
    else {
        if(pos < 2){
            NodoFicha *temp=primero;
            this->primero=this->primero->siguiente;
            this->primero->atras=NULL;
            this->size--;
            temp->siguiente=NULL;
            return temp;
        }else if (pos >=size) {
            NodoFicha *temp=ultimo;
            this->ultimo=this->ultimo->atras;
            this->ultimo->siguiente=NULL;
            this->size--;
            temp->atras=NULL;
            return temp;
        }else{
            NodoFicha *cur=primero;
            for (int var = 0; var < pos; ++var) {
                cur=cur->siguiente;
            }
            cur->atras->siguiente=cur->siguiente;
            cur->siguiente->atras=cur->atras;
            this->size++;
            return cur;
        }
    }
}

std::string ListaDoble::toString(){
    NodoFicha *temp=this->primero;
    std::string cadena="digraph G {node [shape = square]; \n graph [rankdir=LR]; \n";
    int contado=0;
    while (temp!=NULL) {
        cadena+=std::to_string(contado)+"[lable= "+temp->letra+"]\n";
        contado++;
        temp=temp->siguiente;
    }
    temp=primero;
    contado=0;
    while (temp->siguiente!=NULL) {
        cadena+=std::to_string(contado)+" -> ";
        contado++;
        temp=temp->siguiente;
    }
}

void ListaDoble::graficar(std::string usuario){
    std::string texto,ruta;
        ruta="/home/ahiezer/Proyecto1Edd2020/Ltrs_"+usuario+".dot";
        texto=toString();
        std::ofstream fileCitas;
        fileCitas.open(ruta.c_str());
        fileCitas<<texto;
        fileCitas.close();
        system("cd /home/ahiezer/Proyecto1Edd2020/ && dot Ltrs_"+usuario+".dot -Tjpg -o Ltrs_"+usuario+".jpg");
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        system("xdg-open /home/ahiezer/Proyecto1Edd2020/Ltrs_"+usuario+".jpg");
}
