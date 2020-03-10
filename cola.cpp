#include "cola.h"

Cola::Cola()
{
    this->primero=NULL;
    this->ultimo=NULL;
}

void Cola::encolar(std::string letra, int puntos){
    NodoCola* n=new NodoCola(letra,puntos);
    if(this->primero==NULL){
        this->primero=n;
        this->ultimo=n;
    }else {
        ultimo->siguiente=n;
        ultimo=n;
    }
}

NodoCola *Cola::desencolar(){
    if(this->primero==NULL){
        return NULL;
    }else {
        NodoCola *temp=this->primero;
        if(primero==ultimo){
            this->primero=NULL;
            this->ultimo=NULL;
        }else{
            primero=primero->siguiente;
            temp->siguiente=NULL;
        }
            return temp;
    }
}
