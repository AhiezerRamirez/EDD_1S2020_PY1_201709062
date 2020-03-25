#include "listajugadoreslinea.h"

ListaJugadoresLinea::ListaJugadoresLinea()
{
    this->inicio=NULL;
    this->fin=NULL;
}

void ListaJugadoresLinea::ingrear(NodoArbol *jugador){
    NodoJugadoresLinea *n=new NodoJugadoresLinea(jugador);
    if(this->inicio==NULL){
        n->siguiente=n;
        this->inicio=n;
        this->fin=n;
    }else{
        this->fin->siguiente=n;
        n->siguiente=inicio;
        this->fin=n;
    }
}

std::string ListaJugadoresLinea::mostrarJugadores(){
    return "Jugando: "+this->inicio->jugador->dato +" Y "+this->fin->jugador->dato+"\n";
}
