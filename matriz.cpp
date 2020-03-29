#include "matriz.h"
#include <iostream>
#include <chrono>
#include <thread>

Matriz::Matriz(int size)
{
    this->size=size;
    this->cabecerasHorizontal=new CabeceraHorizontal();
    this->cabeceravertical=new CabeceraVertica();

}

void Matriz::insertar(std::string dia, int x, std::string hora, int y, std::string actividad,std::string tipo,int puntos){
    NodoH *C=this->cabecerasHorizontal->buscar(dia);
    Nodo *F=this->cabeceravertical->buscar(hora);
    NodoMatriz *n=new NodoMatriz(actividad,x,y,tipo,puntos);

    if(F==NULL && C==NULL){
        C=this->cabecerasHorizontal->insertarEn(dia,x);
        F=this->cabeceravertical->insertarEn(hora,y);
        F->listahorizonta->insertar(n,x);
        C->listavertica->insertar(n,y);
    }else if(F==NULL && C!=NULL){
        F=this->cabeceravertical->insertarEn(hora,y);
        F->listahorizonta->insertar(n,x);
        C->listavertica->insertar(n,y);
    }else if(F!=NULL && C==NULL){
        C=this->cabecerasHorizontal->insertarEn(dia,x);
        F->listahorizonta->insertar(n,x);
        C->listavertica->insertar(n,y);
    }else{
        F->listahorizonta->insertar(n,x);
        C->listavertica->insertar(n,y);
    }
}

void Matriz::borrar(std::string dia,int x, std::string hora, int y){
    NodoH *C=this->cabecerasHorizontal->buscarx(x);
    Nodo *F=this->cabeceravertical->buscary(y);

    if(C!=NULL && F!=NULL){
        C->listavertica->borrar(x,y);
        F->listahorizonta->borrar(x,y);
    }

    if(C->listavertica->primero==NULL){
        this->cabecerasHorizontal->borrar(x);
    }

    if(F->listahorizonta->primero==NULL){
        this->cabeceravertical->borrarEn(y);
    }
}

void Matriz::imprimir(){
    std::string ruta;
    ruta="/home/ahiezer/Proyecto1Edd2020/matriz.dot";
    std::ofstream filematriz;
    filematriz.open(ruta.c_str());
    filematriz<<"digraph { \n rankdir = TB; \n node [shape=rectangle, height=0.5, width=0.5]; \n graph[ nodesep = 0.5];\n";
    //------------------------Declaracion de los nodos cabecera y nodos matriz
    NodoH *temph=this->cabecerasHorizontal->primero;
    while (temph!=NULL) {
        filematriz<<temph->Gnombre+"[label=\""+temph->dato+"\"];\n";
        temph=temph->adelante;
    }
    filematriz<<"\n";
    Nodo *tempv=this->cabeceravertical->primero;
    while (tempv!=NULL) {
        filematriz<<tempv->Gnombre+" [label=\""+tempv->dato+"\"];\n";
        tempv=tempv->abajo;
    }
    filematriz<<"\n";
    temph=this->cabecerasHorizontal->primero;
    while (temph!=NULL){
        NodoMatriz *aux=temph->listavertica->primero;
        while (aux!=NULL) {
            if(aux->tipo=="triple"){
                filematriz<<aux->Gnombre+"[label=\""+aux->dato+"\" style=filled color=lightblue];\n";
            }else if (aux->tipo=="doble") {
                filematriz<<aux->Gnombre+"[label=\""+aux->dato+"\" style=filled color=chartreuse];\n";
            } else {
                filematriz<<aux->Gnombre+"[label=\""+aux->dato+"\"];\n";
            }
            aux=aux->abajo;
        }
        temph=temph->adelante;
    }
    filematriz<<"\n";
    /*tempv=this->cabeceravertical->primero;
    while (tempv!=NULL) {
        NodoMatriz *aux=tempv->listahorizonta->primero;
        while (aux!=NULL) {
            filematriz<<aux->Gnombre+"[label=\""+aux->dato+"\"];\n";
            aux=aux->adelante;
        }
        tempv=tempv->abajo;
    }*/
    //-------------------------Fin de los nodos cabecera y nodos matriz

    //-------------------------Enlaces entre Nodos cabecera y nodos matriz por igual
    temph=this->cabecerasHorizontal->primero;
    filematriz<<"root -> "+temph->Gnombre+"[ dir=both];\n";
    while (temph->adelante!=NULL) {
        filematriz<<temph->Gnombre+" -> "+temph->adelante->Gnombre+"[ dir=both];\n";
        temph=temph->adelante;
    }

    tempv=this->cabeceravertical->primero;
    filematriz<<"root -> "+tempv->Gnombre+"[ dir=both];\n";
    while (tempv->abajo!=NULL) {
        filematriz<<tempv->Gnombre+" -> "+tempv->abajo->Gnombre+" [ dir=both];\n";
        tempv=tempv->abajo;
    }
    filematriz<<"\n";
    temph=this->cabecerasHorizontal->primero;
    while (temph!=NULL){
        NodoMatriz *aux=temph->listavertica->primero;
            filematriz<<temph->Gnombre+" -> "+aux->Gnombre+" [ dir=both];\n";
            while (aux->abajo!=NULL) {
                filematriz<<aux->Gnombre+" -> "+aux->abajo->Gnombre+" [ dir=both];\n";
                aux=aux->abajo;
          //  }
        }

        temph=temph->adelante;
    }
    filematriz<<"\n";
    tempv=this->cabeceravertical->primero;
    while (tempv!=NULL) {
        NodoMatriz *aux=tempv->listahorizonta->primero;
            filematriz<<tempv->Gnombre+" -> "+aux->Gnombre+" [constraint=false, dir=both];\n";
            while (aux->adelante!=NULL) {
                filematriz<<aux->Gnombre+" -> "+aux->adelante->Gnombre+" [ dir=both];\n";
                aux=aux->adelante;
            }
        //}

        tempv=tempv->abajo;
    }
    filematriz<<"\n";
//------------------------Fin enlaces de nodo cabecera y de mas

    temph=this->cabecerasHorizontal->primero;
    filematriz<<"{ rank=same;root;";
    while (temph!=NULL) {
        filematriz<<temph->Gnombre+" ;";
        temph=temph->adelante;
    }
    filematriz<<"}";
    filematriz<<"\n";
    tempv=this->cabeceravertical->primero;
    while (tempv!=NULL) {
        filematriz<<"{rank= same;"+tempv->Gnombre+";";
        NodoMatriz *aux=tempv->listahorizonta->primero;
        while (aux!=NULL) {
            filematriz<<aux->Gnombre+";";
            aux=aux->adelante;
        }
        filematriz<<"}\n";
        tempv=tempv->abajo;
    }
    filematriz<<"}";
    filematriz.close();
    system("cd /home/ahiezer/Proyecto1Edd2020/ && dot matriz.dot -Tjpg -o matriz.jpg");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    system("xdg-open /home/ahiezer/Proyecto1Edd2020/matriz.jpg");
}

