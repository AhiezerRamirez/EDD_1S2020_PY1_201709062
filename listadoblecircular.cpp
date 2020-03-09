#include "listadoblecircular.h"

ListaDobleCircular::ListaDobleCircular()
{
    this->primero=NULL;
    this->ultimo=NULL;
}

void ListaDobleCircular::insertar(std::string dato){
    Nodo *n=new Nodo(caracter,espacio);
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
void ListaDobleCircular::graficar(){

}
