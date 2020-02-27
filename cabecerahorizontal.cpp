#include "cabecerahorizontal.h"

CabeceraHorizontal::CabeceraHorizontal()
{
    this->primero=NULL;
    this->ultimo=NULL;
    this->size=0;
}

NodoH* CabeceraHorizontal::insertarEn(std::string dato, int x){
    NodoH *n=new NodoH(dato,x);
    if(primero==NULL){
        this->primero=n;
        this->ultimo=n;
    }else{
        if(x <= primero->x){
            n->adelante=primero;
            primero->atras=n;
            primero=n;
        }else if(x >= ultimo->x){
            ultimo->adelante=n;
            n->atras=ultimo;
            ultimo=n;
        }else {
            NodoH *aux=this->primero;
            while (aux->x < x) {
                aux=aux->adelante;
            }
            aux->atras->adelante=n;
            n->atras=aux->atras;
            n->adelante=aux;
            aux->atras=n;
        }
    }
    this->size++;
    return n;
}

NodoH *CabeceraHorizontal::buscar(std::string dato){
    NodoH *temp=this->primero;
    while (temp!=NULL) {
        if(temp->dato==dato)
            return temp;
        temp=temp->adelante;
    }
    return NULL;
}
