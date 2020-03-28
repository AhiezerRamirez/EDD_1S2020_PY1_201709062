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
    return "Jugando:\n"+this->inicio->jugador->dato +": "+this->inicio->jugador->fichas->mostrarFichas()+"  punteo -> "+std::to_string(this->inicio->jugador->puntos)+"\n"
            +this->fin->jugador->dato+": "+this->fin->jugador->fichas->mostrarFichas()+"  punteo -> "+std::to_string(this->fin->jugador->puntos)+"\n";
}

void ListaJugadoresLinea::vaciar(){
    this->inicio=NULL;
    this->fin=NULL;
}
