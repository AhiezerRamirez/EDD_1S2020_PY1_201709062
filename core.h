#ifndef CORE_H
#define CORE_H
#include "listadoblecircular.h"
#include "listasimple.h"

class Core
{
public:
    ListaDobleCircular *diccionario;
    ListaSimple *casillasEspeciales;
    Core();
};

#endif // CORE_H
