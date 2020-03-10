#include "listasimple.h"

ListaSimple::ListaSimple()
{
    this->primero=NULL;
}

void ListaSimple::insertar(std::string tipo, int x, int y){
    NodoListaSimple *n=new NodoListaSimple(tipo,x,y);
    if(primero==NULL){
        primero=n;
    }else{
        n->siguiente=primero;
        primero=n;
    }
}

NodoListaSimple* ListaSimple::buscar(int x , int y){
    NodoListaSimple *aux=this->primero;
    while (aux!=NULL) {
        if(aux->x==x && aux->y==y)
            return aux;
        aux=aux->siguiente;
    }
    return NULL;
}

void ListaSimple::toString(){
    NodoListaSimple *aux=this->primero;
    while (aux!=NULL) {
        std::cout<<aux->tipo+" "+std::to_string(aux->x)+","+std::to_string(aux->y)<<std::endl;
        aux=aux->siguiente;
    }
}
