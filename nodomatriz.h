#ifndef NODOMATRIZ_H
#define NODOMATRIZ_H
#include <string>

class NodoMatriz
{
public:
    std::string dato;
    std::string Gnombre;
    int x,y;
    NodoMatriz *arriba;
    NodoMatriz *abajo;
    NodoMatriz *adelante;
    NodoMatriz *atras;
    NodoMatriz(std::string dato,int x ,int y);
};

#endif // NODOMATRIZ_H
