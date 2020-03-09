#include <iostream>
#include "json.hpp"
#include "matriz.h"
#include "arbolbinario.h"

using namespace std;
using json = nlohmann::json;

void leerJson();

int main()
{

    while (true) {
        std::cout<<"\n\n";
        std::cout<<"-----------------------------------------"<<std::endl;
        std::cout<<"        1)Lectura de Archivo             "<<std::endl;
        std::cout<<"        2)Ingresar Jugadores             "<<std::endl;
        std::cout<<"        3)Juego                          "<<std::endl;
        std::cout<<"        4)Generar Reportes               "<<std::endl;
        std::cout<<"        5)Salir                          "<<std::endl;
        std::cout<<"-----------------------------------------"<<std::endl;
        std::cout<<"Escoja una opcion: ";
        int opcion;
        std::cin>>opcion;
        switch (opcion) {
        case 1:
            leerJson();
            break;
        case 5:
            exit(EXIT_SUCCESS);
            break;
        default:
            std::cout<<"Opcion incorrecta, eliga una opcion correcta"<<std::endl;
            break;
        }
    }
    /*Matriz matrix;
    matrix.insertar("Martes",2,"14:30",14,"Cardiologo");
    matrix.insertar("Jueves",4,"10:30",10,"Patologo");
    matrix.insertar("Viernes",5,"20:30",20,"Oftafmologo");
    matrix.insertar("Martes",2,"15:30",15,"Cardiologo");
    matrix.insertar("Lunes",1,"06:30",6,"Ginecologo");
    matrix.insertar("Jueves",4,"14:30",14,"Urologo");
    matrix.insertar("Martes",2,"11:30",11,"Patologo");
    matrix.insertar("Domingo",0,"1:30",1,"Muertologo");
    matrix.borrar("Domingo",0,"1:30",1);
    matrix.borrar("Viernes",5,"20:30",20);
    //matrix.insertar("Domingo",0,"1:30",1,"Muertologo");
    //matrix.insertar("Domingo",0,"9:00",9,"Ucologo");
    //matrix.insertar("Viernes",5,"20:30",20,"Oftafmologo");
    //matrix.insertar("Lunes",1,"7:30",7,"Ginecologo");
    matrix.imprimir();
    std::cout<<matrix.cabeceravertical->primero->abajo->abajo->abajo->abajo->listahorizonta->size;
    ArbolBinario *arbol=new ArbolBinario();
    arbol->insertar(5);
    arbol->insertar(3);
    arbol->insertar(6);
    arbol->insertar(7);
    arbol->insertar(2);
    arbol->insertar(9);
    arbol->insertar(4);
    arbol->insertar(11);
    arbol->insertar(22);
    arbol->insertar(17);
    arbol->insertar(1);
    arbol->insertar(91);
    arbol->remover(17);
    arbol->remover(7);
    arbol->remover(91);
    arbol->inorder();*/
    cout << "Hello World!" << endl;
    return 0;
}

void leerJson(){
    while (true) {
        std::cout<<"Por favor, ingrese la ruta de ubicacion"<<std::endl;
        std::cout<<"de su archivo de configuarcion"<<std::endl;
        string ruta;
        std::cin>>ruta;
        std::ifstream i(ruta);
        if(i.is_open()){
            json j3;
            i >> j3;
            for(unsigned int x = 0; x < j3.at("eBooks").size(); x++)
                {
                    cout << "Edition of the book: " << j3.at("eBooks")[x].at("edition") << endl;
                    cout << "Language of the book: " << j3.at("eBooks")[x].at("language") << endl;
                }
            std::cout<<"Configuracion acceptada.\n"<<std::endl;

            break;
        }else{
            std::cout<<"Error al leer el archivo, verifique su ruta\n"<<std::endl;
        }
    }
}
