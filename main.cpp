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
    //core->crearMatriz(15);
    /*core->matriz->imprimir();
    //core->llenarColaFichas();
    //core->Fichas->imprimir();
    core->arbol->insertar("Rudy");
    core->arbol->insertar("pedro");
    core->arbol->insertar("Anibal");
    core->arbol->insertar("Andrea");
    core->arbol->insertar("Joselinne");
    //core->arbol->graficar();
    core->arbol->preorder();
    core->arbol->inorder();
    core->arbol->postorder();*/
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
            break;
        case 2:
            //core->llenarColaFichas();
            core->meterfichasPruba();
            insertarjugadores2(core);
            //ingresarJugadores(core);
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
        //string ruta;
        //std::cin>>ruta;
        std::ifstream i("/home/ahiezer/Proyecto1Edd2020/example.json");
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
