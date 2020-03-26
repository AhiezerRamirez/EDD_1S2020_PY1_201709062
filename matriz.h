#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>
#include <string>
#include <fstream>
#include "cabecerahorizontal.h"
#include "cabeceraVertical.h"

//template<typename M>


//template<typename M,typename T>
class Matriz
{
public:
    CabeceraHorizontal *cabecerasHorizontal;
    CabeceraVertica *cabeceravertical;
    int size;
    Matriz(int size);
    void insertar(std::string dia,int x,std::string hora, int y, std::string actividad,std::string tipo);
    void imprimir();
    void borrar(std::string dia,int x,std::string hora, int y);
    std::string mostrarMatriz();
};

#endif // MATRIZ_H
