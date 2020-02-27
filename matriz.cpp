#include "matriz.h"

Matriz::Matriz()
{
    this->cabecerasHorizontal=new CabeceraHorizontal();
    this->cabeceravertical=new CabeceraVertica();

}

void Matriz::insertar(std::string dia, int x, std::string hora, int y, std::string actividad){
    NodoH *C=this->cabecerasHorizontal->buscar(dia);
    Nodo *F=this->cabeceravertical->buscar(hora);
    NodoMatriz *n=new NodoMatriz(actividad,x,y);

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


void Matriz::imprimir(){
    std::string ruta;
    ruta="/home/ahiezer/Proyecto1Edd2020/matriz.txt";
    std::ofstream filematriz;
    filematriz.open(ruta.c_str());
    filematriz<<"digraph { \n rankdir = TB; \n node [shape=rectangle, height=0.5, width=0.5]; \n graph[ nodesep = 0.5];\n";
    //------------------------Declaracion de los nodos cabecera y nodos matriz
    NodoH *temph=this->cabecerasHorizontal->primero;
    while (temph!=NULL) {
        filematriz<<temph->Gnombre+"[label=\""+temph->dato+"\"];\n";
        temph=temph->adelante;
    }
    Nodo *tempv=this->cabeceravertical->primero;
    while (tempv!=NULL) {
        filematriz<<tempv->Gnombre+" [label=\""+tempv->dato+"\"];\n";
        tempv=tempv->abajo;
    }

    temph=this->cabecerasHorizontal->primero;
    while (temph!=NULL){
        NodoMatriz *aux=temph->listavertica->primero;
        while (aux!=NULL) {
            filematriz<<aux->Gnombre+"[label=\""+aux->dato+"\"];\n";
            aux=aux->abajo;
        }
        temph=temph->adelante;
    }

    tempv=this->cabeceravertical->primero;
    while (tempv!=NULL) {
        NodoMatriz *aux=tempv->listahorizonta->primero;
        while (aux!=NULL) {
            filematriz<<aux->Gnombre+"[label=\""+aux->dato+"\"];\n";
            aux=aux->adelante;
        }
        tempv=tempv->abajo;
    }
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

    temph=this->cabecerasHorizontal->primero;
    while (temph!=NULL){
        NodoMatriz *aux=temph->listavertica->primero;
        //if(aux->abajo==NULL){
          //  filematriz<<temph->Gnombre+" -> "+aux->Gnombre+" [ dir=both];\n";
        //}else{
            filematriz<<temph->Gnombre+" -> "+aux->Gnombre+" [ dir=both];\n";
            while (aux->abajo!=NULL) {
                filematriz<<aux->Gnombre+" -> "+aux->abajo->Gnombre+" [ dir=both];\n";
                aux=aux->abajo;
          //  }
        }

        temph=temph->adelante;
    }

    tempv=this->cabeceravertical->primero;
    while (tempv!=NULL) {
        NodoMatriz *aux=tempv->listahorizonta->primero;
        //if(aux->adelante==NULL){
           // filematriz<<tempv->Gnombre+" -> "+aux->Gnombre+" [ dir=both];\n";
            //}else{
            filematriz<<tempv->Gnombre+" -> "+aux->Gnombre+" [constraint=false, dir=both];\n";
            while (aux->adelante!=NULL) {
                filematriz<<aux->Gnombre+" -> "+aux->adelante->Gnombre+" [ dir=both];\n";
                aux=aux->adelante;
            }
        //}

        tempv=tempv->abajo;
    }
//------------------------Fin enlaces de nodo cabecera y de mas

    temph=this->cabecerasHorizontal->primero;
    filematriz<<"{ rank=same;root;";
    while (temph!=NULL) {
        filematriz<<temph->Gnombre+" ;";
        temph=temph->adelante;
    }
    filematriz<<"}";

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
}
