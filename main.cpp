#include <iostream>
#include "matriz.h"

using namespace std;

int main()
{
    Matriz matrix;
    matrix.insertar("Martes",2,"14:30",14,"Cardiologo");
    matrix.insertar("Jueves",4,"10:30",10,"Patologo");
    matrix.insertar("Viernes",5,"20:30",20,"Oftafmologo");
    matrix.insertar("Martes",2,"15:30",15,"Cardiologo");
    matrix.insertar("Lunes",1,"06:30",6,"Ginecologo");
    matrix.insertar("Jueves",4,"14:30",14,"Urologo");
    matrix.insertar("Martes",2,"11:30",11,"Patologo");
    matrix.insertar("Domingo",0,"1:30",1,"Muertologo");
    matrix.imprimir();
    std::cout<<matrix.cabeceravertical->primero->abajo->abajo->abajo->abajo->listahorizonta->size;
    cout << "Hello World!" << endl;
    return 0;
}
