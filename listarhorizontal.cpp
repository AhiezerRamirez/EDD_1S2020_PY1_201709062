#include "listarhorizontal.h"

ListarHorizontal::ListarHorizontal()
{
    this->primero=NULL;
    this->ultimo=NULL;
    this->size=0;
}

void ListarHorizontal::insertar(NodoMatriz *node, int x){
    if(this->primero==NULL){
        this->primero=node;
        this->ultimo=node;
    }else{
        if(x <= primero->x){
            node->adelante=primero;
            primero->atras=node;
            primero=node;
        }else if(x > ultimo->x){
            ultimo->adelante=node;
            node->atras=ultimo;
            ultimo=node;
        }else{
            NodoMatriz *temp=this->primero;
            while (temp->x < x) {
                temp=temp->adelante;
            }
            temp->atras->adelante=node;
            node->atras=temp->atras;
            node->adelante=temp;
            temp->atras=node;
        }
    }
}

NodoMatriz* ListarHorizontal::buscar(std::string dato){
    NodoMatriz *temp=this->primero;
    while (temp!=NULL) {
        if(temp->dato==dato)
            return temp;
        temp=temp->adelante;
    }
    return NULL;
}
