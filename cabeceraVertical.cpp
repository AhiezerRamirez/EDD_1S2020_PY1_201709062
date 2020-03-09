#include "cabeceraVertical.h"

CabeceraVertica::CabeceraVertica()
{
    this->primero=NULL;
    this->ultimo=NULL;
    this->size=0;
}

void CabeceraVertica::insertarArriba(std::string dato,int y){
    Nodo *n=new Nodo(dato,y);
    if(primero==NULL){
        this->primero=n;
        this->ultimo=n;
    }else{
        n->abajo=primero;
        this->primero->arriba=n;
        primero=n;
    }
    this->size++;
}

Nodo* CabeceraVertica::insertarEn(std::string dato,int y){
    Nodo *n=new Nodo(dato, y);
    if(this->primero==NULL){
        this->primero=n;
        this->ultimo=n;
    }else{
        if(y <=primero->y){
            n->abajo=primero;
            this->primero->arriba=n;
            primero=n;
        }else if(y >= ultimo->y){
            this->ultimo->abajo=n;
            n->arriba=ultimo;
            ultimo=n;
        }else{

            Nodo *temp;
            temp=this->primero;
            //Nodo<T> *anterior;
            while(temp->y < y) {
              //  anterior=temp;
                temp=temp->abajo;
            }
            temp->arriba->abajo=n;
            n->arriba=temp->arriba;
            n->abajo=temp;
            temp->arriba=n;
        }
    }
    this->size++;
    return n;
}

void CabeceraVertica::insertarAbajo(std::string dato,int y){
    Nodo *n=new Nodo(dato,y);
    if(primero=NULL){
        this->primero=n;
        this->ultimo=n;
    }else{
        this->ultimo->abajo=n;
        n->arriba=ultimo;
        ultimo=n;
    }
    this->size++;
}

void CabeceraVertica::borrarEn(int y){
    Nodo *temp=buscary(y);
    if(temp!=NULL){
        if(temp==this->primero && temp==this->ultimo){
            this->primero=NULL;
            this->ultimo=NULL;
            delete temp;
            this->size--;
        }else if(temp == this->primero){
            this->primero=primero->abajo;
            //Nodo *aux= primero->arriba;
            primero->arriba=NULL;
            delete temp;
            this->size--;
        }else if(temp==this->ultimo){
            this->ultimo=this->ultimo->arriba;
            //Nodo *aux= ultimo->abajo;
            this->ultimo->abajo=NULL;
            delete temp;
            this->size--;
        }else{
            temp->arriba->abajo=temp->abajo;
            temp->abajo->arriba=temp->arriba;
            delete temp;
            size--;
        }
    }
}



Nodo* CabeceraVertica::buscary(int y){
    Nodo *p=primero;
    while (p!=NULL) {
        if(p->y==y)
            return p;
        p=p->abajo;
    }
    return NULL;
}

Nodo* CabeceraVertica::buscar(std::string dato){
    Nodo *p=primero;
    while (p!=NULL) {
        if(p->dato==dato)
            return p;
        p=p->abajo;
    }
    return NULL;
}
