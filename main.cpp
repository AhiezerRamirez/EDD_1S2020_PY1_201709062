#include <iostream>
#include <algorithm>
#include "json.hpp"
#include "core.h"
#include "matriz.h"
#include "arbolbinario.h"
#include "tablero.h"

using namespace std;
using json = nlohmann::json;

void leerJson(Core *cor,int *tam);
void ingresarJugadores(Core *cor);
void insertarjugadores2(Core *cor){

        std::cout<<"Ingresar nombre del usuario"<<std::endl;
        string nombres[]={"Ahiezer","Silvia","Abraham","Nelson","Rebeca"};
        bool breaker;
        for(string nombre:nombres){
            breaker=cor->arbol->insertar(nombre);
        }

        if(breaker==true)
            std::cout<<"todo bien chilero"<<endl;
        else
        cout<<"Intene otra vez"<<endl;

}

int main()
{
    int tama=0;
    int *taman=&tama;
    Core *core=new Core();
    Tablero *tablero=new Tablero(core);
    while (true) {
        //system("clear");
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
            leerJson(core,taman);
            core->llenarColaFichas();
            break;
        case 2:
            //core->meterfichasPruba();
            //insertarjugadores2(core);
            ingresarJugadores(core);
            break;
        case 3:
            tablero->escojerJugadores();
            tablero->prepararTablero(taman);
            tablero->dibujaTablero();
            break;
        case 4:
            tablero->mostrarReportes();
            break;
        case 5:
            exit(EXIT_SUCCESS);
            break;
        default:
            std::cout<<"Opcion incorrecta, eliga una opcion correcta"<<std::endl;
            std::cout<<"1)Continuar. 2)Salir"<<std::endl;
            std::string opcion;
            std::cin;
            switch (stoi(opcion)) {
            case 1:
                break;
            case 2:
                exit(EXIT_SUCCESS);
                break;
            }
            break;
        }
    }
    cout << "Hello World!" << endl;
    return 0;
}
void ingresarJugadores(Core *cor){
    while (true) {
        std::cout<<"Ingresar nombre del usuario"<<std::endl;
        string nombre;
        cin>>nombre;
        bool breaker=cor->arbol->insertar(nombre);
        if(breaker==true)
            break;
        else
        cout<<"Intene otra vez"<<endl;
    }
}

void leerJson(Core *cor,int *tam){
    while (true) {
        std::cout<<"Por favor, ingrese la ruta de ubicacion"<<std::endl;
        std::cout<<"de su archivo de configuarcion"<<std::endl;
        string ruta;
        std::cin>>ruta;
        std::ifstream i(ruta);
        if(i.is_open()){
            json j3;
            i >> j3;
            for(unsigned int x = 0; x < j3.at("diccionario").size(); x++)
                {
                    std::string palabra=j3.at("diccionario")[x].at("palabra");
                    for_each(palabra.begin(), palabra.end(), [](char& in){ in = ::toupper(in); });
                    cor->diccionario->insertar((palabra));
                    //cout << "Palabra: " << j3.at("diccionario")[x].at("palabra") << endl;
                }
            *tam=j3.at("dimension").get<int>();
            //std::cout<<j3.at("dimension").get<int>()<<std::endl;

            for(unsigned int x = 0; x < j3.at("casillas").at("dobles").size(); x++){
                //cout << "Casilla Doble: [" << j3.at("casillas").at("dobles")[x].at("x") << "," << j3.at("casillas").at("dobles")[x].at("y") << "]" << endl;
                cor->casillasEspeciales->insertar("doble",j3.at("casillas").at("dobles")[x].at("x") , j3.at("casillas").at("dobles")[x].at("y") );
                cor->casDobles->insertar(to_string(j3.at("casillas").at("dobles")[x].at("x"))+to_string(j3.at("casillas").at("dobles")[x].at("y")),1);
            }

            for(unsigned int x = 0; x < j3.at("casillas").at("triples").size(); x++){
                //cout << "Casilla triples: [" << j3.at("casillas").at("triples")[x].at("x") << "," << j3.at("casillas").at("triples")[x].at("y") << "]" << endl;
                cor->casillasEspeciales->insertar("triple",j3.at("casillas").at("triples")[x].at("x") , j3.at("casillas").at("triples")[x].at("y") );
                cor->casTriples->insertar(to_string(j3.at("casillas").at("triples")[x].at("x"))+to_string(j3.at("casillas").at("triples")[x].at("y")),1);
            }

            std::cout<<"Configuracion acceptada.\n"<<std::endl;

            break;
        }else{
            std::cout<<"Error al leer el archivo, verifique su ruta\n"<<std::endl;
        }
    }
}
