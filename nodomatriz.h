#ifndef NODOMATRIZ_H
#define NODOMATRIZ_H
#include <string>

class NodoMatriz
{
public:
    std::string dato,tipo;
    std::string Gnombre;
    int x,y;
    NodoMatriz *arriba;
    NodoMatriz *abajo;
    NodoMatriz *adelante;
    NodoMatriz *atras;
    NodoMatriz(std::string dato,int x ,int y,std::string);
};

#endif // NODOMATRIZ_H
