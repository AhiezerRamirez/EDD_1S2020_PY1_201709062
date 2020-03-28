#include "nodomatriz.h"

NodoMatriz::NodoMatriz(std::string dato,int x ,int y,std::string tipo,int puntos)
{
    this->dato=dato;
    this->x=x;
    this->y=y;
    this->arriba=NULL;
    this->abajo=NULL;
    this->adelante=NULL;
    this->atras=NULL;
    this->Gnombre="nodo"+std::to_string(x)+std::to_string(0)+std::to_string(y);
    this->tipo=tipo;
    this->puntos=puntos;
}
