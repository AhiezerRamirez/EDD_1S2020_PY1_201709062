#include "core.h"

Core::Core()
{
    this->diccionario=new ListaDobleCircular();
    this->Fichas=new Cola();
    this->arbol=new ArbolBinario();
    this->scoreboard=new ListaSimpleOrdenada();
    this->casillasEspeciales=new ListaSimple();
    this->casDobles=new ListaDoble();
    this->casTriples=new ListaDoble();
    this->onlinePlayers=new ListaJugadoresLinea();
}

void Core::llenarColaFichas(){
    Cola *cola_llenarficha=new Cola();
    cola_llenarficha->encolar("A",1,12);
    cola_llenarficha->encolar("E",1,12);
    cola_llenarficha->encolar("O",1,9);
    cola_llenarficha->encolar("I",1,6);
    cola_llenarficha->encolar("S",1,6);
    cola_llenarficha->encolar("N",1,5);
    cola_llenarficha->encolar("L",1,4);
    cola_llenarficha->encolar("R",1,5);
    cola_llenarficha->encolar("U",1,5);
    cola_llenarficha->encolar("T",1,4);
    cola_llenarficha->encolar("D",2,5);
    cola_llenarficha->encolar("G",2,2);
    cola_llenarficha->encolar("C",3,4);
    cola_llenarficha->encolar("B",3,2);
    cola_llenarficha->encolar("M",3,2);
    cola_llenarficha->encolar("P",3,2);
    cola_llenarficha->encolar("H",4,2);
    cola_llenarficha->encolar("F",4,1);
    cola_llenarficha->encolar("V",4,1);
    cola_llenarficha->encolar("Y",4,1);
    cola_llenarficha->encolar("Q",5,1);
    cola_llenarficha->encolar("J",8,1);
    cola_llenarficha->encolar("Ñ",8,1);//Falta ponerle la enne
    cola_llenarficha->encolar("X",8,1);
    cola_llenarficha->encolar("Z",10,1);
    NodoCola *temp=cola_llenarficha->desencolar();
    this->Fichas->meterradom(temp->ficha->letra,temp->ficha->puntos,1);
    temp=cola_llenarficha->desencolar();
    this->Fichas->meterradom(temp->ficha->letra,temp->ficha->puntos,1);
    while (cola_llenarficha->primero!=NULL) {
        temp=cola_llenarficha->desencolar();
        for (int var = 0; var <= temp->ficha->cantfichas; ++var) {
            int v2 = rand() % this->Fichas->size + 1;
            this->Fichas->meterradom(temp->ficha->letra,temp->ficha->puntos,v2);
        }
    }
}
void Core::meterfichasPruba(){
    this->Fichas->meterradom("A",1,1);
    this->Fichas->meterradom("S",1,2);
    this->Fichas->meterradom("M",3,1);
    this->Fichas->meterradom("A",1,1);
    this->Fichas->meterradom("R",1,2);
    this->Fichas->meterradom("H",4,3);
    this->Fichas->meterradom("O",1,2);
    this->Fichas->meterradom("L",1,5);
    this->Fichas->meterradom("A",1,5);
    this->Fichas->meterradom("V",4,3);
    this->Fichas->meterradom("A",1,1);
    this->Fichas->meterradom("O",1,2);
    this->Fichas->meterradom("L",1,5);
    this->Fichas->meterradom("G",2,1);
    this->Fichas->meterradom("U",1,4);
    this->Fichas->meterradom("H",4,3);
    this->Fichas->meterradom("O",1,2);
    this->Fichas->meterradom("L",1,5);
    this->Fichas->meterradom("A",1,5);

}
void Core::crearMatriz(int size){

    this->matriz=new Matriz(size);
}
