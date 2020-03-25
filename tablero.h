#ifndef TABLERO_H
#define TABLERO_H
#include "core.h"

class Tablero
{
public:
    Core *core;
    Tablero(Core *core);
    void escojerJugadores();
    void dibujaTablero();
};

#endif // TABLERO_H
