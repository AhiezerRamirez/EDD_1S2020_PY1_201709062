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
    void insertar(std::string dia,int x,std::string hora, int y, std::string actividad,std::string tipo,int puntos);
    void imprimir();
    void borrar(std::string dia,int x,std::string hora, int y);
    std::string mostrarMatriz();
    std::string buscar(int x, int y);
    int sumar(int x, int y);
    bool existe(int x, int y);
};

#endif // MATRIZ_H
