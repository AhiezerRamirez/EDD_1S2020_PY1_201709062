#ifndef CORE_H
#define CORE_H
#include "listadoblecircular.h"
#include "listasimple.h"
#include "cola.h"
#include "arbolbinario.h"
#include "listasimpleordenada.h"
#include "matriz.h"
#include "listadoble.h"
#include "listajugadoreslinea.h"

class Core
{
public:
    ListaDobleCircular *diccionario;
    ListaDoble *casDobles,*casTriples;
    ListaSimple *casillasEspeciales;
    Cola *Fichas;
    ArbolBinario *arbol;
    ListaSimpleOrdenada *scoreboard;
    Matriz *matriz;
    ListaJugadoresLinea *onlinePlayers;
    Core();
    void llenarColaFichas();
    void crearMatriz(int size);
};

#endif // CORE_H