std::string Matriz::mostrarMatriz(){
    std::string auxmatriz[this->size+1][this->size+1];
    NodoH *temp=this->cabecerasHorizontal->primero;
    while (temp!=NULL) {
        auxmatriz[temp->x+1][0]=temp->dato;
        NodoMatriz *aux=temp->listavertica->primero;
        while (aux!=NULL) {
            auxmatriz[aux->x+1][aux->y+1]=aux->dato;
            aux=aux->abajo;
        }
        temp=temp->adelante;
    }
    Nodo *auxtemp=this->cabeceravertical->primero;
    while (auxtemp!=NULL) {
        auxmatriz[0][auxtemp->y+1]=auxtemp->dato;
        auxtemp=auxtemp->abajo;
    }

    std::string cadena="";
    for (int var = 0; var < this->size; ++var) {
        for (int j = 0; j < this->size; ++j) {
            if(auxmatriz[j][var]!=""){
                cadena+=auxmatriz[j][var];
            }
            else{
                cadena+=" ";
            }
        }
        cadena+="\n";
    }
    return cadena;
}

std::string Matriz::buscar(int x, int y){
    Nodo *vtemp=this->cabeceravertical->primero;
    while (vtemp!=NULL) {
        if(vtemp->y==y){
            NodoMatriz *aux=vtemp->listahorizonta->primero;
            while (aux!=NULL) {
                if(aux->x==x&&aux->y==y){
                    return aux->dato;
                }
                aux=aux->adelante;
            }
        }
        vtemp=vtemp->abajo;
    }
    return "";
}

int Matriz::sumar(int x, int y){
    Nodo *vtemp=this->cabeceravertical->primero;
    while (vtemp!=NULL) {
        if(vtemp->y==y){
            NodoMatriz *aux=vtemp->listahorizonta->primero;
            while (aux!=NULL) {
                if(aux->x==x&&aux->y==y){
                    if(aux->tipo=="triple"){
                        return (3*aux->puntos);
                    }else if(aux->tipo=="doble"){
                        return (2*aux->puntos);
                    }else{
                        return aux->puntos;
                    }
                }
                aux=aux->adelante;
            }
        }
        vtemp=vtemp->abajo;
    }
    return 0;
}

bool Matriz::existe(int x, int y){
    Nodo *vtemp=this->cabeceravertical->primero;
    while (vtemp!=NULL) {
        if(vtemp->y==y){
            NodoMatriz *aux=vtemp->listahorizonta->primero;
            while (aux!=NULL) {
                if(aux->x==x&&aux->y==y){
                    return true;
                }
                aux=aux->adelante;
            }
        }
        vtemp=vtemp->abajo;
    }
    return false;
}
