#ifndef LISTAJUGADORESLINEA_H
#define LISTAJUGADORESLINEA_H
#include "arbolbinario.h"

class NodoJugadoresLinea
{
public:
    NodoArbol *jugador;
    NodoJugadoresLinea *siguiente;
    NodoJugadoresLinea(NodoArbol *jugador) {
        this->jugador=jugador;
    }
};

class ListaJugadoresLinea
{
public:
    NodoJugadoresLinea *inicio,*fin;
    ListaJugadoresLinea();
    void ingrear(NodoArbol *jugador);
    std::string mostrarJugadores();
    void vaciar();
};

#endif // LISTAJUGADORESLINEA_H
