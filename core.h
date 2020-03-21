#ifndef CORE_H
#define CORE_H
#include "listadoblecircular.h"
#include "listasimple.h"
#include "cola.h"
#include "arbolbinario.h"
#include "listasimpleordenada.h"
#include "matriz.h"

class Core
{
public:
    ListaDobleCircular *diccionario;
    ListaSimple *casillasEspeciales;
    Cola *Fichas;
    ArbolBinario *arbol;
    ListaSimpleOrdenada *scoreboard;
    Matriz matriz;

    Core();
    void llenarColaFichas();
};

#endif // CORE_H
