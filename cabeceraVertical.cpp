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
    Nodo *n =new Nodo(dato, y);
    if(this->primero==NULL){
        insertarArriba(dato,y);
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

void CabeceraVertica::borrarArriba(){
    if(this->primero->abajo==NULL){
        this->primero=NULL;
        this->ultimo=NULL;
        this->size--;
    }else if(this->primero!=NULL){
        primero=primero->abajo;
        delete primero->arriba;
        primero->arriba=NULL;
        size--;
    }
}

void CabeceraVertica::borrarEn(int pos){
    if(pos<1 || pos > size){
        return;
    }else{
        if(pos==1)
            borrarArriba();
        else if(pos==size)
            borrarAbajo();
        else if(this->primero!=NULL){
            Nodo *temp=primero;
            for (int var = 0; var < pos; ++var) {
                temp=temp->abajo;
            }
            temp->arriba->abajo=temp->abajo;
            temp->abajo->arriba=temp->arriba;
            delete temp;
            size--;
        }
    }
}

void CabeceraVertica::borrarAbajo(){
    if(this->primero->abajo==NULL){
        primero=NULL;
        ultimo=NULL;
        size--;
    }else if(this->primero!=NULL){
        ultimo=ultimo->arriba;
        delete ultimo->abajo;
        ultimo->abajo=NULL;
        size--;
    }
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
