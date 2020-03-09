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
    this->size++;
}

void ListarHorizontal::borrar(int x, int y){
    NodoMatriz* temp=buscarxy(x,y);
    if(temp!=NULL){
        if(temp==this->primero && temp==this->ultimo){
            this->primero=NULL;
            this->ultimo=NULL;
            //delete temp;
            this->size--;
        }else if (temp==this->primero) {
            this->primero=this->primero->adelante;
            //NodoMatriz *aux= this->primero->atras;
            this->primero->atras=NULL;
            //delete aux;
            this->size--;
        }else if (temp== this->ultimo) {
            this->ultimo=this->ultimo->atras;
            //NodoMatriz *aux= this->ultimo->adelante;
            this->ultimo->adelante=NULL;
            //delete aux;
            this->size--;
        }else {
            temp->atras->adelante=temp->adelante;
            temp->adelante->atras=temp->atras;
            //delete temp;
            this->size--;
        }
    }
}

NodoMatriz* ListarHorizontal::buscarxy(int x, int y){
    NodoMatriz *temp=this->primero;
    while (temp!=NULL) {
        if(temp->x==x && temp->y==y)
            return temp;
        temp=temp->adelante;
    }
    return NULL;
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
