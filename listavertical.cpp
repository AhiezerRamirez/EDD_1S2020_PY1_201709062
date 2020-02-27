#include "listavertical.h"

ListaVertical::ListaVertical()
{
    this->primero=NULL;
    this->ultimo=NULL;
    this->size=0;
}

void ListaVertical::insertar(NodoMatriz *node,int y){
    if(primero==NULL){
        primero=node;
        ultimo=node;
    }else{
        if(y <= primero->y){
            node->abajo=primero;
            primero->arriba=node;
            primero=node;
        }else if(y >= ultimo->y){
            ultimo->abajo=node;
            node->arriba=ultimo;
            ultimo=node;
        }else{
            NodoMatriz* temp=this->primero;
            while (temp->y < y) {
                temp=temp->abajo;
            }
            temp->arriba->abajo=node;
            node->abajo=temp;
            node->arriba=temp->arriba;
            temp->arriba=node;

        }
    }
    this->size++;
}

NodoMatriz* ListaVertical::buscar(std::string dato){
    NodoMatriz* temp=this->primero;
    while (temp!=NULL) {
        if(temp->dato==dato)
            return temp;
        temp=temp->abajo;
    }
    return NULL;
}
