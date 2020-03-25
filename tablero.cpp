#include "tablero.h"

Tablero::Tablero(Core *core)
{
    this->core=core;
}

void Tablero::escojerJugadores(){
    while (true) {
        std::cout<<"Escoja al jugador 1"<<std::endl;
        std::cout<<"Escriba el nombre dell jugador 1"<<std::endl;
        std::string player;
        std::cin>>player;
        NodoArbol *jugador1=core->arbol->get(player);
        std::cout<<"Escoja al jugador 2"<<std::endl;
        std::cout<<"Escriba el nombre dell jugador 2"<<std::endl;
        std::cin>>player;
        NodoArbol *jugador2=core->arbol->get(player);
        if(jugador1!=NULL && jugador2!=NULL){
            for (int var = 0; var < 7; ++var) {
                NodoCola *ficha1= core->Fichas->desencolar();
                std::cout<<ficha1->letra+" " +std::to_string(ficha1->puntos)<<std::endl;
                jugador1->fichas->insertar(ficha1->letra,ficha1->puntos);
            }
            for (int var = 0; var < 7; ++var) {
                NodoCola *ficha1= core->Fichas->desencolar();
                std::cout<<ficha1->letra+" "+ std::to_string(ficha1->puntos)<<std::endl;
                jugador1->fichas->insertar(ficha1->letra,ficha1->puntos);
            }
            break;
        }else{
            std::cout<<"Jugadores incorrectos"<<std::endl;
            break;
        }
    }
}
