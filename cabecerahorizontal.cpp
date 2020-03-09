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

void CabeceraHorizontal::borrar(int x){
    NodoH *temp=buscarx(x);
    if(temp!=NULL){
        if(temp==this->primero && temp== this->ultimo){
            this->primero=NULL;
            this->ultimo=NULL;
            delete temp;
            this->size--;
        }else if(temp==primero){
            this->primero=primero->adelante;
            //NodoH *aux=this->primero->atras;
            this->primero->atras=NULL;
            delete temp;
            this->size--;
        }else if(temp==ultimo){
            this->ultimo=ultimo->atras;
            //NodoH *aux=this->ultimo->adelante;
            this->ultimo->adelante=NULL;
            delete temp;
            this->size--;
        }else{
            temp->atras->adelante=temp->adelante;
            temp->adelante->atras=temp->atras;
            delete temp;
            this->size--;
        }
    }
}

NodoH* CabeceraHorizontal::buscarx(int x){
    NodoH *temp=this->primero;
    while (temp!=NULL) {
        if(temp->x==x)
            return temp;
        temp=temp->adelante;
    }
    return NULL;
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
