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

void ListaVertical::borrar(int x, int y){
    NodoMatriz *aux=buscarxy(x,y);
    if(aux!=NULL){
        if(aux==this->primero && aux==this->ultimo){
            this->primero=NULL;
            this->ultimo=NULL;
            delete aux;
            this->size--;
        }else if(aux==this->primero){
            primero=primero->abajo;
            delete primero->arriba;
            primero->arriba=NULL;
            this->siz--;
        }else if(aux==this->ultimo){
            ultimo=ultimo->arriba;
            delete ultimo->abajo;
            ultimo->abajo=NULL;
            this->size--;
        }else{
            aux->arriba->abajo=aux->abajo;
            aux->abajo->arriba=aux->arriba;
            delete aux;
            size--;
        }
    }
}

NodoMatriz* ListaVertical::buscarxy(int x, int y){
    NodoMatriz *temp=this->primero;
    while (temp!=NULL) {
        if(temp->x==x && temp->y=y)
            return temp;
        temp=temp->abajo;
    }
    return NULL;
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
